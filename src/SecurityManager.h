#pragma once

#include <stdint.h>
#include <Arduino.h>

class IDisplay
{
  public:
    virtual void setup();
    virtual void askForPassword() = 0;
    virtual void showPasswordValid() = 0;
    virtual void showPasswordInvalid() = 0;
};

class IPasswordReader
{
  public:
    virtual void setup();
    virtual bool isValid() = 0;
    virtual uint32_t readPassword() = 0;
};

class ILockController
{
  public:
    virtual void setup();
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class IPasswordValidator
{
  public:
    virtual void setup();
    virtual bool validate(uint32_t password) = 0;
};

class SecurityManager
{
  public:
    SecurityManager();
    void setDisplay(IDisplay *display);
    void setPasswordReader(IPasswordReader *passwordReader);
    void setLockController(ILockController *lock);
    void setPasswordValidator(IPasswordValidator *validator);
    void check();

  private:
    IDisplay *m_display;
    IPasswordReader *m_passwordReader;
    ILockController *m_lock;
    IPasswordValidator *m_passwordValidator;
};