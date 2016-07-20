
#include "stdafx.h"
#include <Windows.h>
using namespace std;
#include <iostream>
using namespace std;
#include <string>
using namespace std;
#include <conio.h> 
using namespace std;
#include <fstream>
using namespace std;
#include <sstream>


int spielfeldbauen();
int bildrechnen();
int paint();
int checknachbarn();
int ng();
int auswahl();
int random();
int blinker();
int kreis();
int pulsar();
int magneten();
int gun();
int auslesen();

string adresse;

int gen = 0;
int seed;
char auswahlchar;
int warscheinlichkeit = 6;

int x = 50, y = 50;
int k = (x / 2) - 21;

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
	cout << "geben sie 'P' für Pulsar ein" << endl;
	cout << "geben sie 'M' für Magneten ein" << endl;
	cout << "geben sie 'G' für Gun ein" << endl;
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
	else if (auswahlchar == 'B')
	{
		blinker();
	}
	else if (auswahlchar == 'b')
	{
		blinker();
	}
	else if (auswahlchar == 'K')
	{
		kreis();
	}
	else if (auswahlchar == 'k')
	{
		kreis();
	}
	else if (auswahlchar == 'P')
	{
		pulsar();
	}
	else if (auswahlchar == 'p')
	{
		pulsar();
	}
	else if (auswahlchar == 'M') {
		magneten();
	}
	else if (auswahlchar == 'm') {
		magneten();
	}
	else if (auswahlchar == 'G') {
		gun();
	}
	else if (auswahlchar == 'g') {
		gun();
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

	adresse = "C:\\Users\\Ferdinand\\Desktop\\SpieldesLebens\\blinker.txt";

	auslesen();

	return(0);
}

int kreis() {

	adresse = "C:\\Users\\Ferdinand\\Desktop\\SpieldesLebens\\kreis.txt";

	auslesen();

	return(0);
}

int pulsar() {

	adresse = "C:\\Users\\Ferdinand\\Desktop\\SpieldesLebens\\pulsar.txt";

	auslesen();

	return(0);
}

int magneten() {

	adresse = "C:\\Users\\Ferdinand\\Desktop\\SpieldesLebens\\magneten.txt";

	auslesen();

	return(0);
}

int gun() {

	adresse = "C:\\Users\\Ferdinand\\Desktop\\SpieldesLebens\\gun.txt";

	auslesen();

	return(0);
}

int auslesen() {

	ifstream namenliste(adresse, ios::in);

	string zeichenkette;

	int linienzähler = 0;

	

	while (getline(namenliste, zeichenkette))
	{

		int a[40];
		

		stringstream datenstrohm(zeichenkette);

		datenstrohm >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9] >> a[10] >> a[11] >> a[12] >> a[13] >> a[14] >> a[15] >> a[16] >> a[17] >> a[18] >> a[19] >> a[20] >> a[21] >> a[22] >> a[23] >> a[24] >> a[25] >> a[26] >> a[27] >> a[28] >> a[29] >> a[30] >> a[31] >> a[32] >> a[33] >> a[34] >> a[35] >> a[36] >> a[37] >> a[38] >> a[39];
		
		
		for (int i = 0; i < 40; i++)
		{
			if (a[i] == 1)
				{
					spielfeld[k + linienzähler][k + i] = 'x';
					zellelebendig[k + linienzähler][k + i] = 1;
				}
		}
		
		
		linienzähler++;
	}
	return(0);
}

//ende