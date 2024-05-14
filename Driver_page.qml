import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["№ Страницы","Фамилия","Имя","Отчетство","Водит. удостоверение","Контактный телефон","E-mail","ГосНомер ТС"]
    property var button_name: ["qrc:/Button/arrow.png","qrc:/Button/add.png","qrc:/Button/save.png","qrc:/Button/del.png","qrc:/Button/arrow.png"]
    property bool newData: false
        property var imageBufferText

    ColumnLayout
    {
        anchors.fill: parent

    Header
    {
        name_page: "Водители"
        id_page: driver_page
    }

    RowLayout
    {
        Layout.alignment: Qt.AlignLeft
        Layout.topMargin: parent.height * 0.05
        Layout.preferredWidth: parent.width
        Layout.preferredHeight: parent.height *0.9 - parent.height * 0.05

        ColumnLayout
        {
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width* 0.25

            Repeater
            {
                model: 8
                Rectangle
                {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: parent.height*0.05
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
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width* 0.25

            Rectangle
            {
                Layout.alignment: Qt.AlignLeft
                Layout.preferredHeight: parent.height*0.05
                Layout.preferredWidth: parent.width *0.9
                color: "gray"
                enabled: false
                border.color: "black"
                border.width: parent.height * 0.0025
                clip: true

                TextInput {
                    id: text_numer
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
                    text: Driver_com.getDriversIndex(0)+1
                    horizontalAlignment: TextInput.AlignRight
                }

            }

            Repeater
            {
                model: Driver_com.Drivers_vector.length-2
                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.05
                    Layout.preferredWidth: parent.width *0.9
                    color: "#C0E8FF"
                    border.color: "black"
                    border.width: parent.height * 0.0025
                    clip: true
                    TextInput {
                        id: text_textInput
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
                        text: qsTr(Driver_com.Drivers_vector[index+1])
                        horizontalAlignment: TextInput.AlignRight

                        onTextChanged:
                        {
                            Driver_com.Drivers_vector[index+1] = text_textInput.text
                        }
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
           Layout.preferredWidth: parent.width * 0.5
           Rectangle
           {
               Layout.alignment: Qt.AlignHCenter
               Layout.preferredHeight: parent.height * 0.7
               Layout.preferredWidth: parent.width * 0.7
               radius: parent.height * 0.01
               color: "black"

               Rectangle
               {
                   id: rect_set_logo_name
                   visible: false
                   enabled: false
                   anchors.centerIn: parent
                   width: parent.width
                   height: parent.height
                   color: "gray"
                   clip: true
                   border.color: "black"
                   border.width: parent.height * 0.01

                   ColumnLayout
                   {
                       anchors.fill: parent

                       Text
                       {
                           Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                           Layout.topMargin: parent.height * 0.1
                           text: "Вставте ссылку"
                           font.pixelSize: parent.height * 0.07
                           font.bold: true
                           color: "black"
                       }

                       Rectangle
                       {
                           Layout.alignment: Qt.AlignHCenter
                           Layout.preferredHeight: parent.height * 0.1
                           Layout.preferredWidth: parent.width * 0.9
                           border.color: "black"
                           border.width: parent.height * 0.01
                           clip: true

                           TextInput {
                               id: image_textInput
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
                               text: qsTr(Driver_com.Drivers_vector[8])
                               horizontalAlignment: TextInput.AlignRight

                               onTextChanged:
                               {
                                   Driver_com.Drivers_vector[8] = image_textInput.text
                               }

                               onFocusChanged:
                               {
                                   if (focus) {
                                       imageBufferText = image_textInput.text
                                       image_textInput.text = ""
                                   }
                               }

                               onActiveFocusChanged: {
                                           if (!activeFocus && image_textInput.text === "") {
                                               image_textInput.text = imageBufferText
                                           }
                                       }

                               onAccepted:
                               {
                                       image_logo.visible =  true
                                       image_logo.enabled =  true
                                       rect_set_logo_name.visible =  false
                                       rect_set_logo_name.enabled =  false

                                   //Database.cars_addNewData(Transport_company.Cars_vector)
                               }
                           }
                       }

                       Button
                       {
                           Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                           Layout.bottomMargin: parent.height * 0.1
                           Layout.preferredHeight: parent.height * 0.1
                           Layout.preferredWidth: parent.width * 0.1
                           background: Rectangle
                           {
                               color: parent.pressed ? "gray" : (parent.hovered ? "darkred" : "red")

                               radius: parent.height * 0.1
                               border.color: "black"
                               border.width: parent.width * 0.01
                           }
                           Image
                           {
                               anchors.centerIn: parent
                               source: button_name[3]
                               width: parent.width * 0.7
                               height: parent.height * 0.7
                               fillMode: Image.PreserveAspectFit
                               mirror: true
                           }

                           onClicked:
                           {
                               image_logo.visible =  true
                               image_logo.enabled =  true
                               rect_set_logo_name.visible =  false
                               rect_set_logo_name.enabled =  false
                           }
                       }
                   }
               }
           Image
           {
               id: image_logo
               visible: true
               enabled: true
               source: Driver_com.Drivers_vector[8]
               anchors.fill: parent
               fillMode: Image.PreserveAspectFit
               MouseArea
               {
                   anchors.fill: parent
                   onClicked:
                   {
                       image_logo.visible =  false
                       image_logo.enabled =  false
                       rect_set_logo_name.visible =  true
                       rect_set_logo_name.enabled =  true
                   }
               }
           }
           }

           RowLayout
           {
               Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
               Layout.preferredHeight: parent.height * 0.3
               Layout.preferredWidth: parent.width

               Repeater
               {
                   model: 5
                   Button
                   {
                       Layout.alignment: Qt.AlignTop
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

                       onClicked:
                       {
                           switch(index)
                           {
                           case 0:
                               if(newData)
                                   newData = false
                               if(Driver_com.getDriversIndex(0) > 0)
                                    Driver_com.setDrivers_vector(Database.getDataVector(Driver_com.getDriversIndex(-1),"Drivers","id"));
                               image_textInput.text = Driver_com.Drivers_vector[8];
                               text_numer.text = Driver_com.getDriversIndex(0)+1;
                               break;
                           case 1:
                               Driver_com.drivers_clearVector();
                               newData = true;
                               text_numer.text = Driver_com.getDriversMaxIndex()+1;
                               break;
                           case 2:
                               console.log(Driver_com.Drivers_vector)
                               if(newData)
                               {
                                   Database.drivers_createNewData(Driver_com.Drivers_vector)
                                   Driver_com.setDriversMaxIndex( Driver_com.getDriversMaxIndex()+1)
                                   Driver_com.setDrivers_vector(Database.getDataVector(Driver_com.getDriversIndex(0),"Drivers","id"));
                                   text_numer.text = Driver_com.getDriversIndex(0)+1;
                               }
                               else
                                   Database.drivers_addNewData(Driver_com.Drivers_vector);
                               break;
                           case 3:
                               Database.delete_Data(Driver_com.Drivers_vector[0], "Drivers","id");
                               if(Driver_com.getDriversIndex(0) < Driver_com.getDriversMaxIndex()-1)
                                  Driver_com.setDrivers_vector(Database.getDataVector(Driver_com.getDriversIndex(0),"Drivers","id"));
                               else
                                   Driver_com.setDrivers_vector(Database.getDataVector(Driver_com.getDriversIndex(-1),"Drivers","id"));
                               Driver_com.setDriversMaxIndex( Driver_com.getDriversMaxIndex()-1)
                               text_numer.text = Driver_com.getDriversIndex(0)+1;
                               break;
                           case 4:
                               if(newData)
                                   newData = false
                               if(Driver_com.getDriversIndex(0) < Driver_com.getDriversMaxIndex()-1)
                                    Driver_com.setDrivers_vector(Database.getDataVector(Driver_com.getDriversIndex(1),"Drivers","id"));
                               image_textInput.text = Driver_com.Drivers_vector[8];
                               text_numer.text = Driver_com.getDriversIndex(0)+1;
                               break;
                           }
                       }
                   }
               }
           }
       }
    }
    }
}
