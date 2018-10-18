#include <Arduino.h>
#include <SPI.h>
#include "LiquidCrystalDisplay.h"
#include "RFIDPasswordReader.h"
#include "UniquePasswordValidator.h"
#include "ServoReleLock.h"
#include "SecurityManager.h"

LiquidCrystalDisplay display(0x27, 16, 2);
RFIDPasswordReader passwordReader(10, 9);
UniquePasswordValidator uniqueValidator(0x2e53d011);
ServoReleLock servoReleLock(7, 6);
SecurityManager guard;

void setup()
{
    Serial.begin(9600);
    SPI.begin();

    guard.setDisplay(&display);
    guard.setPasswordReader(&passwordReader);
    guard.setLockController(&servoReleLock);
    guard.setPasswordValidator(&uniqueValidator);
}

void loop()
{
    guard.check();
}
