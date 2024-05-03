import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle
{
    anchors.fill: parent
    color: "lightgray"

    property var left_button_name: ["Заказы","Автомобили"]
    property var right_button_name: ["Поставщик", "Клиент","Водители"]

    RowLayout
    {
        anchors.fill: parent
       ColumnLayout
       {
           Layout.alignment: Qt.AlignHCenter
           Layout.preferredHeight: parent.height
           Layout.preferredWidth: parent.width * 0.25

           Repeater
           {
               model: 2
               Button
               {
                   Layout.alignment: Qt.AlignHCenter
                   Layout.topMargin: parent.height * 0.05
                   Layout.preferredHeight: parent.height * 0.15
                   Layout.preferredWidth: parent.width * 0.9
                   background: Rectangle
                   {
                       color: parent.pressed ? "gray" : (parent.hovered ? "darkred" : "red")

                       radius: parent.height * 0.1
                       border.color: "black"
                       border.width: parent.width * 0.01
                   }
                   Text
                   {
                       anchors.centerIn: parent
                       text: qsTr(left_button_name[index])
                       font.bold: true
                       font.pixelSize: parent.height * 0.3
                       color: "white"
                   }
                   onClicked:
                   {
                       switch(index)
                       {
                           case 0:
                               main_page.visible = false
                               main_page.enabled = false
                               orders_page.visible = true
                               orders_page.enabled = true

                               orders_page.model_vector_order = Database.getAllModelCar(" ",false)
                               orders_page.supplier_vector_order = Database.getAllSupplierName()
                               orders_page.clients_vector_order = Database.getAllClientsName()
                               orders_page.drivers_vector_order = Database.getAllDriversName()
                               break;
                           case 1:
                               main_page.visible = false
                               main_page.enabled = false
                               car_page.visible = true
                               car_page.enabled = true
                               break;
                           default:
                               break;
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


       ColumnLayout
       {
           Layout.preferredHeight: parent.height
           Layout.preferredWidth: parent.width * 0.5

            Image
            {
                source: "qrc:/Image/Screenshot from 2024-04-16 20-12-31.png"
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight: parent.height * 0.7
                Layout.preferredWidth: parent.width * 0.7
                fillMode: Image.PreserveAspectFit
            }

            Button
            {
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.preferredHeight: parent.height * 0.15
                Layout.preferredWidth: parent.width * 0.5
                background: Rectangle
                {
                    color: parent.pressed ? "gray" : (parent.hovered ? "darkred" : "red")

                    radius: parent.height * 0.1
                    border.color: "black"
                    border.width: parent.width * 0.01
                }
                Text
                {
                    anchors.centerIn: parent
                    text: qsTr("Выход")
                    font.bold: true
                    font.pixelSize: parent.height * 0.3
                    color: "white"
                }
                onClicked: Qt.quit()
            }
       }

       ColumnLayout
       {
           Layout.alignment: Qt.AlignHCenter
           Layout.preferredHeight: parent.height
           Layout.preferredWidth: parent.width * 0.25

           Repeater
           {
               model: 3
               Button
               {
                   Layout.alignment: Qt.AlignHCenter
                   Layout.topMargin: parent.height * 0.05
                   Layout.preferredHeight: parent.height * 0.15
                   Layout.preferredWidth: parent.width * 0.9
                   background: Rectangle
                   {
                       color: parent.pressed ? "gray" : (parent.hovered ? "darkred" : "red")

                       radius: parent.height * 0.1
                       border.color: "black"
                       border.width: parent.width * 0.01
                   }
                   Text
                   {
                       anchors.centerIn: parent
                       text: qsTr(right_button_name[index])
                       font.bold: true
                       font.pixelSize: parent.height * 0.3
                       color: "white"
                   }
                   onClicked:
                   {
                       switch(index)
                       {
                       case 0:
                           main_page.visible = false
                           main_page.enabled = false
                           supplier_page.visible = true
                           supplier_page.enabled = true
                           break
                       case 1:
                           main_page.visible = false
                           main_page.enabled = false
                           clients_page.visible = true
                           clients_page.enabled = true
                           break
                       case 2:
                           main_page.visible = false
                           main_page.enabled = false
                           driver_page.visible = true
                           driver_page.enabled = true
                           break
                       default:
                           break
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
}
