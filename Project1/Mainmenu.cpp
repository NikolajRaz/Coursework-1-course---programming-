#pragma once
#include"harley.h"
#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

//void colormenu(string *Menu, int n, int pointer);

int main() {
	clickrefresh();
	string Menu[8] = { "1.ADD NEW INFORMATION", "2.PRINT INFORMATION", "3.DELETE INFORMATION", "4.SORT INFORMATION", "5.SEARCH", "6.SHOW SUMMARY INFORMATION", "7.PROGRAMM DISCRIPTION", "8.EXIT\n" };
	int pointer=0;
	while(true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		system("CLS");
		cout << "----    ----      ----      ------------  ----          ------------  ----    ----" << endl;
		cout << "----    ----     ------     ------------  ----          ------------  -----  -----" << endl;
		cout << "----    ----    --    --    ----    ----  ----          ----           ---------- " << endl;
		cout << "------------   ----------   ------------  ----          ------------    --------  " << endl;
		cout << "------------  ------------  ------------  ----          ------------     ------   " << endl;
		cout << "----    ----  ----    ----  ----  ----    ----          ----             ------   " << endl;
		cout << "----    ----  ----    ----  ----   ----   ------------  ------------     ------   " << endl;
		cout << "----    ----  ----    ----  ----    ----  ------------  ------------     ------   " << endl;
		cout << endl;
		cout << "----------        ----      --        --  ----  ----------    ------------  ------------  ----     ---" << endl;
		cout << "-----------      ------     ---      ---  ----  -----------   ------------  ------------  -----    ---" << endl;
		cout << "----    ----    --    --    ----    ----  ----  ----    ----  ----          ----    ----  ------   ---" << endl;
		cout << "----    ----   ----------    ----  ----   ----  ----    ----  ------------  ----    ----  --- ---  ---" << endl;
		cout << "----    ----  ------------    --------    ----  ----    ----  ------------  ----    ----  ---  --- ---" << endl;
		cout << "----    ----  ----    ----     ------     ----  ----    ----          ----  ----    ----  ---   ------" << endl;
		cout << "-----------   ----    ----      ----      ----  -----------   ------------  ------------  ---    -----" << endl;
		cout << "----------    ----    ----       --       ----  ----------    ------------  ------------  ---     ----" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "MAIN MENU" << endl;
		colormenu(Menu, 8, pointer);
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer = scrolls_up(8, pointer);
				break;
			}
			else
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer = scrolls_down(8, pointer);
					break;
				}
				else
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (pointer)
						{
						case 0: Sleep(500); click(); mainadd(); break;
						case 1: Sleep(500); click(); mainprint(); break;
						case 2: Sleep(500); click(); deleteinformation(); break;
						case 3: Sleep(500); click(); mainsort(); break;
						case 4: Sleep(500); click(); mainsearch(); break;
						case 5: Sleep(500); click(); show(); break;
						case 6: Sleep(500); click(); system("CLS"); cout << "DISCRIPTION: " << endl;
							cout << "Welcome to Harley Davidson motor shop database! To navigate between menu options use up-scroll and down-scroll. " << endl << "To choose menu option press Enter. Please, don't press any other button's, before you need to. " << endl << "If you pressed, please, restart the program. While writing, please, do not use any other symbols, except latin." << endl;
							system("PAUSE"); restart(); break;
						case 7: system("CLS");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout << "Goodbye!" << endl;
							system("PAUSE");
							return 0; break;
						}
						break;
					}
		}
		Sleep(150);
	}
}