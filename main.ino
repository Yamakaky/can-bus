#include <SPI.h>
#include "mcp_can.h"

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_500KBPS))
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}

void printHex(INT8U item) {
    Serial.print("0x");
    Serial.print(item, HEX);
}

void printBool(INT8U b) {
    if (b) {
        Serial.print("true");
    } else {
        Serial.print("false");
    }
}

void loop()
{
    INT8U len = 0;
    INT8U buf[8];

    if (CAN_MSGAVAIL == CAN.checkReceive()) {
        CAN.readMsgBuf(&len, buf);

        Serial.print("{\"id\": 0x");
        printHex(CAN.getCanId());
        Serial.print(", \"isExtended\": ");
        printBool(CAN.isExtendedFrame());
        Serial.print(", \"isRemote\": ");
        printBool(CAN.isRemoteRequest());

        Serial.print(", \"data\": [");
        if (len > 0) {
            printHex(buf[0]);
            for(size_t i = 1; i < len; i++) {
                Serial.print(", ");
                printHex(buf[i]);
            }
        }
        Serial.println("]}");
    }
}
