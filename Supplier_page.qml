import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["№ Страницы","Название компании","Адрес","Представитель","Контактный телефон","E-mail"]
    property var button_name: ["qrc:/Button/arrow.png","qrc:/Button/add.png","qrc:/Button/save.png","qrc:/Button/del.png","qrc:/Button/arrow.png"]

    property var bufferTextImage
    property bool newData: false

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
                    text: Transport_company.getSupplierIndex(0)+1
                    horizontalAlignment: TextInput.AlignRight
                }
            }

            Repeater
            {
                id: rectad
                model: Transport_company.Supplier_vector.length-2
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
                        id: text_weigth
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
                        text: qsTr(Transport_company.Supplier_vector[index+1])
                        horizontalAlignment: TextInput.AlignRight

                        onTextChanged:
                        {
                            Transport_company.Supplier_vector[index+1] = text_weigth.text

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
                                   Transport_company.Supplier_vector[6] = image_textInput.text
                               }

                               onFocusChanged:
                               {
                                   if (focus) {
                                       bufferTextImage = image_textInput.text
                                       image_textInput.text = ""
                                   }
                               }

                               onActiveFocusChanged: {
                                           if (!activeFocus && image_textInput.text === "") {
                                               image_textInput.text = bufferTextImage
                                           }
                                       }

                               onAccepted:
                               {
                                       image_logo.visible =  true
                                       image_logo.enabled =  true
                                       rect_set_logo_name.visible =  false
                                       rect_set_logo_name.enabled =  false
                                   Database.supplier_addNewData(Transport_company.Supplier_vector)
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
                               if(newData)
                                   newData = false
                               if(Transport_company.getSupplierIndex(0) > 0)
                                    Transport_company.setSupplier_vector(Database.getDataVector(Transport_company.getSupplierIndex(-1),"Supplier","Id_supplier"));
                               image_textInput.text = Transport_company.Supplier_vector[6];
                               text_numer.text = Transport_company.getSupplierIndex(0)+1;
                               break;
                           case 1:
                               Transport_company.supplier_clearVector();
                               newData = true;
                               text_numer.text = Transport_company.getSupplierMaxIndex()+1;
                               break;
                           case 2:
                               console.log(Transport_company.Supplier_vector)
                               if(newData)
                               {
                                   Database.supplier_createNewData(Transport_company.Supplier_vector)
                                   Transport_company.setSupplierMaxIndex( Transport_company.getSupplierMaxIndex()+1)
                                   Transport_company.setSupplier_vector(Database.getDataVector(Transport_company.getSupplierIndex(0),"Supplier","Id_supplier"));
                                   text_numer.text = Transport_company.getSupplierIndex(0)+1;
                               }
                               else
                                   Database.supplier_addNewData(Transport_company.Supplier_vector);
                               break;
                           case 3:
                               Database.delete_Data(Transport_company.Supplier_vector[0], "Supplier","id_supplier");
                               if(Transport_company.getSupplierIndex(0) < Transport_company.getSupplierMaxIndex()-1)
                                  Transport_company.setSupplier_vector(Database.getDataVector(Transport_company.getSupplierIndex(0),"Supplier","Id_supplier"));
                               else
                                   Transport_company.setSupplier_vector(Database.getDataVector(Transport_company.getSupplierIndex(-1),"Supplier","Id_supplier"));
                               Transport_company.setSupplierMaxIndex( Transport_company.getSupplierMaxIndex()-1)
                               text_numer.text = Transport_company.getSupplierIndex(0)+1;
                               break;
                           case 4:
                               if(newData)
                                   newData = false
                               if(Transport_company.getSupplierIndex(0) < Transport_company.getSupplierMaxIndex()-1)
                                    Transport_company.setSupplier_vector(Database.getDataVector(Transport_company.getSupplierIndex(1),"Supplier","Id_supplier"));
                               image_textInput.text = Transport_company.Supplier_vector[6];
                               text_numer.text = Transport_company.getSupplierIndex(0)+1;
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
