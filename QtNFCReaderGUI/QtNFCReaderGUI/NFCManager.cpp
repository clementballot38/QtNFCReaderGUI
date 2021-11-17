#include "NFCManager.h"



// constructor
NFCManager::NFCManager(QMainWindow* _parent)
    : parent(_parent)
{
}



/*
* Function to handle connection with NFC reader
*/
bool NFCManager::connect()
{
    // set NFC reader settings
    this->nfc_reader.Type = ReaderCDC;
    this->nfc_reader.device = 0;

    // start reading
    this->status = OpenCOM(&this->nfc_reader);

    if (this->status == MI_OK)
    {
        // turn RF power on
        RF_Power_Control(&this->nfc_reader, TRUE, 0);

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



/*
* Function to save data to the card
*/
bool NFCManager::save(std::string fname, std::string lname) {
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];

    // connect to the card
    this->status = ISO14443_3_A_PollCard(&this->nfc_reader, atq, sak, uid, &this->uid_len);

    if (this->status == MI_OK)
    {
        // convert strings to char arrays
        QByteArray fname_array = QString::fromStdString(fname).toLocal8Bit();
        QByteArray lname_array = QString::fromStdString(lname).toLocal8Bit();

        // try to save values on the card
        int fname_status = Mf_Classic_Write_Block(&this->nfc_reader, TRUE, 9, (unsigned char*)strdup(fname_array.constData()), Auth_KeyB, 2),
            lname_status = Mf_Classic_Write_Block(&this->nfc_reader, TRUE, 10, (unsigned char*)strdup(lname_array.constData()), Auth_KeyB, 2);
        
        // check the final status
        this->status = (fname_status == MI_OK && lname_status == MI_OK) ? MI_OK : MI_WRITEERR;

        if (this->status == MI_OK)
        {
            // save the values locally
            this->first_name = fname;
            this->last_name = lname;
        }
        return this->status == MI_OK;
    }
    else
    {
        return false;
    }
}



/*
* Function to load data from card
*/
bool NFCManager::load()
{
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];

    // connect to the card
    this->status = ISO14443_3_A_PollCard(&this->nfc_reader, atq, sak, uid, &uid_len);

    if (this->status == MI_OK)
    {
        // try to read datas from the card
        uint8_t lname_array[16], fname_array[16], counter_array[16];
        int lname_status = Mf_Classic_Read_Block(&this->nfc_reader, TRUE, 10, lname_array, Auth_KeyA, 2),
            fname_status = Mf_Classic_Read_Block(&this->nfc_reader, TRUE, 9, fname_array, Auth_KeyA, 2),
            count_status = Mf_Classic_Read_Block(&this->nfc_reader, TRUE, 14, counter_array, Auth_KeyB, 3);

        // check the final status
        this->status = (fname_status == MI_OK && lname_status == MI_OK && count_status == MI_OK) ? MI_OK : MI_READERR;

        if (this->status == MI_OK)
        {
            // save the values locally
            this->last_name = this->arrayToString(lname_array, 16);
            this->first_name = this->arrayToString(fname_array, 16);
            this->count_val = counter_array[0];
        }
        return this->status == MI_OK;
    }
    else
        return false;
}



/*
* Function to increment the counter
*/
bool NFCManager::increment(uint inc_val)
{
    int inc_status = Mf_Classic_Increment_Value(&this->nfc_reader, TRUE, 14, inc_val, 13, Auth_KeyB, 3),
        res_status = Mf_Classic_Restore_Value(&this->nfc_reader, TRUE, 13, 14, Auth_KeyB, 3),
        rea_status = Mf_Classic_Read_Value(&this->nfc_reader, TRUE, 14, &this->count_val, Auth_KeyB, 3);
    this->status = (inc_status == MI_OK && res_status == MI_OK && rea_status == MI_OK) ? MI_OK : MI_INCRERR;
    return this->status == MI_OK;
}



/*
* Function to decrement the counter
*/
bool NFCManager::decrement(uint dec_val)
{
    int dec_status = Mf_Classic_Decrement_Value(&this->nfc_reader, TRUE, 14, dec_val, 13, Auth_KeyB, 3),
        res_status = Mf_Classic_Restore_Value(&this->nfc_reader, TRUE, 13, 14, Auth_KeyB, 3),
        rea_status = Mf_Classic_Read_Value(&this->nfc_reader, TRUE, 14, &this->count_val, Auth_KeyB, 3);
    this->status = (dec_status == MI_OK && res_status == MI_OK && rea_status == MI_OK) ? MI_OK : MI_DECRERR;
    return this->status == MI_OK;
}




/*
* Function to convert a char array to a string
*/
std::string NFCManager::arrayToString(uint8_t* arr, uint len)
{
    std::string temp = "";
    for (uint i = 0; i < len; i++)
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') || arr[i] == '-')
            temp += arr[i];
    return temp;
}



/*
* Functions to get current saved datas
*/
std::string NFCManager::getFirstName()
{
    return this->first_name;
}
std::string NFCManager::getLastName()
{
    return this->last_name;
}
std::string NFCManager::getCounterValue()
{
    return std::to_string(this->count_val);
}