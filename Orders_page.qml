import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Window 2.15

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["id Водителя","Фамилия","Имя","Отчетство","Водит. удостоверение","Контактный телефон","E-mail"]
    property var button_name: ["qrc:/Button/arrow.png","qrc:/Button/add.png","qrc:/Button/save.png","qrc:/Button/del.png","qrc:/Button/arrow.png"]
    ColumnLayout
    {
        anchors.fill: parent
        Header
        {
            name_page: "Заказы"
            id_page: orders_page
        }

        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: parent.width * 0.05
            Layout.topMargin: parent.height * 0.05
            Layout.preferredWidth: parent.width * 0.9
            Layout.preferredHeight: parent.height *0.7 - parent.height * 0.05

            ColumnLayout
            {
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width* 0.3

                Repeater
                {
                    model: 7
                    Rectangle
                    {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredHeight: parent.height*0.1
                        Layout.preferredWidth: parent.width *0.9
                        color: "red"
                        border.color: "black"
                        border.width: parent.height * 0.005
                        clip: true
                        Text {
                            anchors
                            {
                                verticalCenter: parent.verticalCenter
                                left: parent.left
                                leftMargin: parent.width * 0.05
                            }
                            font.pixelSize: parent.height * 0.7
                            font.bold: true
                            color: "white"

                            text: qsTr(parameters_name[index])
                        }
                    }
                }
            }

            ColumnLayout
            {
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width* 0.3

                Repeater
                {
                    model: 7
                    Rectangle
                    {
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight: parent.height*0.1
                        Layout.preferredWidth: parent.width *0.9
                        color: index !== 0? "#C0E8FF": "gray"
                        border.color: "black"
                        border.width: parent.height * 0.005
                        clip: true
                        TextInput {
                            anchors
                            {
                                verticalCenter: parent.verticalCenter
                                right: parent.right
                                rightMargin: parent.width * 0.05
                            }
                            width: parent.width * 0.95
                            height: parent.height
                            font.pixelSize: parent.height * 0.8
                            color: "black"
                            text: qsTr("")
                            horizontalAlignment: TextInput.AlignRight
                        }
                    }
                }
            }

            ColumnLayout
            {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width* 0.4

                Item
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height * 0.075
                    Layout.preferredWidth: parent.width * 0.85

                    Text
                    {
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            right: cost_rect.left
                            rightMargin: parent.width * 0.075
                        }
                        text: qsTr("Итог: ")
                        font.pixelSize: parent.height * 0.6
                        font.bold: true
                    }
                    Rectangle
                    {
                        id: cost_rect
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            right: parent.right
                        }
                        height: parent.height
                        width: parent.width * 0.5
                        color: "white"
                        border.color: "black"
                        clip: true

                        Text
                        {
                            anchors
                            {
                                verticalCenter: parent.verticalCenter
                                right: parent.right
                                rightMargin: parent.width * 0.05
                            }
                            text: qsTr("500.000 RUB")
                            font.pixelSize: parent.height* 0.4
                            horizontalAlignment: Text.AlignRight
                        }
                    }
                }

                Item
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }
        }


        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Rectangle
        {
            id: my_food_list
            Layout.alignment: Qt.alignTop | Qt.AlignHCenter
            Layout.preferredHeight: parent.height * 0.3
            Layout.preferredWidth: parent.width * 0.9
            clip: true
            border.color: "black"
            color: "#121212"

            Item
            {
                id: name_type
                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                }
                width: parent.width
                height: parent.height * 0.1

                RowLayout {
                    height: parent.height
                    width: parent.width
                    spacing: 0

                    Repeater
                    {
                        model: 7
                        Rectangle
                        {
                            Layout.alignment: Qt.AlignHCenter
                            Layout.preferredWidth: parent.width/7
                            Layout.preferredHeight: parent.height
                            color: "gray"
                            border.color: "black"
                            border.width: parent.width * 0.001

                            Text {
                                anchors
                                {
                                    verticalCenter: parent.verticalCenter
                                    right: parent.right
                                    rightMargin: parent.width * 0.05
                                }
                                width: parent.width * 0.95
                                height: parent.height
                                font.pixelSize: parent.height * 0.8
                                color: "black"
                                text: qsTr("")
                                horizontalAlignment: TextInput.AlignRight
                            }
                        }
                    }
                }
            }

            Item {
                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    top: name_type.bottom
                }
                width: parent.width
                height: parent.height - name_type.height

            ScrollView
            {
                anchors.fill: parent
                clip: true
                ScrollBar.vertical.policy: ScrollBar.AlwaysOff
                contentHeight: my_food_column.height

            ColumnLayout {
                id: my_food_column
                width: parent.width
                spacing: 0
                anchors
                {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                }

                    Repeater {
                        id: my_food_list_repeater
                        model: 10

                        RowLayout {
                            Layout.preferredHeight: my_food_list.height* 0.2
                            Layout.preferredWidth: parent.width
                            spacing: 0

                            Repeater
                            {
                                model: 7
                                Rectangle
                                {
                                    Layout.alignment: Qt.AlignHCenter
                                    Layout.preferredWidth: parent.width/7
                                    Layout.preferredHeight: parent.height
                                    color: "white"
                                    border.color: "black"
                                    border.width: parent.width * 0.001

                                    TextInput {
                                        anchors
                                        {
                                            verticalCenter: parent.verticalCenter
                                            right: parent.right
                                            rightMargin: parent.width * 0.05
                                        }
                                        width: parent.width * 0.95
                                        height: parent.height
                                        font.pixelSize: parent.height * 0.8
                                        color: "black"
                                        text: qsTr("")
                                        horizontalAlignment: TextInput.AlignRight
                                    }
                                }
                            }
                        }
                    }
                }
            }
       }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.preferredHeight: parent.height * 0.2
            Layout.preferredWidth: parent.width

            Repeater
            {
                model: 5
                Button
                {
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    Layout.preferredHeight: parent.height * 0.6
                    Layout.preferredWidth: parent.width * 0.15
                    background: Rectangle
                    {
                        color: parent.pressed ? "red" : (parent.hovered ? "darkred" : "gray")

                        radius: parent.height * 0.1
                        border.color: "black"
                        border.width: parent.width * 0.01
                    }
                    Image
                    {
                        anchors.centerIn: parent
                        source: button_name[index]
                        width: parent.width * 0.7
                        height: parent.height * 0.7
                        fillMode: Image.PreserveAspectFit
                        mirror: index ===0? true: false
                    }
                }
            }
        }
    }
}
