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

    Driver_page
    {
        id: driver_page
        visible: false
        enabled: false
    }

    Orders_page
    {
        id: orders_page
        visible: false
        enabled: false
        model_vector_order: Database.getAllModelCar(" ",false)
        supplier_vector_order: Database.getAllSupplierName()
    }

    Clients_page
    {
        id: clients_page
        visible: false
        enabled: false
    }

    Supplier_page
    {
        id: supplier_page
        visible: false
        enabled: false
    }
}
