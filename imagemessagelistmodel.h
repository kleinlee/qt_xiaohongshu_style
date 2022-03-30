#ifndef IMAGEMESSAGELISTMODEL_H
#define IMAGEMESSAGELISTMODEL_H
#include <QAbstractListModel>
#include <QList>
#include <QString>
#include <QHash>
#include <QImage>
#include <QQmlEngine>
#include "imagemsgmanager.h"

class ImageMessageListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_NAMED_ELEMENT(ImageMessageListModel)
    Q_PROPERTY(int colIndex READ colIndex WRITE setColIndex)
    Q_PROPERTY(QList<int> imgIdList READ imgIdList WRITE setImgIdList NOTIFY imgIdListChanged)
signals:
    void imgIdListChanged();
public:
    explicit ImageMessageListModel(QObject *parent = 0);

//    Q_INVOKABLE int addNew(QString strName);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE int update();

    enum LineInfo_Roles{
        RoleImageID = Qt::UserRole + 1,
        RoleImage,
        RoleText
    };

    int colIndex() const { return colIndex_; }
    void setColIndex(int colIndex);

    QList<int> imgIdList() const { return m_imgId_list; }
    void setImgIdList(QList<int> imgIdList);

private:
    QHash<int, QByteArray> m_roleNames;
    QList<ImageMessage*> m_display_list;

    QList<int> m_imgId_list;

    int colIndex_;

    ImageMsgManager* imageMsgManager_;
};

#endif // IMAGEMESSAGELISTMODEL_H
