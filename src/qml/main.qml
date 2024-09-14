import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: window
    width: 600
    height: 900
    visible: true

    ColumnLayout {
        anchors.fill:parent
        Label {
            text: "Basic application"
        }
        Button {
            text: "Button"
            onClicked: core.send()
        }   
        Item {
            Layout.fillHeight: true
        }
    }
}