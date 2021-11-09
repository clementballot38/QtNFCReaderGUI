#include "NFCManager.h"




NFCManager::NFCManager(QMainWindow* _parent)
    : parent(_parent)
{
}



/*
* Functions to handle connection with NFC reader
*/
bool NFCManager::connect()
{
    // set NFC reader settings
    this->nfc_reader.Type = ReaderCDC;
    this->nfc_reader.device = 0;

    // start reading
    int16_t status = OpenCOM(&this->nfc_reader);

    if (status == MI_OK)
    {
        // get NFC reader serial number
        for (int i = 0; i < 4; i++)
            this->serial[i] = this->nfc_reader.serial[i];

        // get NFC reader version
        for (int i = 0; i < 30; i++)
            this->version[i] = this->nfc_reader.version[i];

        // load keys to NFC reader
        Mf_Classic_LoadKey(&this->nfc_reader, Auth_KeyA, key_a, 2);
        Mf_Classic_LoadKey(&this->nfc_reader, Auth_KeyB, key_b, 2);
        Mf_Classic_LoadKey(&this->nfc_reader, Auth_KeyA, key_c, 3);
        Mf_Classic_LoadKey(&this->nfc_reader, Auth_KeyB, key_d, 3);
        
        return true;
    }
    else
    {
        return false;
    }
}