#pragma once
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<string.h>

using namespace std;

struct maininfo {
	char code[6];
	char model[15];
	int count;
	float price;
};

struct moto {
	char code[6];
	char lot[15];
	int volume;
	float high;
	float mass;
	float torque; //krutjashij moment
	float fuelrate;
	int year;
};

struct equip {
	char code[6];
	char type[15];
	char size[8];
	char material[25];
};

struct acces {
	char code[6];
	char type[15];
	char comp[50];
};

void colormenu(string *Menu, int n, int pointer);
int scrolls_up(int n, int pointer);
int scrolls_down(int n, int pointer);
void mainadd();
void mainprint();
void mainsort();
void sortmoto();
void sortequip();
void sortacces();
void mainsearch();
void searchmoto();
void searchequip();
void searchacces();
void show();
void restart();
void click();
void clickrefresh();
void superignore();
int codegener();
void addmoto();
void addequip();
void addacces();
void printall();
void printmoto();
void printequip();
void printacces();
void deleteinformation();
void sortseries();
void sortpricemoto();
void sortyear();
void sorttypeequip();
void sortpriceequip();
void sortsize();
void sorttypeacces();
void sortpriceacces();
void searchbycode();
void searchbymodelmoto();
void searchbyengine();
void searchbymodelequip();
void searchbymakeup();
void searchbymodelacces();
void searchbycomp();
void showcountmoto();
void showcountequip();
void showcountacces();
void showcost();
int intcheck(int n);
float floatcheck(float n);
void strcheck(char *s, int n);
void correct(char *s);