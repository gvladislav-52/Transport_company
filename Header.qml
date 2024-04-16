import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle
{
    property var name_page
    property var id_page
    id: header
    Layout.alignment: Qt.AlignHCenter
    Layout.preferredWidth: parent.width
    Layout.preferredHeight: parent.height * 0.1
    color: "red"

    RowLayout
    {
        anchors.fill: parent
        ToolButton
        {
            Layout.alignment: Qt.AlignLeft
            Layout.leftMargin: parent.width * 0.015
            Layout.preferredHeight: parent.height * 0.7
            Layout.preferredWidth: parent.width * 0.05
            background: Rectangle
            {
                color: parent.pressed ? "gray" : (parent.hovered ? "darkred" : "transparent")
                radius: parent.height * 0.1
            }
            Image
            {
                anchors.centerIn: parent
                source: "qrc:/Button/arrow.png"
                width: parent.width * 0.7
                height: parent.height * 0.7
                fillMode: Image.PreserveAspectFit
                mirror: true
            }
            onClicked:
            {
                main_page.visible = true
                main_page.enabled = true
                id_page.visible = false
                id_page.enabled = false
            }
        }

        Text
        {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            Layout.leftMargin: parent.width * 0.05
            text: qsTr(name_page)
            font.bold: true
            font.pixelSize: parent.height * 0.5
            color: "white"
        }

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
