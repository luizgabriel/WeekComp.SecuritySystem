#include "SecurityManager.h"
#include <MFRC522.h>

class RFIDPasswordReader : public IPasswordReader
{
  public:
    RFIDPasswordReader(byte ssPort, byte rsPort);
    virtual void setup();
    virtual bool isValid();
    virtual uint32_t readPassword();

  private:
    MFRC522 m_rfid;
};