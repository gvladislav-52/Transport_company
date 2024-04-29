import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Window 2.15

Rectangle {
    anchors.fill: parent
    color: "lightgray"

    property var parameters_name: ["id Заказа","id Клиента","id Водителя","Дата размещения","Дата назначения","Дата исполнения","Адрес доставки"]
    property var button_name: ["qrc:/Button/arrow.png","qrc:/Button/add.png","qrc:/Button/save.png","qrc:/Button/del.png","qrc:/Button/arrow.png"]
    property var label_name: ["Марка","Модель","Объем","Мощность","Количество","Скидка","Итоговая цена"]

    property var ttest: [20,36,1,32,213]

    property var supplier_vector_order
    property var model_vector_order

    property var marksComboBox: []
    property var modelsComboBox: []

    property var volume: []
    property var power: []
    property var cost: []

    property var testNode: []

    ColumnLayout
    {

        property int test_r: 3
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
                        color: "#C0E8FF"
                        border.color: "black"
                        border.width: parent.height * 0.005
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
                            text: qsTr(Transport_company.Cars_vector[index+2])
                            horizontalAlignment: TextInput.AlignRight

                            onTextChanged:
                            {
                                Transport_company.Cars_vector[index+2] = text_textInput.text
                            }
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
                            Layout.preferredWidth: parent.width/7.05
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
                                text: label_name[index]
                                horizontalAlignment: TextInput.AlignHCenter
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
                        model: 3

                        RowLayout {
                            property var ebanIndex: index
                            Layout.preferredHeight: my_food_list.height* 0.2
                            Layout.preferredWidth: parent.width
                            spacing: 0

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true

                                 ComboBox {
                                    id: comboBox
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        left: parent.left
                                    }
                                    width: parent.width
                                    height: parent.height

                                    model: supplier_vector_order

                                    background: Rectangle {
                                        color: "white"
                                    border.width: parent && parent.activeFocus ? 2 : 1
                                    }

                                    contentItem: Text {
                                        id: marks_text
                                        text: supplier_vector_order[marksComboBox[ebanIndex]]
                                        color: "black"
                                        font.bold: true
                                        font.pixelSize: comboBox.height * 0.3
                                        horizontalAlignment: TextInput.AlignHCenter
                                        verticalAlignment: TextInput.AlignVCenter
                                    }

                                    onActivated: {
                                        marksComboBox[ebanIndex] = comboBox.currentIndex
                                        marks_text.text = comboBox.textAt(marksComboBox[ebanIndex])
                                        comboBox1.model = Database.getAllModelCar(comboBox.textAt(marksComboBox[ebanIndex]),true)
                                        comboBox1.currentIndex = -1;
                                        model_text.text = ""
                                            }

                                             onActiveFocusChanged:
                                            {
                                                if(my_food_list_repeater.model-index === 1)
                                                     my_food_list_repeater.model = ++my_food_list_repeater.model
                                            }
                                        }
                                    }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true

                                 ComboBox {
                                    id: comboBox1
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        left: parent.left
                                    }
                                    width: parent.width
                                    height: parent.height

                                    model: Database.getAllModelCar("123",false)

                                    currentIndex: 0

                                    background: Rectangle {
                                        color: "white"
                                    border.width: parent && parent.activeFocus ? 2 : 1
                                    }

                                    contentItem: Text {
                                        id: model_text
                                        text: model_vector_order[modelsComboBox[ebanIndex]]
                                        color: "black"
                                        font.bold: true
                                        font.pixelSize: comboBox1.height * 0.3
                                        horizontalAlignment: TextInput.AlignHCenter
                                        verticalAlignment: TextInput.AlignVCenter
                                    }

                                    onActivated: {
                                        model_text.text = comboBox1.currentText;
                                        modelsComboBox[ebanIndex] = model_vector_order.indexOf(comboBox1.currentText);
                                        volume_text.text = Database.getItemCar(model_text.text,4)
                                        volume[ebanIndex] = volume_text.text
                                        power_text.text = Database.getItemCar(model_text.text,5)
                                        power[ebanIndex] = power_text.text
                                        cost_text.text = Database.getItemCar(model_text.text,9)
                                        cost[ebanIndex] = cost_text.text
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "lightgray"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                Text {
                                    id: volume_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: volume[ebanIndex]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "lightgray"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                Text {
                                    id: power_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: power[ebanIndex]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                TextInput {
                                    id: kol_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: qsTr("")
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter

                                    onActiveFocusChanged:
                                    {
                                        if(my_food_list_repeater.model-index === 1)
                                            my_food_list_repeater.model = ++my_food_list_repeater.model
                                    }

                                    onAccepted: {

                                        cost_text.text = cost[ebanIndex]*kol_text.text
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                TextInput {
                                    id: sale_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: qsTr("")
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter

                                    onActiveFocusChanged:
                                    {
                                        if(my_food_list_repeater.model-index === 1)
                                            my_food_list_repeater.model = ++my_food_list_repeater.model
                                    }

                                    onAccepted: {

                                        cost_text.text = (cost[ebanIndex]*kol_text.text)*((100-parseInt(sale_text.text))/100)
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: parent.width/7.05
                                Layout.preferredHeight: parent.height
                                color: "lightgray"
                                border.color: "black"
                                border.width: parent.width * 0.001
                                clip: true
                                Text {
                                    id: cost_text
                                    anchors
                                    {
                                        verticalCenter: parent.verticalCenter
                                        right: parent.right
                                        rightMargin: parent.width * 0.05
                                    }
                                    width: parent.width * 0.95
                                    height: parent.height
                                    color: "black"
                                    font.bold: true
                                    font.pixelSize: comboBox.height * 0.3
                                    text: cost[ebanIndex]
                                    horizontalAlignment: TextInput.AlignHCenter
                                    verticalAlignment: TextInput.AlignVCenter
                                }
                            }
                        }
                    }

                    // Button
                    // {
                    //     Layout.alignment: Qt.AlignBottom| Qt.AlignHCenter
                    //     Layout.preferredHeight: my_food_list.height * 0.15
                    //     Layout.preferredWidth: my_food_list.width * 0.35
                    //     background: Rectangle
                    //     {
                    //         color: parent.pressed ? "red" : (parent.hovered ? "darkred" : "gray")

                    //         radius: parent.height * 0.1
                    //         border.color: "black"
                    //         border.width: parent.width * 0.01

                    //     }
                    //     Text
                    //     {
                    //         anchors
                    //         {
                    //             centerIn: parent
                    //         }

                    //         text: "Добавить новое значение"
                    //         font.pixelSize: parent.height * 0.5
                    //         color: "black"
                    //     }

                    //     onClicked: my_food_list_repeater.model = ++my_food_list_repeater.model
                    // }
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
                    onClicked:
                    {
                        for(var i = 0; i<marksComboBox.length; i++)
                        {
                            testNode[0] = Database.getSupplierId(supplier_vector_order[marksComboBox[i]])
                            testNode[1] = Database.getCarId(model_vector_order[modelsComboBox[i]])
                            testNode[2] = volume[i]
                            testNode[3] = power[i]
                            testNode[4] = cost[i]
                            console.log(testNode);
                        }

                    //         marksComboBox: []
                    //     modelsComboBox: []

                    //     property var volume: []
                    //     property var power: []
                    //     property var cost: []

                    }
                }
            }
        }
    }
}
