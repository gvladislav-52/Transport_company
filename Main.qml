import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    minimumWidth: 600
    minimumHeight: 300
    title: "Transport company"

    Main_page
    {
        id: main_page
        visible: true
        enabled: true
    }

    Car_page
    {
        id: car_page
        visible: false
        enabled: false
    }
}
