#include "imagemessagelistmodel.h"

ImageMessageListModel::ImageMessageListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_roleNames.insert(RoleImageID, "msg_image_id");
    m_roleNames.insert(RoleImage, "msg_image");
    m_roleNames.insert(RoleText, "msg_text");

    imageMsgManager_ = ImageMsgManager::GetInstance();

//    ImageMessage ele;
//    ele.col_index_ = 0;
//    m_display_list.append(&(ele));

}

void ImageMessageListModel::setImgIdList(QList<int> imgIdList)
{
    m_imgId_list = imgIdList;
}

void ImageMessageListModel::setColIndex(int colIndex)
{
    colIndex_ = colIndex;
}

int ImageMessageListModel::rowCount(const QModelIndex &parent) const
{
    return m_display_list.size();
}

QVariant ImageMessageListModel::data(const QModelIndex &index, int role) const
{
    ImageMessage* ele = m_display_list.at(index.row());
    QVariant var;
    switch (role) {
    case RoleImageID:
        var = ele->img_id_;
        break;
    case RoleImage:
        var = ele->img_url_;
        break;
    case RoleText:
        var = ele->text_;
        break;
    default:
        break;
    }
    return var;
}

QHash<int, QByteArray> ImageMessageListModel::roleNames() const
{
    return m_roleNames;
}

// -1说明未下载到图片，0说明col0已更新，1说明该col1更新
int ImageMessageListModel::update()
{
    ImageMessage* ele;
    if (colIndex_ == 0)
    {
        int tag_update = imageMsgManager_->update();
        if(tag_update == -1 | tag_update == 1)
        {
            return tag_update;
        }
        ele = &(imageMsgManager_->m_display_list0.last());
    }
    else
    {
        ele = &(imageMsgManager_->m_display_list1.last());
    }

    qDebug() << "ImageMessageListModel::update1111111" << ele->img_url_;

    qDebug() << "AAAAAAA" << m_display_list.size() << ele->img_id_;
    m_display_list.append(ele);
    m_imgId_list.append(ele->img_id_);
    emit layoutChanged();
    return 0;
}
