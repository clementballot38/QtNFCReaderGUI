/*
* NFCManager
* ----------
* 
* This class handles the management of a NFC reader : connect,
* read, write, incrementing & decremeting.
* 
* Usage :
* To use this class, add the following code :
* NFCManager manager = new NFCManager(<main window>);
* manager.<function>();
* 
* Data scheme :
* Data on the NFC tag are stored as following :
*	+------------+--------+-------+
*	|    name    | sector | block |
*	+------------+--------+-------+
*	| fisrt name |   2    |   9   |
*	+------------+--------+-------+
*	| last name  |   2    |  10   |
*	+------------+--------+-------+
*	|  counter   |   3    |  14   |
*	+------------+--------+-------+
*/





#pragma once
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "lib/MfErrNo.h"
#include "lib/ODALID.h"
#include <string>
#include <qdebug.h>



class NFCManager
{
public :
	// constructor
	NFCManager(QMainWindow* _parent);
	
	bool connect();	// attempt to connect to the reader
	bool load();	// load data from the tag
	bool save(std::string fname, std::string lname);	// write data to the tag
	bool increment(uint inc_val);	// increment the counter
	bool decrement(uint dec_val);	// decrement the counter

	bool isConnected();	// get connexion status

	std::string getFirstName();		// get the first name
	std::string getLastName();		// get the last name
	std::string getCounterValue();	// get the counter value


private:
	QMainWindow* parent;	// attached window
	ReaderName nfc_reader;	// NFC reader

	void updateConnectionStatus();	// update the connexion status based on the current status

	// converts a char array to string
	std::string arrayToString(uint8_t* arr, uint len);

	// keys
	uint8_t key_a[6] = { 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5 };
	uint8_t key_b[6] = { 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5 };
	uint8_t key_c[6] = { 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5 };
	uint8_t key_d[6] = { 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5 };

	// UID length
	uint16_t uid_len = 12;

	// NFC reader infos
	char version[30];
	uint8_t serial[4] = { 0, 0, 0, 0 };
	int status = MI_OK;

	// stored values
	std::string first_name;
	std::string last_name;
	uint32_t count_val = 1;
	bool connected = false;
};

