#include "ServoReleLock.h"

ServoReleLock::ServoReleLock(uint8_t servoPort, uint8_t relePort)
    : m_servo(), m_relePort(relePort), m_servoPort(servoPort)
{
}

void ServoReleLock::setup()
{
    this->m_servo.attach(this->m_servoPort, 670, 2500);
    pinMode(this->m_relePort, OUTPUT);
    digitalWrite(this->m_relePort, LOW);

    this->lock();
}

void ServoReleLock::lock()
{
    this->m_servo.write(0);
    delay(500);
    digitalWrite(this->m_relePort, LOW);
}

void ServoReleLock::unlock()
{
    delay(500);
    this->m_servo.write(180);
    delay(500);

    digitalWrite(this->m_relePort, HIGH);
    delay(3000);
}