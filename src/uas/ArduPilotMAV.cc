#include "ArduPilotMAV.h"

ArduPilotMAV::ArduPilotMAV(MAVLinkProtocol* mavlink, int id) :
        UAS(mavlink, id)//,
        // place other initializers here
{
}

/**
 * This function is called by MAVLink once a complete, uncorrupted (CRC check valid)
 * mavlink packet is received.
 *
 * @param link Hardware link the message came from (e.g. /dev/ttyUSB0 or UDP port).
 *             messages can be sent back to the system via this link
 * @param message MAVLink message, as received from the MAVLink protocol stack
 */
void ArduPilotMAV::receiveMessage(LinkInterface* link, mavlink_message_t message)
{
    // Let UAS handle the default message set
    UAS::receiveMessage(link, message);

    // Handle your special messages
    switch (message.msgid)
    {
    case MAVLINK_MSG_ID_HEARTBEAT:
        {
            qDebug() << "ARDUPILOT RECEIVED HEARTBEAT";
            break;
        }
    default:
        qDebug() << "\nARDUPILOT RECEIVED MESSAGE WITH ID" << message.msgid;
        break;
    }
}