import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        anchors.centerIn: parent
        spacing: 30

        Row {
            spacing: 10
            Label {
                id: lbl

                font.pixelSize: 20
                anchors.top: parent.top
                anchors.topMargin: 20
                text: "Path  "
            }

            TextField {
                id: txtField
                width: 250
            }
        }
        Button {
            id: btn
            width: 100
            height: 30
            text: "Save"

            anchors.left: parent.left
            anchors.leftMargin: 100

            onPressed: {
                if (txtField.text != "")
                    Cleaner.do_clean(txtField.text)
                else
                    Cleaner.do_clean("dEfAuLt")

                popup.open()
            }
        }
    }

    Popup {
        id: popup
        width: parent.width / 3
        height: parent.height / 6

        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height - 50) / 3)
        Text {
            id: popTxt
            text: qsTr("Done")
            anchors.centerIn: parent
        }
    }
}
