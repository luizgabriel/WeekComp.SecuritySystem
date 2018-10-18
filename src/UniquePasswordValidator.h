#pragma once
#include "SecurityManager.h"

class UniquePasswordValidator : public IPasswordValidator
{
  public:
    UniquePasswordValidator(uint32_t validPassword);
    virtual void setup();
    virtual bool validate(uint32_t pass);

  private:
    uint32_t m_uniqueValidPassword;
};