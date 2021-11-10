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
	NFCManager(QMainWindow* _parent);
	bool connect();
	bool save(std::string fname, std::string lname);
	bool load();
	bool increment(uint inc_val);
	bool decrement(uint dec_val);

	std::string getFirstName();
	std::string getLastName();
	std::string getCounterValue();


private:
	QMainWindow* parent;
	ReaderName nfc_reader;

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


	// fetched infos
	std::string first_name;
	std::string last_name;
	uint32_t count_val = 1;
};

