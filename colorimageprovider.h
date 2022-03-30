#ifndef COLORIMAGEPROVIDER_H
#define COLORIMAGEPROVIDER_H

#include <qqmlextensionplugin.h>

#include <qqmlengine.h>
#include <qquickimageprovider.h>
#include <QImage>
#include "imagemsgmanager.h"
class ColorImageProvider : public QQuickImageProvider
{
public:
    ColorImageProvider();

//    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

    ImageMsgManager* imageMsgManager_;
};


#endif // COLORIMAGEPROVIDER_H
