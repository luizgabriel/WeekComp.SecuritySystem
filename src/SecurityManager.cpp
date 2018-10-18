#include "SecurityManager.h"

SecurityManager::SecurityManager()
{
}

void SecurityManager::setDisplay(IDisplay *display)
{
    this->m_display = display;
    this->m_display->setup();
    this->m_display->askForPassword();
};

void SecurityManager::setPasswordReader(IPasswordReader *passwordReader)
{
    this->m_passwordReader = passwordReader;
    this->m_passwordReader->setup();
};

void SecurityManager::setLockController(ILockController *lock)
{
    this->m_lock = lock;
    this->m_lock->setup();
    this->m_lock->lock();
}

void SecurityManager::setPasswordValidator(IPasswordValidator *validator)
{
    this->m_passwordValidator = validator;
    this->m_passwordValidator->setup();
}

void SecurityManager::check()
{
    if (!this->m_passwordReader->isValid())
        return;

    uint32_t password = this->m_passwordReader->readPassword();

    if (this->m_passwordValidator->validate(password)) {
        this->m_display->showPasswordValid();
        this->m_lock->unlock();
    } else {
        this->m_display->showPasswordInvalid();
        delay(2000);
    }

    this->m_display->askForPassword();
    this->m_lock->lock();
}