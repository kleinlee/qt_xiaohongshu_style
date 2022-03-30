import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Rectangle {
    id: rect_ImageMsg
    property int col_id: 0
    property string sssss: ""

    height: image1_DisplayPage.height + text1_DisplayPage.implicitHeight + row1_DisplayPage.height + 16
//                        radius: 10
    layer.enabled: true
    layer.effect: OpacityMask {
        maskSource: Rectangle {
            width: rect_ImageMsg.width
            height: image1_DisplayPage.height + text1_DisplayPage.implicitHeight + row1_DisplayPage.height + 16
            radius: 5
        }
    }

    Image {
        id: image1_DisplayPage
        width: parent.width
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        property string sss:  "image://colors/" + (index + 1).toString()
//        source: "image://colors/" + (Math.max(0,index + 0)).toString()
        source: "image://colors/col" + col_id + "_" + index
//        source: msg_image_id
//        source: Math.random() > 0.5? "image://colors/4":"image://colors/3"

    }
    Text {
        id: text1_DisplayPage
        width: parent.width - 16
        anchors.top: image1_DisplayPage.bottom
        anchors.topMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter

        wrapMode: Text.WrapAnywhere
        maximumLineCount: 2
        verticalAlignment: Text.AlignVCenter;
//                horizontalAlignment: Text.AlignHCenter;
//        text: "兄弟们，看看我的新女朋友怎么样"
        text: sssss
        font.pointSize: 14;
        font.weight: 1000
        font.wordSpacing: 5
    }
    Rectangle {
        id: row1_DisplayPage
        anchors.top: text1_DisplayPage.bottom
        anchors.topMargin: 8
        height: 24
        width: parent.width

        Image {
            x: 8
            source: "qrc:/2.jpg"
            height: parent.height
            width: height
        }
        Text {
            x: 40
            text: "胡歌"
            font.pointSize: 11
            font.weight: 700
            anchors.verticalCenter: parent.verticalCenter
        }

        Image {
            x: parent.width - 60
            height: 20
            width: height
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/like.png"
        }
        Text {
            x: parent.width - 38
            text: "1234"
            color: "gray"
            font.pointSize: 11
            font.weight: 500
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
