#pragma once
#include"harley.h"
#include<iostream>
#include<string.h>
#include<string>
#include<windows.h>

void colormenu(string *Menu, int n, int pointer) {
	for (int i = 0; i < n; i++)
	{
		if (i == pointer)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
			cout << Menu[i] << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << Menu[i] << endl;
		}
	}
}

int scrolls_up(int n, int pointer) {
	pointer -= 1;
	if (pointer == -1)
	{
		pointer = n - 1;
	}
	return pointer;
}

int scrolls_down(int n, int pointer) {
	pointer += 1;
	if (pointer == n)
	{
		pointer = 0;
	}
	return pointer;
}

void mainadd() {
	string Menu[4] = { "1.MOTORCYCLES", "2.EQUIPMENT", "3.ACCESORRY", "4.RETURN TO MAIN MENU" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "ADD NEW INFORMATION ABOUT: " << endl;
		colormenu(Menu, 4, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(4, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(4, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); click(); addmoto(); Sleep(500); break;
						case 1: Sleep(500); click(); addequip(); Sleep(500); break;
						case 2: Sleep(500); click(); addacces(); Sleep(500); break;
						case 3: click(); return;  break;
						}
						break;
					}
		}
		Sleep(150);
	}
}

void mainprint() {
	string Menu[5] = { "1.PRINT ALL", "2.MOTORCYCLES", "3.EQUIPMENT", "4.ACCESORRY", "5.RETURN TO MAIN MENU" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "PRINT INFORMATION ABOUT: " << endl;
		colormenu(Menu, 5, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(5, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(5, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); click(); printall(); Sleep(500); break;
						case 1: Sleep(500); click(); printmoto(); Sleep(500); break;
						case 2: Sleep(500); click(); printequip(); Sleep(500); break;
						case 3: Sleep(500); click(); printacces(); Sleep(500); break;
						case 4: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}

void mainsort() {
	string Menu[4] = { "1.MOTORCYCLES", "2.EQUIPMENT", "3.ACCESORRY", "4.RETURN TO MAIN MENU" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SORT INFORMATION ABOUT: " << endl;
		colormenu(Menu, 4, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(4, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(4, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); sortmoto(); break;
						case 1: Sleep(500); sortequip(); break;
						case 2: Sleep(500); sortacces(); break;
						case 3: Sleep(500); click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}

void sortmoto() {
	string Menu[4] = { "1.SERIES", "2.PRICE", "3.YEAR OF COMPLETION", "4.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SORT BY: " << endl;
		colormenu(Menu, 4, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(4, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(4, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); sortseries(); Sleep(500); break;
						case 1: Sleep(500); sortpricemoto(); Sleep(500); break;
						case 2: Sleep(500); sortyear(); Sleep(500); break;
						case 3: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}

void sortequip() {
	string Menu[4] = {"1.TYPE", "2.PRICE", "3.SIZE", "4.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SORT BY: " << endl;
		colormenu(Menu, 4, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(4, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(4, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); sorttypeequip(); Sleep(500); break;
						case 1: Sleep(500); sortpriceequip(); Sleep(500); break;
						case 2: Sleep(500); sortsize(); Sleep(500); break;
						case 3: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}

void sortacces() {
	string Menu[3] = {"1.TYPE", "2.PRICE", "3.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SORT BY: " << endl;
		colormenu(Menu, 3, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(3, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(3, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); sorttypeacces(); Sleep(500); break;
						case 1: Sleep(500); sortpriceacces(); Sleep(500); break;
						case 2: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}
void mainsearch() {
	string Menu[5] = { "1.MOTORCYCLES", "2.EQUIPMENT", "3.ACCESORRY", "4.SEARCH BY CODE", "5.RETURN TO MAIN MENU" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SEARCH INFORMATION ABOUT: " << endl;
		colormenu(Menu, 5, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(5, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(5, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); click(); searchmoto(); break;
						case 1: Sleep(500); click(); searchequip(); break;
						case 2: Sleep(500); click(); searchacces(); break;
						case 3: Sleep(500); click(); searchbycode(); Sleep(500); break;
						case 4: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
Break:
	Sleep(500);
}

void searchmoto() {
	string Menu[3] = { "1.MODEL", "2.ENGINE VOLUME", "3.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SEARCH BY: " << endl;
		colormenu(Menu, 3, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(3, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(3, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); click(); searchbymodelmoto(); Sleep(500); break;
						case 1: Sleep(500); click(); searchbyengine(); Sleep(500); break;
						case 2: Sleep(500); click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
Break:
	Sleep(500);
}

void searchequip() {
	string Menu[3] = {"1.MODEL", "2.MAKEUP", "3.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SEARCH BY: " << endl;
		colormenu(Menu, 3, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(3, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(3, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); click(); searchbymodelequip(); Sleep(500); break;
						case 1: Sleep(500); click(); searchbymakeup(); Sleep(500); break;
						case 2: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
Break:
	Sleep(500);
}

void searchacces() {
	string Menu[3] = { "1.MODEL", "2.COMPATIBILITY", "3.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SEARCH BY: " << endl;
		colormenu(Menu, 3, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(3, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(3, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); click(); searchbymodelacces(); break;
						case 1: Sleep(500); click(); searchbycomp(); Sleep(500); break;
						case 2: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}

void show() {
	string Menu[5] = { "1.HOW MANY MOTORCYCLES ARE IN STORAGE", "2.HOW MANY EQUIPMENT ARE IN STORAGE", "3.HOW MANY ACCESSORIES ARE IN STORAGE", "4.TOTAL COST OF ALL PRODUCTS ON STORAGE", "5.RETURN" };
	int pointer = 0;
	while (true) {
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "SEARCH BY: " << endl;
		colormenu(Menu, 5, pointer);
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(5, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(5, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer) {
						case 0: Sleep(500); showcountmoto(); Sleep(500); break;
						case 1: Sleep(500); showcountequip(); Sleep(500); break;
						case 2: Sleep(500); showcountacces(); Sleep(500); break;
						case 3: Sleep(500); showcost(); Sleep(500); break;
						case 4: click(); return; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}