import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Window 2.15

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    ColumnLayout
    {
        anchors.fill: parent
        Header
        {
            name_page: "Заказы"
            id_page: orders_page
        }

        // ListModel {
        //     id: fruitModel
        //     ListElement { name: "Apple"; cost: 0.5 }
        //     ListElement { name: "Banana"; cost: 0.3 }
        //     ListElement { name: "Cherry"; cost: 0.8 }
        // }

        // ListView {
        //     anchors.fill: parent
        //     model: fruitModel
        //     delegate: RowLayout {
        //         Text {
        //             text: model.name
        //             font.pixelSize: 16
        //             verticalAlignment: Text.AlignVCenter
        //         }
        //         Text {
        //             text: "$" + model.cost
        //             font.pixelSize: 16
        //             verticalAlignment: Text.AlignVCenter
        //         }
        //     }
        // }

        Rectangle {
            width: 200
            height: 100
            color: "lightblue"

            MouseArea {
                anchors.fill: parent
                onClicked: dropdown.visible = !dropdown.visible
            }

            Text {
                text: "Нажмите для открытия списка"
                anchors.centerIn: parent
            }

            ListView {
                id: dropdown
                visible: false
                width: parent.width
                height: 120
                clip: true
                model: ListModel {
                    ListElement { text: "Элемент 1" }
                    ListElement { text: "Элемент 2" }
                    ListElement { text: "Элемент 3" }
                    ListElement { text: "Элемент 4" }
                    ListElement { text: "Элемент 5" }
                    ListElement { text: "Элемент 6" }
                }

                delegate: Item {
                    width: parent.width
                    height: 20
                    Text {
                        text: model.text
                        anchors.centerIn: parent
                    }
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
