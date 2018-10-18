#pragma once

#include <LiquidCrystal_I2C.h>
#include <inttypes.h>
#include "SecurityManager.h"

class LiquidCrystalDisplay : public IDisplay
{
  public:
    LiquidCrystalDisplay(uint8_t i2cAddr, int cols, int rows);
    virtual void setup();
    virtual void askForPassword();
    virtual void showPasswordValid();
    virtual void showPasswordInvalid();

  private:
    LiquidCrystal_I2C m_lcd;
};