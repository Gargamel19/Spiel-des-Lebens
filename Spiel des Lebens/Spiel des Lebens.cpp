
#include "stdafx.h"
#include <Windows.h>
using namespace std;
#include <iostream>
using namespace std;
#include <string>
using namespace std;
#include <conio.h> 
using namespace std;

int spielfeldbauen();
int bildrechnen();
int auswahl();
int paint();
int random();
int checknachbarn();
int ng();
int blinker();
int kreis();
int pulsar();

string output;

int gen = 0;
int seed;
char auswahlchar;
int warscheinlichkeit = 6;

int x = 50, y = 50;

char spielfeld[50][50];

int zellelebendig[50][50];

int zellelebendigNG[50][50];

int zelletot[50][50];

int main()
{
	spielfeldbauen();

	paint();

	cout << "geben sie 'R' für Random ein" << endl; 
	cout << "geben sie 'B' für Blinker ein" << endl;
	cout << "geben sie 'K' für Kreis ein" << endl;
	cout << "geben sie 'P' für p ein" << endl;
	cin >> auswahlchar;
	

	auswahl();
	paint();

	while (true)
	{
		gen++;
		checknachbarn();
		ng();
		Sleep(100);
		paint();
		
		
		
	}
	

	int stop;
	cin >> stop;

	return 0;
}

int spielfeldbauen() {

	// anzeige: ist die zelle lebendig auf 0 gesetzt
	for (int i = 0; i < y-1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{

			spielfeld[j][i] = '0';

		}
	}
	//ist die zelle lebendig auf 0 gesetzt
	for (int i = 0; i < y - 1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{

			zellelebendig[j][i] = 0;

		}
	}
	//wird die zelle nächste Generation leben auf 0 gesetzt
	for (int i = 0; i < y - 1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{

			zellelebendigNG[j][i] = 0;

		}
	}
	//wird die zelle nächste Generation leben auf 0 gesetzt
	for (int i = 0; i < y - 1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{

			zelletot[j][i] = 0;

		}
	}
	return(0);
}

int bildrechnen() {

	for (int i = 0; i < y - 1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{

			if (spielfeld[i][j] == 'x')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				cout << spielfeld[i][j] << " ";
			}
			if (spielfeld[i][j] == '0')
			{
				if (zelletot[i][j] == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);
					cout << spielfeld[i][j] << " ";
				}
				else if (zelletot[i][j] == 0) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255);
					cout << spielfeld[i][j] << " ";

				}


			}

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout <<  "\n";



	}
	return(0);
}

int paint()
{

	system("cls");

	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Generation: " << gen << endl << endl << endl;

	bildrechnen();
	
	return(0);
}

int checknachbarn() {

	//line1[]
	for (int i = 0; i < x-1; i++)
	{
		int NGzähler = 0;
		if (spielfeld[i-1][0] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i + 1][0] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i - 1][1] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i][1] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i + 1][1] == 'x')
		{
			NGzähler++;
		}
		
		if (zellelebendig[i][0] == 1)
		{
			if (NGzähler == 2)
			{
				zellelebendigNG[i][0] = 1;
			}
			if (NGzähler == 3)
			{
				zellelebendigNG[i][0] = 1;
			}
			if (NGzähler > 3)
			{
				zellelebendigNG[i][0] = 0;
				zelletot[i][0] = 1;
			}
			if (NGzähler < 2)
			{
				zellelebendigNG[i][0] = 0;
				zelletot[i][0] = 1;
			}
		}
		if (zellelebendig[i][0] == 0)
		{
			if (NGzähler == 3)
			{
				zellelebendigNG[i][0] = 1;
			} else {
				zellelebendigNG[i][0] = 0;
			}
		}

	}

	
	//line2[1 - (y-1)]
	for (int i = 1; i < y-1; i++)
	{
		for (int j = 0; j < x-1; j++)
		{
			int NGzähler = 0;
			if (zellelebendig[j-1][i-1] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j][i - 1] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j + 1][i - 1] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j - 1][i] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j + 1][i] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j - 1][i + 1] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j][i + 1] == 1)
			{
				NGzähler++;
			}
			if (zellelebendig[j + 1][i + 1] == 1)
			{
				NGzähler++;
			}

			if (zellelebendig[j][i] == 1)
			{
				if (NGzähler == 2)
				{
					zellelebendigNG[j][i] = 1;
				}
				if (NGzähler == 3)
				{
					zellelebendigNG[j][i] = 1;
				}
				if (NGzähler > 3)
				{
					zellelebendigNG[j][i] = 0;
					zelletot[j][i] = 1;
				}
				if (NGzähler < 2)
				{
					zellelebendigNG[j][i] = 0;
					zelletot[j][i] = 1;
				}
			}
			if (zellelebendig[j][i] == 0)
			{
				if (NGzähler == 3)
				{
					zellelebendigNG[j][i] = 1;
				} else {
					zellelebendigNG[j][i] = 0;
				}
			}

		}
	}
	
	//line(y-1)[alle]
	for (int i = 0; i < x - 1; i++)
	{
		int NGzähler = 0;
		if (spielfeld[i - 1][y - 2] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i][y - 2] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i + 1][y - 2] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i - 1][y - 1] == 'x')
		{
			NGzähler++;
		}
		if (spielfeld[i + 1][y - 1] == 'x')
		{
			NGzähler++;
		}

		if (zellelebendig[i][y - 1] == 1)
		{
			if (NGzähler == 2)
			{
				zellelebendigNG[i][y - 1] = 1;
			}
			if (NGzähler == 3)
			{
				zellelebendigNG[i][y - 1] = 1;
			}
			if (NGzähler > 3)
			{
				zellelebendigNG[i][y - 1] = 0;
				zelletot[i][y - 1] = 1;
			}
			if (NGzähler < 2)
			{
				zellelebendigNG[i][y - 1] = 0;
				zelletot[i][y - 1] = 1;
			}
		}
		if (zellelebendig[i][y - 1] == 0)
		{
			if (NGzähler == 3)
			{
				zellelebendigNG[i][y - 1] = 1;
			}
			else {
				zellelebendigNG[i][y - 1] = 0;
			}
		}
	
	}
	return(0);
}

int ng() {

	for (int i = 0; i < y-1; i++)
	{
		for (int j = 0; j < x-1; j++)
			{
			if (zellelebendigNG[j][i] == 1)
			{
				spielfeld[j][i] = 'x';
				zellelebendig[j][i] = 1;
			}
			else if (zellelebendigNG[j][i] == 0)
			{
				spielfeld[j][i] = '0';
				zellelebendig[j][i] = 0;
			}
		}
		
		
			
	}
	
	return(0);

}

int auswahl() {

	if (auswahlchar == 'R')
	{
		random();
	}
	else if (auswahlchar == 'r')
	{
		random();
	}
	if (auswahlchar == 'B')
	{
		blinker();
	}
	else if (auswahlchar == 'b')
	{
		blinker();
	}
	if (auswahlchar == 'K')
	{
		kreis();
	}
	else if (auswahlchar == 'k')
	{
		kreis();
	}
	if (auswahlchar == 'P')
	{
		pulsar();
	}
	else if (auswahlchar == 'p')
	{
		pulsar();
	}
	return(0);
}

int random() {

	cout << "geben sie nun noch einen parameter ein, für die Random funktion" << endl;

	cin >> seed;


	int random;
	srand(seed);


	for (int i = 0; i < x-1; i++)
	{
		for (int j = 0; j < y-1; j++)
		{
			random = rand() % 10;

			if (random > warscheinlichkeit)
			{
				spielfeld[j][i] = 'x';
				zellelebendig[j][i] = 1;
			}
		}
	}
	
	return(0);
}

int blinker() {

	spielfeld[9][10] = 'x';
	spielfeld[9][9] = 'x';
	spielfeld[9][8] = 'x';

	zellelebendig[9][10] = 1;
	zellelebendig[9][9] = 1;
	zellelebendig[9][8] = 1;

	return(0);
}

int kreis() {

	spielfeld[9][9] = 'x';
	spielfeld[13][9] = 'x';
	spielfeld[11][7] = 'x';
	spielfeld[11][11] = 'x';

	spielfeld[10][8] = 'x';
	spielfeld[12][8] = 'x';
	spielfeld[10][10] = 'x';
	spielfeld[12][10] = 'x';

	zellelebendig[9][9] = 1;
	zellelebendig[13][9] = 1;
	zellelebendig[11][7] = 1;
	zellelebendig[11][11] = 1;

	zellelebendig[10][8] = 1;
	zellelebendig[12][8] = 1;
	zellelebendig[10][10] = 1;
	zellelebendig[12][10] = 1;

	return(0);
}
int pulsar() {

	spielfeld[6][9] = 'x';
	spielfeld[7][9] = 'x';
	spielfeld[8][9] = 'x';
	spielfeld[12][9] = 'x';
	spielfeld[13][9] = 'x';
	spielfeld[14][9] = 'x';

	spielfeld[6][11] = 'x';
	spielfeld[7][11] = 'x';
	spielfeld[8][11] = 'x';
	spielfeld[12][11] = 'x';
	spielfeld[13][11] = 'x';
	spielfeld[14][11] = 'x';

	spielfeld[6][4] = 'x';
	spielfeld[7][4] = 'x';
	spielfeld[8][4] = 'x';
	spielfeld[12][4] = 'x';
	spielfeld[13][4] = 'x';
	spielfeld[14][4] = 'x';

	spielfeld[6][16] = 'x';
	spielfeld[7][16] = 'x';
	spielfeld[8][16] = 'x';
	spielfeld[12][16] = 'x';
	spielfeld[13][16] = 'x';
	spielfeld[14][16] = 'x';


	spielfeld[9][6] = 'x';
	spielfeld[9][7] = 'x';
	spielfeld[9][8] = 'x';
	spielfeld[9][12] = 'x';
	spielfeld[9][13] = 'x';
	spielfeld[9][14] = 'x';

	spielfeld[11][6] = 'x';
	spielfeld[11][7] = 'x';
	spielfeld[11][8] = 'x';
	spielfeld[11][12] = 'x';
	spielfeld[11][13] = 'x';
	spielfeld[11][14] = 'x';

	spielfeld[4][6] = 'x';
	spielfeld[4][7] = 'x';
	spielfeld[4][8] = 'x';
	spielfeld[4][12] = 'x';
	spielfeld[4][13] = 'x';
	spielfeld[4][14] = 'x';

	spielfeld[16][6] = 'x';
	spielfeld[16][7] = 'x';
	spielfeld[16][8] = 'x';
	spielfeld[16][12] = 'x';
	spielfeld[16][13] = 'x';
	spielfeld[16][14] = 'x';



	zellelebendig[6][9] = 1;
	zellelebendig[7][9] = 1;
	zellelebendig[8][9] = 1;
	zellelebendig[12][9] = 1;
	zellelebendig[13][9] = 1;
	zellelebendig[14][9] = 1;

	zellelebendig[6][11] = 1;
	zellelebendig[7][11] = 1;
	zellelebendig[8][11] = 1;
	zellelebendig[12][11] = 1;
	zellelebendig[13][11] = 1;
	zellelebendig[14][11] = 1;

	zellelebendig[6][4] = 1;
	zellelebendig[7][4] = 1;
	zellelebendig[8][4] = 1;
	zellelebendig[12][4] = 1;
	zellelebendig[13][4] = 1;
	zellelebendig[14][4] = 1;

	zellelebendig[6][16] = 1;
	zellelebendig[7][16] = 1;
	zellelebendig[8][16] = 1;
	zellelebendig[12][16] = 1;
	zellelebendig[13][16] = 1;
	zellelebendig[14][16] = 1;


	zellelebendig[9][6] = 1;
	zellelebendig[9][7] = 1;
	zellelebendig[9][8] = 1;
	zellelebendig[9][12] = 1;
	zellelebendig[9][13] = 1;
	zellelebendig[9][14] = 1;

	zellelebendig[11][6] = 1;
	zellelebendig[11][7] = 1;
	zellelebendig[11][8] = 1;
	zellelebendig[11][12] = 1;
	zellelebendig[11][13] = 1;
	zellelebendig[11][14] = 1;

	zellelebendig[4][6] = 1;
	zellelebendig[4][7] = 1;
	zellelebendig[4][8] = 1;
	zellelebendig[4][12] = 1;
	zellelebendig[4][13] = 1;
	zellelebendig[4][14] = 1;

	zellelebendig[16][6] = 1;
	zellelebendig[16][7] = 1;
	zellelebendig[16][8] = 1;
	zellelebendig[16][12] = 1;
	zellelebendig[16][13] = 1;
	zellelebendig[16][14] = 1;

	return(0);
}