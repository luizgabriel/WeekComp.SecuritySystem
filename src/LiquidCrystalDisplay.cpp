#include "LiquidCrystalDisplay.h"

LiquidCrystalDisplay::LiquidCrystalDisplay(uint8_t i2cAddr, int cols, int rows)
    : m_lcd(i2cAddr, cols, rows)
{
}

void LiquidCrystalDisplay::setup()
{
    this->m_lcd.init();
    this->m_lcd.backlight();
}

void LiquidCrystalDisplay::askForPassword()
{
    this->m_lcd.clear();
    this->m_lcd.setCursor(0, 0);
    this->m_lcd.print(F("Aproxime seu"));
    this->m_lcd.setCursor(0, 1);
    this->m_lcd.print(F("cartao do leitor"));
}

void LiquidCrystalDisplay::showPasswordInvalid()
{
    this->m_lcd.clear();
    this->m_lcd.setCursor(0, 0);
    this->m_lcd.print(F("Nao autorizado!"));
}

void LiquidCrystalDisplay::showPasswordValid()
{
    this->m_lcd.clear();
    this->m_lcd.setCursor(0, 0);
    this->m_lcd.print(F("Autorizado!"));
}