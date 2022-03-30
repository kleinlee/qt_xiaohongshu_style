#include "imagemsgmanager.h"
#include <QDebug>
#include <QEventLoop>
ImageMsgManager* ImageMsgManager::instance_ = NULL;
ImageMsgManager::ImageMsgManager()
{
    img_num_ = 0;
//    update();
}
// -1说明未下载到图片，0说明该col0更新，1说明该col1更新
int ImageMsgManager::update()
{
    ImageMessage imageMessage;
    imageMessage.img_id_ = img_num_;
    imageMessage.img_url_ = "image://colors/" + QString::number(img_num_);
    if(!downloadPic(imageMessage.img_))
    {
        qDebug()<< "DownLoader error!" << imageMessage.img_url_;
        return -1;
    }

    img_num_ ++;
    qDebug() << "ImageMsgManager::update" << img_num_ << imageMessage.img_url_;
    if (height_col0 > height_col1)
    {
        height_col1 += imageMessage.img_.height()/imageMessage.img_.width();
        m_display_list1.append(imageMessage);
        return 1;
    }
    else
    {
        height_col0 += imageMessage.img_.height()/imageMessage.img_.width();
        m_display_list0.append(imageMessage);
        return 0;
    }
}

bool ImageMsgManager::downloadPic(QImage& image)
{
    QString url = "http://192.168.1.5:8000/download_template/?id=" + QString::number(img_num_);
    request.setUrl(url);
    QEventLoop loop;
    reply = manager.get(request);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug()<< "DownLoader::downloadPic  reply->error()" << "Wrong";
        return false;
    }
    else
    {
        QByteArray data = reply->readAll();
        image = QImage::fromData(data,"jpg");
        qDebug() << "load ready";
//        QString dir_path = "data/" + QString::number(pin_id, 10) + "." + type;
//        QString dir_path = "ssss.jpg";
//        image_.save(dir_path, "JPG");
        qDebug() << "write pic";
        return true;
    }
}
