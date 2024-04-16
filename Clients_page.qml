import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["id Клиента","Название компании","Контактное лицо","Контактный телефон","E-mail"]
    property var button_name: ["qrc:/Button/arrow.png","qrc:/Button/add.png","qrc:/Button/save.png","qrc:/Button/del.png","qrc:/Button/arrow.png"]

    ColumnLayout
    {
        anchors.fill: parent

    Header
    {
        name_page: "Клиенты"
        id_page: clients_page
    }

    RowLayout
    {
        Layout.alignment: Qt.AlignLeft
        Layout.topMargin: parent.height * 0.05
        Layout.preferredWidth: parent.width
        Layout.preferredHeight: parent.height *0.9 - parent.height * 0.05

        ColumnLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width* 0.4

            Repeater
            {
                model: 5
                Rectangle
                {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: parent.height*0.075
                    Layout.preferredWidth: parent.width *0.9
                    color: "red"
                    border.color: "black"
                    border.width: parent.height * 0.0025
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

            Item
            {
                Layout.preferredHeight: parent.height * 0.3
                Layout.preferredWidth: parent.width
            }
        }

        ColumnLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width* 0.4

            Repeater
            {
                model: 5
                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.075
                    Layout.preferredWidth: parent.width *0.9
                    color: index !== 0? "#C0E8FF": "gray"
                    border.color: "black"
                    border.width: parent.height * 0.0025
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

            Item
            {
                Layout.preferredHeight: parent.height * 0.3
                Layout.preferredWidth: parent.width
            }
        }

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
                Layout.topMargin: parent.height * 0.1
                Layout.preferredHeight: parent.height * 0.4
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
