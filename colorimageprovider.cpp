#include "colorimageprovider.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QEventLoop>

ColorImageProvider::ColorImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{
    imageMsgManager_ = ImageMsgManager::GetInstance();
}

QImage ColorImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    int width = 100;
    int height = 50;

    if (size)
        *size = QSize(width, height);

    QString col = id.split("_")[0];
    int index = id.split("_")[1].toInt();
    qDebug() << "MMMMMMMMMMMM" << col << index;

    if (index == -1)
    {
        return QImage(1,1,QImage::Format_RGB32);
    }
    if (col == "col0")
    {
        return imageMsgManager_->m_display_list0.at(index).img_;
    }
    else
    {
        return imageMsgManager_->m_display_list1.at(index).img_;
    }
}

