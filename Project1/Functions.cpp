#pragma once
#include"harley.h"
#include<iostream>
#include<cstring>
#include<string>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<sstream>
#include<iomanip>

using namespace std;

void restart() {
	ShellExecute(0, "open", "Project1.exe", 0, 0, SW_SHOW);
	exit(0);
}
void click() {
	int c = 0;
	ifstream ifile;
	ifile.open("click.dat", ios::binary);
	if (!ifile)
	{
		ofstream ofile2;
		ofile2.open("click.dat", ios::binary);
		ofile2.write((char*)&c, sizeof(int));
		ofile2.close();
	}
	ifile.read((char*)&c, sizeof(int));
	c++;
	ifile.close();
	ofstream ofile;
	ofile.open("click.dat", ios::binary);
	ofile.write((char*)&c, sizeof(int));
	ofile.close();
}
void clickrefresh() {
	int c = 0;
	ofstream ofile;
	ofile.open("click.dat", ios::binary);
	ofile.write((char*)&c, sizeof(int));
	ofile.close();
}
void superignore() {
	int c = 0;
	int newc = 0;
	ifstream ifile;
	ifile.open("click.dat", ios::binary);
	ifile.read((char*)&c, sizeof(int));
	ifile.close();
	ofstream ofile;
	ofile.open("click.dat", ios::binary);
	ofile.write((char*)&newc, sizeof(int));
	ofile.close();
	for (int i = 0; i < c; i++)
		cin.ignore();
}

int codegener(){
	srand(time(NULL));
	ifstream ifile;
	ifile.open("code.dat", ios::binary);
	int newcode;
	if (!ifile)
		newcode = rand() % 10000;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(int);
		int *codes = new int[size];
		ifile.read((char*)codes, size * sizeof(int));
		ifile.close();
		int miss = 1;
		while (miss != 0)
		{
			newcode = rand() % 10000;
			miss = 0;
			for (int i = 0; i < size; i++)
			{
				if (newcode == codes[i])
					miss++;
			}
		}
		delete[]codes;
	}
	ofstream ofile;
	ofile.open("code.dat", ios::binary | ios::app);
	ofile.write((char*)&newcode, sizeof(int));
	ofile.close();
	return newcode;
}

void addmoto() {
	superignore();
	system("CLS");
	maininfo motomain;
	moto additional;
	char code[6];
	strcpy_s(code, "M");
	char number[5];
	_itoa_s(codegener(), number, 10);
	strcat_s(code, number);
	strcpy_s(motomain.code, code);
	strcpy_s(additional.code, code);
	//while (cin.get() != '\n');
	cout << "Enter motorcycle model: ";
	cin.getline(motomain.model, 100);
	strcheck(motomain.model, 14);
	/*latin(motomain.model, 14);*/
	correct(motomain.model);
	cout << "Enter motorcycle series: ";
	cin.getline(additional.lot, 100);
	strcheck(additional.lot, 14);
	correct(additional.lot);
	cout << "Enter engine volume(cm^3): ";
	cin >> additional.volume;
	additional.volume = intcheck(additional.volume);
	cout << "Enter high of seat(cm): ";
	cin >> additional.high;
	additional.high = floatcheck(additional.high);
	cout << "Enter mass(kg): ";
	cin >> additional.mass;
	additional.mass = floatcheck(additional.mass);
	cout << "Enter torque(Nm): ";
	cin >> additional.torque;
	additional.torque = floatcheck(additional.torque);
	cout << "Enter fuelrate(L/100km): ";
	cin >> additional.fuelrate;
	additional.fuelrate = floatcheck(additional.fuelrate);
	cout << "Enter year of edition: ";
	cin >> additional.year;
	additional.year = intcheck(additional.year);
	cout << "Enter price(euro): ";
	cin >> motomain.price;
	motomain.price = floatcheck(motomain.price);
	cout << "Enter amount of motorcycles on store:";
	cin >> motomain.count;
	motomain.count = intcheck(motomain.count);
	ofstream ofile;
	ofile.open("maininfo.dat", ios::binary | ios::app);
	ofile.write((char*)&motomain, sizeof(maininfo));
	ofile.close();
	ofstream ofile2;
	ofile2.open("moto.dat", ios::binary | ios::app);
	ofile2.write((char*)&additional, sizeof(moto));
	ofile2.close();
	system("CLS");
	cout << "Done..." << endl;
	Sleep(1000);
	restart();
}

void addequip() {
	superignore();
	system("CLS");
	maininfo equipmain;
	equip additional;
	char code[6];
	strcpy_s(code, "E");
	char number[5];
	_itoa_s(codegener(), number, 10);
	strcat_s(code, number);
	strcpy_s(equipmain.code, code);
	strcpy_s(additional.code, code);
	cout << "Enter model: ";
	cin.getline(equipmain.model, 100);
	strcheck(equipmain.model, 14);
	correct(equipmain.model);
	cout << "Enter type: ";
	cin.getline(additional.type, 100);
	strcheck(additional.type, 14);
	correct(equipmain.model);
	cout << "Enter size(Euro standart): ";
	cin.getline(additional.size, 100);
	strcheck(additional.size, 7);
	cout << "Enter material: ";
	cin.getline(additional.material, 100);
	strcheck(additional.material, 24);
	cout << "Enter price(euro): ";
	cin >> equipmain.price;
	equipmain.price = floatcheck(equipmain.price);
	cout << "Enter amount of equipment on storage: ";
	cin >> equipmain.count;
	equipmain.count = intcheck(equipmain.count);
	ofstream ofile;
	ofile.open("maininfo.dat", ios::binary | ios::app);
	ofile.write((char*)&equipmain, sizeof(maininfo));
	ofile.close();
	ofstream ofile2;
	ofile2.open("equip.dat", ios::binary | ios::app);
	ofile2.write((char*)&additional, sizeof(equip));
	ofile2.close();
	system("CLS");
	cout << "Done..." << endl;
	Sleep(1000);
	restart();
}

void addacces() {
	superignore();
	system("CLS");
	maininfo accesmain;
	acces additional;
	char code[6];
	strcpy_s(code, "A");
	char number[5];
	_itoa_s(codegener(), number, 10);
	strcat_s(code, number);
	strcpy_s(accesmain.code, code);
	strcpy_s(additional.code, code);
	cout << "Enter model: ";
	cin.getline(accesmain.model, 100);
	strcheck(accesmain.model, 14);
	correct(accesmain.model);
	cout << "Enter type: ";
	cin.getline(additional.type, 100);
	strcheck(additional.type, 14);
	correct(accesmain.model);
	cout << "Enter compatibility: ";
	cin.getline(additional.comp, 100);
	strcheck(additional.comp, 50);
	correct(additional.comp);
	cout << "Enter price(euro): ";
	cin >> accesmain.price;
	accesmain.price = floatcheck(accesmain.price);
	cout << "Enter amount of accessories on storage: ";
	cin >> accesmain.count;
	accesmain.count = intcheck(accesmain.count);
	ofstream ofile;
	ofile.open("maininfo.dat", ios::binary | ios::app);
	ofile.write((char*)&accesmain, sizeof(maininfo));
	ofile.close();
	ofstream ofile2;
	ofile2.open("acces.dat", ios::binary | ios::app);
	ofile2.write((char*)&additional, sizeof(acces));
	ofile2.close();
	system("CLS");
	cout << "Done..." << endl;
	Sleep(1000);
	restart();
}

void printall() {
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *print = new maininfo[size];
		ifile.read((char*)print, size * sizeof(maininfo));
		ifile.close();
		for (int i = 0; i < 51; i++)
			cout << "-";
		cout << endl;
		cout << setw(7) << "    CODE|";
		cout << setw(15) << "            MODEL| ";
		cout << setw(10) << " PRICE(EURO)| ";
		cout << setw(7) << "  AMOUNT|" << endl;
		for (int i = 0; i < 51; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(7) << print[i].code << " | ";
			cout << setw(15) << print[i].model << " | ";
			cout << setw(11) << print[i].price << " | ";
			cout << setw(7) << print[i].count << " |" << endl;
		}
		for (int i = 0; i < 51; i++)
			cout << "-";
		cout << endl;
		delete[]print;
	}
	system("PAUSE");
	restart();
}

void printmoto() {
	ifstream ifile;
	ifile.open("moto.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(moto);
		moto *print = new moto[size];
		ifile.read((char*)print, size * sizeof(moto));
		ifile.close();
		for (int i = 0; i < 98; i++)
			cout << "-";
		cout << endl;
		cout << "    CODE|";
		cout << "          SERIES|";
		cout << " VOLUME(CM3)|";
		cout << " HIGH(CM)|";
		cout << " MASS(KG)|";
		cout << " FUELRATE(L/100KM)|";
		cout << " TORQUE(NM)|";
		cout << "   YEAR|";
		cout << endl;
		for (int i = 0; i < 98; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(7) << print[i].code << " | ";
			cout << setw(15) << print[i].lot << "| ";
			cout << setw(11) << print[i].volume << "| ";
			cout << setw(8) << print[i].high << "| ";
			cout << setw(8) << print[i].mass << "| ";
			cout << setw(17) << print[i].fuelrate << "| ";
			cout << setw(10) << print[i].torque << "| ";
			cout << setw(6) << print[i].year << "|";
			cout << endl;
		}
		for (int i = 0; i < 98; i++)
			cout << "-";
		cout << endl;
		delete[]print;
	}
	system("PAUSE");
	restart();
}

void printequip() {
	ifstream ifile;
	ifile.open("equip.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(equip);
		equip *print = new equip[size];
		ifile.read((char*)print, size * sizeof(equip));
		ifile.close();
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		cout << "    CODE|";
		cout << "             TYPE|";
		cout << "      SIZE|";
		cout << "                  MATERIAL|" << endl;
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(7) << print[i].code << " | ";
			cout << setw(15) << print[i].type << " | ";
			cout << setw(8) << print[i].size << " | ";
			cout << setw(24) << print[i].material << " | ";
			cout << endl;
		}
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		delete[]print;
	}
	system("PAUSE");
	restart();
}

void printacces() {
	ifstream ifile;
	ifile.open("acces.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(acces);
		acces *print = new acces[size];
		ifile.read((char*)print, size * sizeof(acces));
		ifile.close();
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		cout << "    CODE|";
		cout << "             TYPE|";
		cout << "                                       COMPATIBILITY|" << endl;
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(7) << print[i].code << " | ";
			cout << setw(15) << print[i].type << " | ";
			cout << setw(50) << print[i].comp << " | ";
			cout << endl;
		}
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		delete[]print;
	}
	system("PAUSE");
	restart();
}

void deleteinformation() {
	superignore();
	system("CLS");
	char code[100];
	cout << "DELETE INFORMATION" << endl;
	cout << "Enter product code(If you changed your mind enter word 'BACK'): ";
	cin >> code;
	char returnback[5] = {"BACK"};
	if (strcmp(returnback, code) != 0)
	{
	while (strlen(code) > 5) {
		cout << "Your code is too long, please, repeat: ";
		cin >> code;
	}
	code[0] = toupper(code[0]);
	int miss = 0;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *deleteinfo = new maininfo[size];
		ifile.read((char*)deleteinfo, size * sizeof(maininfo));
		ifile.close();
		ofstream ofile;
		ofile.open("maininfo.dat", ios::binary);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(code, deleteinfo[i].code) != 0)
				ofile.write((char*)&deleteinfo[i], sizeof(maininfo));
			else
				miss++;
		}
		ofile.close();
		delete[]deleteinfo;
	}
	if (code[0] == 'M') {
		ifstream ifile2;
		ifile2.open("moto.dat", ios::binary);
		if (!ifile)
			cout << "Error!";
		else
		{
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(moto);
			moto *deleteinfo = new moto[size];
			ifile2.read((char*)deleteinfo, size * sizeof(moto));
			ifile2.close();
			ofstream ofile;
			ofile.open("moto.dat", ios::binary);
			for (int i = 0; i < size; i++)
			{
				if (strcmp(code, deleteinfo[i].code) != 0)
					ofile.write((char*)&deleteinfo[i], sizeof(moto));
				else
					miss++;
			}
			ofile.close();
			delete[]deleteinfo;
		}
	}
	else {
		if (code[0] == 'E') {
			ifstream ifile2;
			ifile2.open("equip.dat", ios::binary);
			if (!ifile2)
				cout << "Error!";
			else
			{
				ifile2.seekg(0, ios::end);
				int size = ifile2.tellg();
				ifile2.seekg(0, ios::beg);
				size = size / sizeof(equip);
				equip *deleteinfo = new equip[size];
				ifile2.read((char*)deleteinfo, size * sizeof(equip));
				ifile2.close();
				ofstream ofile2;
				ofile2.open("equip.dat", ios::binary);
				for (int i = 0; i < size; i++)
				{
					if (strcmp(code, deleteinfo[i].code) != 0)
						ofile2.write((char*)&deleteinfo[i], sizeof(equip));
					else
						miss++;
				}
				ofile2.close();
				delete[]deleteinfo;
			}
		}
		else {
			if (code[0] == 'A') {
				ifstream ifile2;
				ifile2.open("acces.dat", ios::binary);
				if (!ifile2)
					cout << "Error!" << endl;
				else
				{
					ifile2.seekg(0, ios::end);
					int size = ifile2.tellg();
					ifile2.seekg(0, ios::beg);
					size = size / sizeof(acces);
					acces *deleteinfo = new acces[size];
					ifile2.read((char*)deleteinfo, size * sizeof(acces));
					ifile2.close();
					ofstream ofile2;
					ofile2.open("acces.dat", ios::binary);
					for (int i = 0; i < size; i++)
					{
						if (strcmp(code, deleteinfo[i].code) != 0)
							ofile2.write((char*)&deleteinfo[i], sizeof(acces));
						else
							miss++;
					}
					ofile2.close();
					delete[]deleteinfo;
				}
			}
			else
			{
				cout << "Incorrect code" << endl;
				system("PAUSE");
				restart();
			}
		}
	}
	if (miss == 0)
		cout << "Product not found" << endl;
	else
		cout << "Done..." << endl;
	}
	system("PAUSE");
	restart();
}

void sortseries() {
	ifstream ifile;
	ifile.open("moto.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
	ifile.seekg(0, ios::end);
	int size = ifile.tellg();
	ifile.seekg(0, ios::beg);
	size = size/sizeof(moto);
	moto *sort = new moto[size];
	ifile.read((char*)sort, size * sizeof(moto));
	ifile.close();
	int miss = 1;
	while (miss != 0) {
		miss = 0;
		moto copy;
		copy = sort[0];
		for (int i = 0; i < size-1; i++) {
			if (strcmp(sort[i].lot, sort[i+1].lot) < 0)
			{
				copy = sort[i];
				sort[i] = sort[i + 1];
				sort[i + 1] = copy;
				miss++;
			}
		}
	}
	for (int i = 0; i < 82; i++)
		cout << "-";
	cout << endl;
	cout << "         SERIES|";
	cout << "     CODE|";
	cout << "    VOLUME|";
	cout << "   HIGH|";
	cout << "    MASS|";
	cout << "  FUELRATE|";
	cout << "  TORQUE|";
	cout << "   YEAR|";
	cout << endl;
	for (int i = 0; i < 82; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(15) << sort[i].lot << "| ";
		cout << setw(7) << sort[i].code << " | ";
		cout << setw(9) << sort[i].volume << "| ";
		cout << setw(6) << sort[i].high << "| ";
		cout << setw(7) << sort[i].mass << "| ";
		cout << setw(9) << sort[i].fuelrate << "| ";
		cout << setw(7) << sort[i].torque << "| ";
		cout << setw(6) << sort[i].year << "|" << endl;
	}
	for (int i = 0; i < 82; i++)
		cout << "-";
	cout << endl;
	delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sortpricemoto() {
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *sort = new maininfo[size];
		ifile.read((char*)sort, size * sizeof(maininfo));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			maininfo copy;
			copy = sort[0];
			for (int i = 0; i < size-1; i++) {
				if (sort[i].price<sort[i+1].price)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		cout << setw(10) << "      PRICE| ";
		cout << setw(7) << "    CODE|";
		cout << setw(15) << "            MODEL| ";
		cout << setw(7) << "  AMOUNT|" << endl;
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			if (sort[i].code[0] == 'M') {
			cout << setw(10) << sort[i].price << " | ";
			cout << setw(7) << sort[i].code << " | ";
			cout << setw(15) << sort[i].model << " | ";
			cout << setw(7) << sort[i].count << " |";
			cout << endl;
			}
		}
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sortyear() {
	ifstream ifile;
	ifile.open("moto.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(moto);
		moto *sort = new moto[size];
		ifile.read((char*)sort, size * sizeof(moto));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			moto copy;
			copy = sort[0];
			for (int i = 0; i < size - 1; i++) {
				if (sort[i].year < sort[i + 1].year)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		cout << "  YEAR|";
		cout << "   CODE|";
		cout << "          SERIES|";
		cout << "    VOLUME|";
		cout << "   HIGH|";
		cout << "    MASS|";
		cout << "  FUELRATE|";
		cout << "  TORQUE|";
		cout << endl;
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(6) << sort[i].year << "|";
			cout << setw(7) << sort[i].code << "| ";
			cout << setw(15) << sort[i].lot << "| ";
			cout << setw(9) << sort[i].volume << "| ";
			cout << setw(6) << sort[i].high << "| ";
			cout << setw(7) << sort[i].mass << "| ";
			cout << setw(9) << sort[i].fuelrate << "| ";
			cout << setw(7) << sort[i].torque << "| ";
			cout << endl;
		}
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sorttypeequip() {
	ifstream ifile;
	ifile.open("equip.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(equip);
		equip *sort = new equip[size];
		ifile.read((char*)sort, size * sizeof(equip));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			equip copy;
			copy = sort[0];
			for (int i = 0; i < size - 1; i++) {
				if (strcmp(sort[i].type, sort[i + 1].type) < 0)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		cout << "            TYPE|";
		cout << "     CODE|";
		cout << "      SIZE|";
		cout << "                  MATERIAL|" << endl;
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(15) << sort[i].type << " | ";
			cout << setw(7) << sort[i].code << " | ";
			cout << setw(8) << sort[i].size << " | ";
			cout << setw(24) << sort[i].material << " | " << endl;
		}
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sortpriceequip() {
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *sort = new maininfo[size];
		ifile.read((char*)sort, size * sizeof(maininfo));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			maininfo copy;
			copy = sort[0];
			for (int i = 0; i < size - 1; i++) {
				if (sort[i].price < sort[i + 1].price)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		cout << setw(10) << "      PRICE| ";
		cout << setw(7) << "    CODE|";
		cout << setw(15) << "            MODEL| ";
		cout << setw(7) << "  AMOUNT|" << endl;
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			if (sort[i].code[0] == 'E') {
				cout << setw(10) << sort[i].price << " | ";
				cout << setw(7) << sort[i].code << " | ";
				cout << setw(15) << sort[i].model << " | ";
				cout << setw(7) << sort[i].count << " | ";
				cout << endl;
			}
		}
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sortsize() {
	ifstream ifile;
	ifile.open("equip.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(equip);
		equip *sort = new equip[size];
		ifile.read((char*)sort, size * sizeof(equip));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			equip copy;
			copy = sort[0];
			for (int i = 0; i < size - 1; i++) {
				if (strcmp(sort[i].size, sort[i + 1].size) < 0)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		cout << "      SIZE|";
		cout << "    CODE|";
		cout << "             TYPE|";
		cout << "                  MATERIAL|" << endl;
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(8) << sort[i].size << " | ";
			cout << setw(7) << sort[i].code << " | ";
			cout << setw(15) << sort[i].type << " | ";
			cout << setw(24) << sort[i].material << " | " << endl;
		}
		for (int i = 0; i < 65; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sorttypeacces() {
	ifstream ifile;
	ifile.open("acces.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(acces);
		acces *sort = new acces[size];
		ifile.read((char*)sort, size * sizeof(acces));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			acces copy;
			copy = sort[0];
			for (int i = 0; i < size - 1; i++) {
				if (strcmp(sort[i].type, sort[i + 1].type) < 0)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		cout << "             TYPE|";
		cout << "    CODE|";
		cout << "                                       COMPATIBILITY|" << endl;
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << setw(15) << sort[i].type << " | ";
			cout << setw(7) << sort[i].code << " | ";
			cout << setw(50) << sort[i].comp << " |" << endl;
		}
		for (int i = 0; i < 80; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void sortpriceacces() {
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *sort = new maininfo[size];
		ifile.read((char*)sort, size * sizeof(maininfo));
		ifile.close();
		int miss = 1;
		while (miss != 0) {
			miss = 0;
			maininfo copy;
			copy = sort[0];
			for (int i = 0; i < size - 1; i++) {
				if (sort[i].price < sort[i + 1].price)
				{
					copy = sort[i];
					sort[i] = sort[i + 1];
					sort[i + 1] = copy;
					miss++;
				}
			}
		}
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		cout << setw(10) << "      PRICE| ";
		cout << setw(7) << "    CODE|";
		cout << setw(15) << "            MODEL| ";
		cout << setw(7) << "  AMOUNT|" << endl;
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			if (sort[i].code[0] == 'A') {
				cout << setw(10) << sort[i].price << " | ";
				cout << setw(7) << sort[i].code << " | ";
				cout << setw(15) << sort[i].model << " | ";
				cout << setw(7) << sort[i].count << " | ";
				cout << endl;
			}
		}
		for (int i = 0; i < 50; i++)
			cout << "-";
		cout << endl;
		delete[]sort;
	}
	system("PAUSE");
	restart();
}

void searchbycode() {
	superignore();
	system("CLS");
	cout << "Enter product code: ";
	char code[100];
	cin >> code;
	while (strlen(code) > 6) {
		cout << "Your code is too long, please, repeat: ";
		cin >> code;
	}
	code[0] = toupper(code[0]);
	maininfo *search1;
	int mainsize;
	int goal = 0;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();
		if (code[0] == 'M') {
			ifstream ifile;
			ifile.open("moto.dat", ios::binary);
			if (!ifile)
				cout << "Error!" << endl;
			else {
				ifile.seekg(0, ios::end);
				int size = ifile.tellg();
				ifile.seekg(0, ios::beg);
				size = size / sizeof(moto);
				moto *search2 = new moto[size];
				ifile.read((char*)search2, size * sizeof(moto));
				ifile.close();
				for (int i = 0; i < mainsize; i++)
				{
					if (strcmp(code, search1[i].code) == 0)
					{
						cout << "\tMotorcycle model: " << search1[i].model << endl;
						cout << "\tMotorcycle price: " << search1[i].price << endl;
						cout << "\tCount of motorcycle on storage: " << search1[i].count << endl;
						goal++;
					}
				}
				for (int i = 0; i < size; i++)
				{
					if (strcmp(code, search2[i].code) == 0)
					{
						cout << "\tMotorcycle series: " << search2[i].lot << endl;
						cout << "\tEngine volume: " << search2[i].volume << endl;
						cout << "\tMotorcycle seat high: " << search2[i].high << endl;
						cout << "\tMotorcycle mass: " << search2[i].mass << endl;
						cout << "\tMotorcycle torque: " << search2[i].torque << endl;
						cout << "\tMotorcycle fuelrate: " << search2[i].fuelrate << endl;
						cout << "\tYear of edition: " << search2[i].year << endl;
					}
				}
				delete[]search1;
				delete[]search2;
			}
		}
		else
			if (code[0] == 'E')
			{
				ifstream ifile;
				ifile.open("equip.dat", ios::binary);
				if (!ifile)
					cout << "Error!" << endl;
				else {
					ifile.seekg(0, ios::end);
					int size = ifile.tellg();
					ifile.seekg(0, ios::beg);
					size = size / sizeof(equip);
					equip *search2 = new equip[size];
					ifile.read((char*)search2, size * sizeof(equip));
					ifile.close();
					for (int i = 0; i < mainsize; i++)
					{
						if (strcmp(code, search1[i].code) == 0)
						{
							cout << "\tEquipment model: " << search1[i].model << endl;
							cout << "\tEquipment price: " << search1[i].price << endl;
							cout << "\tCount of equipment on storage: " << search1[i].count << endl;
							goal++;
						}
					}
					for (int i = 0; i < size; i++)
					{
						if (strcmp(code, search2[i].code) == 0)
						{
							cout << "\tEquipment type: " << search2[i].type << endl;
							cout << "\tEquipment size: " << search2[i].size << endl;
							cout << "\tMaterial of equipment: " << search2[i].size << endl;
						}
					}
					delete[]search1;
					delete[]search2;
				}
			}
			else
				if (code[0] == 'A') {
					ifstream ifile;
					ifile.open("acces.dat", ios::binary);
					if (!ifile)
						cout << "Error!" << endl;
					else {
						ifile.seekg(0, ios::end);
						int size = ifile.tellg();
						ifile.seekg(0, ios::beg);
						size = size / sizeof(acces);
						acces *search2 = new acces[size];
						ifile.read((char*)search2, size * sizeof(acces));
						ifile.close();
						for (int i = 0; i < mainsize; i++)
						{
							if (strcmp(code, search1[i].code) == 0)
							{
								cout << "\tAccessory model: " << search1[i].model << endl;
								cout << "\tAccessory price: " << search1[i].price << endl;
								cout << "\tCount of accessorry on storage: " << search1[i].count << endl;
								goal++;
							}
						}
						for (int i = 0; i < size; i++)
						{
							if (strcmp(code, search2[i].code) == 0)
							{
								cout << "\tAccessory type: " << search2[i].type << endl;
								cout << "\tAccesorry compatibility: " << search2[i].comp << endl;

							}
						}
						delete[]search1;
						delete[]search2;
					}
				}
				else
					cout << "Incorrect code type!" << endl;
	}
	if (goal == 0)
		cout << "Product not found..." << endl;
	system("PAUSE");
	restart();
}

void searchbymodelmoto() {
	superignore();
	system("CLS");
	cout << "Enter full name of motorcycle model: ";
	char model[15];
	char code[6];
	int goal = 0;
	cin.getline(model, 100);
	strcheck(model, 15);
	correct(model);
	maininfo *search1;
	int mainsize;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();
		ifstream ifile2;
		ifile2.open("moto.dat", ios::binary);
		if (!ifile)
			cout << "Error!" << endl;
		else {
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(moto);
			moto *search2 = new moto[size];
			ifile2.read((char*)search2, size * sizeof(moto));
			ifile2.close();
			for (int i = 0; i < mainsize; i++)
			{
				if (strcmp(model, search1[i].model) == 0)
				{
					cout << "\tMotorcycle model: " << search1[i].model << endl;
					cout << "\tMotorcycle price: " << search1[i].price << endl;
					cout << "\tCount of motorcycle on storage: " << search1[i].count << endl;
					strcpy_s(code, search1[i].code);
					goal++;
				}

				for (int i = 0; i < size; i++)
				{
					if (strcmp(code, search2[i].code) == 0)
					{
						cout << "\tMotorcycle series: " << search2[i].lot << endl;
						cout << "\tEngine volume: " << search2[i].volume << endl;
						cout << "\tMotorcycle seat high: " << search2[i].high << endl;
						cout << "\tMotorcycle mass: " << search2[i].mass << endl;
						cout << "\tMotorcycle torque: " << search2[i].torque << endl;
						cout << "\tMotorcycle fuelrate: " << search2[i].fuelrate << endl;
						cout << "\tYear of edition: " << search2[i].year << endl;
						cout << endl;
					}
				}
				strcpy_s(code, "00000");
			}
			delete[]search1;
			delete[]search2;
		}
	}
	if (goal == 0)
		cout << "Motorcycle is not found..." << endl;
	system("PAUSE");
	restart();
}

void searchbyengine() {
	superignore();
	system("CLS");
	cout << "Enter engine volume: ";
	int volume;
	char code[6];
	int goal = 0;
	cin >> volume;
	volume = intcheck(volume);
	maininfo *search1;
	int mainsize;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();
		ifstream ifile2;
		ifile2.open("moto.dat", ios::binary);
		if (!ifile)
			cout << "Error!" << endl;
		else {
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(moto);
			moto *search2 = new moto[size];
			ifile2.read((char*)search2, size * sizeof(moto));
			ifile2.close();
			for (int i = 0; i < size; i++)
			{
				if (volume == search2[i].volume)
				{
					strcpy_s(code, search2[i].code);
				}

				for (int i = 0; i < mainsize; i++)
					if (strcmp(code, search1[i].code) == 0)
					{
						cout << "\tMotorcycle model: " << search1[i].model << endl;
						cout << "\tMotorcycle price: " << search1[i].price << endl;
						cout << "\tCount of motorcycle on storage: " << search1[i].count << endl;
						goal++;
					}

				for (int i = 0; i < size; i++)
				{
					if (strcmp(code, search1[i].code) == 0)
					{
						cout << "\tMotorcycle series: " << search2[i].lot << endl;
						cout << "\tEngine volume: " << search2[i].volume << endl;
						cout << "\tMotorcycle seat high: " << search2[i].high << endl;
						cout << "\tMotorcycle mass: " << search2[i].mass << endl;
						cout << "\tMotorcycle torque: " << search2[i].torque << endl;
						cout << "\tMotorcycle fuelrate: " << search2[i].fuelrate << endl;
						cout << "\tYear of edition: " << search2[i].year << endl;
						cout << endl;
					}
				}
				strcpy_s(code, "00000");
			}
			delete[]search1;
			delete[]search2;
		}
	}
	if (goal == 0)
		cout << "Motorcycle is not found" << endl;
	system("PAUSE");
	restart();
}

void searchbymodelequip() {
	superignore();
	system("CLS");
	cout << "Enter full name of equipment model: ";
	char model[15];
	char code[6];
	int goal = 0;
	cin.getline(model, 100);
	strcheck(model, 15);
	correct(model);
	maininfo *search1;
	int mainsize;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();
		ifstream ifile2;
		ifile2.open("equip.dat", ios::binary);
		if (!ifile)
			cout << "Error!" << endl;
		else {
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(equip);
			equip *search2 = new equip[size];
			ifile2.read((char*)search2, size * sizeof(equip));
			ifile2.close();
			for (int i = 0; i < mainsize; i++)
			{
				if (strcmp(model, search1[i].model) == 0)
				{
					cout << "\tEquipment model: " << search1[i].model << endl;
					cout << "\tEquipment price: " << search1[i].price << endl;
					cout << "\tCount of equipment on storage: " << search1[i].count << endl;
					strcpy_s(code, search1[i].code);
					goal++;
				}

				for (int i = 0; i < size; i++)
				{
					if (strcmp(code, search2[i].code) == 0)
					{
						cout << "\tEquipment type: " << search2[i].type << endl;
						cout << "\tEquipment size: " << search2[i].size << endl;
						cout << "\tMaterial of equipment: " << search2[i].size << endl;
						cout << endl;
					}
				}
				strcpy_s(code, "00000");
			}
			delete[]search1;
			delete[]search2;
		}
	}
	if (goal == 0)
		cout << "Equipment is not found" << endl;
	system("PAUSE");
	restart();
}

void searchbymakeup() {
	superignore();
	system("CLS");
	cout << "Enter equipment material: ";
	char material[25];
	char code[6];
	int goal = 0;
	cin.getline(material, 100);
	strcheck(material, 25);
	correct(material);
	maininfo *search1;
	int mainsize;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();

		ifstream ifile2;
		ifile2.open("equip.dat", ios::binary);
		if (!ifile)
			cout << "Database is empty" << endl;
		else {
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(equip);
			equip *search2 = new equip[size];
			ifile2.read((char*)search2, size * sizeof(equip));
			ifile2.close();
			for (int i = 0; i < mainsize; i++)
			{
				for (int j = 0; j < strlen(search2[i].material); j++)
				{
					int miss = 1;
					if (material[0] == search2[i].material[j])
					{
						miss = 0;
						for (int l = 0; l < strlen(material); l++)
						{
							if (material[l] != search2[i].material[j + l])
								miss++;
						}
					}
					if (miss == 0)
						strcpy_s(code, search2[i].code);
				}
				for (int p = 0; p < mainsize; p++)
				{
					if (strcmp(code, search1[p].code) == 0)
						{
							cout << "\tEquipment model: " << search1[p].model << endl;
							cout << "\tEquipment price: " << search1[p].price << endl;
							cout << "\tCount of equipment on storage: " << search1[p].count << endl;
							goal++;
						}
				}
				for (int o = 0; o < size; o++)
				{
					if (strcmp(code, search2[o].code) == 0)
					{
						cout << "\tEquipment type: " << search2[o].type << endl;
						cout << "\tEquipment size: " << search2[o].size << endl;
						cout << "\tFull material of equipment: " << search2[o].material << endl;
						cout << endl;
					}
				}
				strcpy_s(code, "00000");
			}
			delete[]search1;
			delete[]search2;
		}
	}
	if (goal == 0)
		cout << "Equipment is not found" << endl;
	system("PAUSE");
	restart();
}

void searchbymodelacces() {
	superignore();
	system("CLS");
	cout << "Enter full name of accessory model: ";
	char model[15];
	char code[6];
	int goal = 0;
	cin.getline(model, 100);
	strcheck(model, 15);
	correct(model);
	maininfo *search1;
	int mainsize;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();
		ifstream ifile2;
		ifile2.open("acces.dat", ios::binary);
		if (!ifile)
			cout << "Error!" << endl;
		else {
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(acces);
			acces *search2 = new acces[size];
			ifile2.read((char*)search2, size * sizeof(acces));
			ifile2.close();
			for (int i = 0; i < mainsize; i++)
			{
				if (strcmp(model, search1[i].model) == 0)
				{
					cout << "\tAccessory model: " << search1[i].model << endl;
					cout << "\tAccessory price: " << search1[i].price << endl;
					cout << "\tCount of accessory on storage: " << search1[i].count << endl;
					strcpy_s(code, search1[i].code);
					goal++;
				}

				for (int i = 0; i < size; i++)
				{
					if (strcmp(code, search2[i].code) == 0)
					{
						cout << "\tAccessory type: " << search2[i].type << endl;
						cout << "\tAccessory compatibility: " << search2[i].comp << endl;
						cout << endl;
					}
				}
				strcpy_s(code, "00000");
			}
			delete[]search1;
			delete[]search2;
		}
		if (goal == 0)
			cout << "Accessory is not found" << endl;
		system("PAUSE");
		restart();
	}
}

void searchbycomp() {
	superignore();
	system("CLS");
	cout << "Enter motorcycle which your accessory need to be compitible: ";
	char comp[25];
	char code[6];
	cin.getline(comp, 100);
	strcheck(comp, 25);
	correct(comp);
	maininfo *search1;
	int goal = 0;
	int mainsize;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	if (!ifile)
		cout << "Database is empty" << endl;
	else {
		ifile.seekg(0, ios::end);
		mainsize = ifile.tellg();
		ifile.seekg(0, ios::beg);
		mainsize = mainsize / sizeof(maininfo);
		search1 = new maininfo[mainsize];
		ifile.read((char*)search1, mainsize * sizeof(maininfo));
		ifile.close();
		ifstream ifile2;
		ifile2.open("acces.dat", ios::binary);
		if (!ifile)
			cout << "Error!" << endl;
		else {
			ifile2.seekg(0, ios::end);
			int size = ifile2.tellg();
			ifile2.seekg(0, ios::beg);
			size = size / sizeof(acces);
			acces *search2 = new acces[size];
			ifile2.read((char*)search2, size * sizeof(acces));
			ifile2.close();
			for (int i = 0; i < mainsize; i++)
			{
				for (int j = 0; j < strlen(search2[i].comp); j++)
				{
					int miss = 1;
					if (comp[0] == search2[i].comp[j])
					{
						miss = 0;
						for (int l = 0; l < strlen(comp); l++)
						{
							if (comp[l] != search2[i].comp[j + l])
								miss++;
						}
					}
					if (miss == 0)
						strcpy_s(code, search2[i].code);
				}
				for (int p = 0; p < mainsize; p++) {
					if (strcmp(code, search1[p].code) == 0)
						{
							cout << "\tAccessory model: " << search1[p].model << endl;
							cout << "\tAccessory price: " << search1[p].price << endl;
							cout << "\tCount of equipment on storage: " << search1[p].count << endl;
							goal++;
						}
				}

				for (int o = 0; o < size; o++)
				{
					if (strcmp(code, search2[o].code) == 0)
					{
						cout << "\tAccessory type: " << search2[o].type << endl;
						cout << "\tFull accessory compatibility: " << search2[o].comp << endl;
						cout << endl;
					}
				}
				strcpy_s(code, "00000");
			}
			delete[]search1;
			delete[]search2;
		}
	}
	if (goal == 0)
		cout << "Accessory is not found" << endl;
		system("PAUSE");
		restart();
}

void showcountmoto() {
	cout << endl;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	int count = 0;
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *show = new maininfo[size];
		ifile.read((char*)show, size * sizeof(maininfo));
		for (int i = 0; i < size; i++)
		{
			if (show[i].code[0] == 'M')
				count = count + show[i].count;
		}
		cout << "Amount of motorcycles on storage is: " << count << endl;
	}
	system("PAUSE");
	restart();
}

void showcountequip() {
	cout << endl;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	int count = 0;
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *show = new maininfo[size];
		ifile.read((char*)show, size * sizeof(maininfo));
		for (int i = 0; i < size; i++)
		{
			if (show[i].code[0] == 'E')
				count = count + show[i].count;
		}
		cout << "Amount of equipment on storage is: " << count << endl;
	}
	system("PAUSE");
	restart();
}

void showcountacces() {
	cout << endl;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	int count = 0;
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *show = new maininfo[size];
		ifile.read((char*)show, size * sizeof(maininfo));
		for (int i = 0; i < size; i++)
		{
			if (show[i].code[0] == 'A')
				count = count + show[i].count;
		}
		cout << "Amount of accessories on storage is: " << count << endl;
	}
	system("PAUSE");
	restart();
}

void showcost() {
	cout << endl;
	ifstream ifile;
	ifile.open("maininfo.dat", ios::binary);
	int cost = 0;
	if (!ifile)
		cout << "Database is empty" << endl;
	else
	{
		ifile.seekg(0, ios::end);
		int size = ifile.tellg();
		ifile.seekg(0, ios::beg);
		size = size / sizeof(maininfo);
		maininfo *show = new maininfo[size];
		ifile.read((char*)show, size * sizeof(maininfo));
		for (int i = 0; i < size; i++)
		{
			cost = cost + show[i].price*show[i].count;
		}
		cout << "Total cost of products on storage is: " << cost << " Euro" << endl;
	}
	system("PAUSE");
	restart();
}

int intcheck(int n) {
	while (cin.fail()) {
		cout << "It ins't a number! Repeat, please: ";
		cin.clear();
		while (cin.get() != '\n');
		cin >> n;
	}
	return n;
}

float floatcheck(float n) {
	while (cin.fail()) {
		cout << "It isn't a number! Repeat, please: ";
		cin.clear();
		while (cin.get() != '\n');
		cin >> n;
	}
	return n;
}

void strcheck(char *s, int n) {
	while (strlen(s) > n) {
		cout << "Too many symbols, please repeat: ";
		cin.getline(s, 100);
}
}

void correct(char *s) {
	s[0] = toupper(s[0]);
	for (int i = 1; i < strlen(s); i++)
		if (isspace(s[i - 1]) || ispunct(s[i - 1]))
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
}
