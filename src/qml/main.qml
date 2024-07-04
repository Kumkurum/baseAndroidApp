import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 320
    height: 640
    visible: true

    ColumnLayout {
        Label {
            text: "Basic application"
        }
        Button {
            text: "Button"
        }   
        Item {
            Layout.fillHeight: true
        }
    }
}