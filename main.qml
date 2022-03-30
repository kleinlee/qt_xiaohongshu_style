import QtQuick 2.0
import QtQuick.Controls
import QtQuick.Window
Window  {
    id: appMainWindow
    width: Qt.platform.os == "android"? Screen.desktopAvailableWidth : 400
    height: Qt.platform.os == "android"? Screen.desktopAvailableHeight : 800
    visible: true
    title: "小红书风格"
    SwipeView {
        id: swipeView
        currentIndex: 0
//        anchors.fill: parent
        width:parent.width
        height: parent.height - tabBar.height
        orientation: Qt.Horizontal
        interactive: true

        DisplayPage {
        }


        Rectangle {
            id: secondPage
            color: "blue"
            Text {
                text: qsTr("社区")
                anchors.centerIn: parent
                font.pixelSize: 25
            }
        }
        Rectangle {
            id: thirdPage
            color: "blue"
            Text {
                text: qsTr("社区")
                anchors.centerIn: parent
                font.pixelSize: 25
            }
        }
        Rectangle {
            id: lastPage
            color: "green"
            Text {
                text: qsTr("设置")
                anchors.centerIn: parent
                font.pixelSize: 25
            }
        }
    }
    TabBar {
        id: tabBar
        width: parent.width
        anchors.bottom: parent.bottom
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("形象")
        }
        TabButton {
            text: qsTr("社区")
        }
        TabButton {
            text: qsTr("设置")
        }
        TabButton {
            text: qsTr("设置")
        }
    }
}
