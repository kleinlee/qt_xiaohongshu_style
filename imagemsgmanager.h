#ifndef IMAGEMSGMANAGER_H
#define IMAGEMSGMANAGER_H

#include <QImage>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
struct ImageMessage
{
    int img_id_;
    QString img_url_;
    QImage img_;
    QString text_;
};

class ImageMsgManager
{
private:
    ImageMsgManager();    //构造函数是私有的，这样就不能在其它地方创建该实例
    static ImageMsgManager *instance_;  //定义一个唯一指向实例的静态指针，并且是私有的。
public:
    static ImageMsgManager* GetInstance()
    {
        if(instance_ == NULL)  //判断是否第一次调用
            instance_ = new ImageMsgManager();
        return instance_;
    }

    bool downloadPic(QImage& image);
    int update();

    QNetworkAccessManager manager;
    QNetworkRequest request;
    QNetworkReply *reply;

    int height_col0 = 0;
    int height_col1 = 0;
    int img_num_ = 0;
    QList<ImageMessage> m_display_list0;
    QList<ImageMessage> m_display_list1;
};

#endif // IMAGEMSGMANAGER_H
