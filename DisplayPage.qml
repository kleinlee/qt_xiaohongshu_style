import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import AAAAA
Rectangle {
    id: firstPage
    color: "white"

    ImageMessageListModel {
        id: model_col0
        colIndex: 0
    }
    ImageMessageListModel {
        id: model_col1
        colIndex: 1
    }

    Flickable {
        id: flickable_DisplayPage
        anchors.fill: parent
        contentWidth: parent.width
        contentHeight: row.implicitHeight
//        draggingHorizontally: false
        Row {
            id: row
            leftPadding: 10
            rightPadding:10
            spacing: 10
            Column {
                id: col0
                spacing: 10
                Repeater {
                    id: repeater
                    model: model_col0
                    Rect_ImageMsg
                    {
                        col_id: 0
                        sssss: "嘿嘿" + model_col0.imgIdList[index]
                        width: flickable_DisplayPage.width/2 - 15
                    }
                    onCountChanged: {
                        console.log("XXXXXXXXX", repeater.count)
                    }
                }
            }
            Column {
                id: col1
                spacing: 10
                Repeater {
                    model: model_col1
                    Rect_ImageMsg
                    {
                        col_id: 1
                        sssss: "哈哈" + model_col1.imgIdList[index]
                        width: flickable_DisplayPage.width/2 - 15
                    }
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log(col0.height,col1.height,flickable_DisplayPage.contentY,flickable_DisplayPage.contentHeight)
            }
        }
        states: [
            State {
                id: downRefresh
                name: "downRefresh"; when: back.percent === 100
                StateChangeScript {
                    name: "funDownRefresh"
                    script: {
                        if (model_col0.update() === 1)
                        {
                            model_col1.update();
                        }
                        console.log("XXXXXXXXX")
                        if (model_col0.update() === 1)
                        {
                            model_col1.update();
                        }
                        console.log("XXXXXXXXX")
                        if (model_col0.update() === 1)
                        {
                            model_col1.update();
                        }
                        console.log("XXXXXXXXX")
                    }
                }
            }
        ]
    }




    Rectangle {
        id: back
        property int percent: Math.min(100, flickable_DisplayPage.contentY + flickable_DisplayPage.height - flickable_DisplayPage.contentHeight-60)
        visible: percent > 0? true:false
        anchors.bottom: parent.bottom
        x: (parent.width - width)/2
        width: 60
        height: width
        radius: width / 2
        color: "transparent"
        border.width: 7
        border.color: percent === 100 ? "green" : "white"     //百分比为100时显示为前景,否则显示为背景

        Text {
            id: t
            text: back.percent === 100? "松开刷新":"下拉刷新"
            anchors.centerIn: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        ConicalGradient {
            anchors.fill: back
            source: back
            enabled: back.percent != 100     //百分比不为100时有效
            visible: enabled            //百分比不为100时有效
            gradient: Gradient {
                GradientStop { position: 0.0; color: "white" }
                GradientStop { position: back.percent / 100 ; color: "green" }
                GradientStop { position: back.percent / 100 + 0.001; color: "white" }
                GradientStop { position: 1.0; color: "white" }
            }
        }
    }


}
