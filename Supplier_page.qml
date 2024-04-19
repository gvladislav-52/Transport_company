import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["id Поставщика","Название компании","Адрес","Представитель","Контактный телефон","E-mail"]
    property var button_name: ["qrc:/Button/arrow.png","qrc:/Button/add.png","qrc:/Button/save.png","qrc:/Button/del.png","qrc:/Button/arrow.png"]

    property var inputText_temp: Transport_company.Supplier_vector
    property var bufferText: ["","","","","","",""]

    ColumnLayout
    {
        anchors.fill: parent

    Header
    {
        name_page: "Поставщики"
        id_page: supplier_page
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
                model: 6
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

            Repeater
            {
                id: rectad
                model: Transport_company.Supplier_vector.length-1
                Rectangle
                {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: parent.height*0.05
                    Layout.preferredWidth: parent.width *0.9
                    color: index !== 0? "#C0E8FF": "gray"
                    border.color: "black"
                    border.width: parent.height * 0.0025
                    clip: true
                    TextInput {
                        id: text_weigth
                        anchors
                        {
                            verticalCenter: parent.verticalCenter
                            right: parent.right
                            rightMargin: parent.width * 0.05
                        }
                        enabled: index === 0 ? false : true
                        width: parent.width * 0.95
                        height: parent.height
                        font.pixelSize: parent.height * 0.8
                        color: "black"
                        text: qsTr(Transport_company.Supplier_vector[index])
                        horizontalAlignment: TextInput.AlignRight

                        onTextChanged:
                        {
                            inputText_temp[index] = text_weigth.text

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
               Layout.preferredHeight: parent.height * 0.6
               Layout.preferredWidth: parent.width * 0.6
               radius: parent.height * 0.01
               color: "white"

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
                               text: qsTr(Transport_company.Supplier_vector[6])
                               horizontalAlignment: TextInput.AlignRight

                               onTextChanged:
                               {
                                   inputText_temp[6] = image_textInput.text
                               }

                               onFocusChanged:
                               {
                                   if (focus) {
                                       bufferText[6] = image_textInput.text
                                       image_textInput.text = ""
                                   }
                               }

                               onActiveFocusChanged: {
                                           if (!activeFocus && image_textInput.text === "") {
                                               image_textInput.text = bufferText[6]
                                           }
                                       }

                               onAccepted:
                               {
                                       image_logo.visible =  true
                                       image_logo.enabled =  true
                                       rect_set_logo_name.visible =  false
                                       rect_set_logo_name.enabled =  false
                                   Database.supplier_addNewData(inputText_temp)
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
               source: Transport_company.Supplier_vector[6]
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
                               if(Transport_company.getSupplierIndex(0) > 0)
                                    Transport_company.setSupplier_vector(Database.getSupplierDataVector(Transport_company.getSupplierIndex(-1)));
                               image_textInput.text = Transport_company.Supplier_vector[6];
                               break;
                           case 1:
                               Database.supplier_createNewData();
                               Transport_company.setSupplier_vector(Database.getSupplierDataVector(Transport_company.getSupplierMaxIndex()-1));
                               Transport_company.getSupplierIndex(Transport_company.getSupplierMaxIndex());
                               break;
                           case 2:
                               console.log(inputText_temp)
                               //Transport_company.setSupplier_vector(inputText_temp);
                               Database.supplier_addNewData(inputText_temp)
                               break;
                           case 3:
                               Database.supplier_delData(Transport_company.Supplier_vector[0]);
                               if(Transport_company.getSupplierIndex(0) < Transport_company.getSupplierMaxIndex()-1)
                                    Transport_company.setSupplier_vector(Database.getSupplierDataVector(Transport_company.getSupplierIndex(1)));
                               break;
                           case 4:
                               if(Transport_company.getSupplierIndex(0) < Transport_company.getSupplierMaxIndex()-1)
                                    Transport_company.setSupplier_vector(Database.getSupplierDataVector(Transport_company.getSupplierIndex(1)));
                               image_textInput.text = Transport_company.Supplier_vector[6];
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
