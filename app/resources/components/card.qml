import QtQuick 2.0

Item {
    property alias text: label.text
    property alias image: icon.source
    Text {
        id: label
        width: parent.width

        font.pixelSize: height * (3 / 4)
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.bottom: icon.top
    }
    Image {
        id: icon
        source: "qrc:/assets/blank.svg"
        sourceSize.width: parent.width
        sourceSize.height: parent.width
        anchors.bottom: parent.bottom
    }
}
