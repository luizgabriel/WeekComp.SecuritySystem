#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "SecurityManager.h"

class ServoReleLock : public ILockController
{
  public:
    ServoReleLock(uint8_t servoPort, uint8_t relePort);
    virtual void setup();
    virtual void lock();
    virtual void unlock();

  private:
    Servo m_servo;
    uint8_t m_relePort;
    uint8_t m_servoPort;
};