#include "RFIDPasswordReader.h"

RFIDPasswordReader::RFIDPasswordReader(byte ssPort, byte rsPort)
    : m_rfid(ssPort, rsPort)
{
}

void RFIDPasswordReader::setup()
{
    this->m_rfid.PCD_Init();
}

bool RFIDPasswordReader::isValid()
{
    return this->m_rfid.PICC_IsNewCardPresent() && this->m_rfid.PICC_ReadCardSerial();
}

uint32_t RFIDPasswordReader::readPassword()
{
    uint32_t pass = *((uint32_t*) &(this->m_rfid.uid.uidByte));

    Serial.println(String(pass, HEX));

    this->m_rfid.PICC_HaltA();
    this->m_rfid.PCD_StopCrypto1();
    
    return pass;
}