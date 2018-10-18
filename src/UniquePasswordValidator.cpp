#include "UniquePasswordValidator.h"

UniquePasswordValidator::UniquePasswordValidator(uint32_t validPassword)
    : m_uniqueValidPassword(validPassword)
{
}

void UniquePasswordValidator::setup()
{
    //
}

bool UniquePasswordValidator::validate(uint32_t pass)
{
    return pass == this->m_uniqueValidPassword;
}