
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
int auslesen();

string adresse;

int gen = 0;
int seed;
char auswahlchar;
int warscheinlichkeit = 6;

int x = 50, y = 50;
int k = (x / 2) - 8;

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

int auslesen() {

	ifstream namenliste(adresse, ios::in);

	string zeichenkette;

	int linienzähler = 0;

	

	while (getline(namenliste, zeichenkette))
	{

		int a;
		int b;
		int c;
		int d;
		int e;
		int f;
		int g;
		int h;
		int i;
		int j;
		int l;
		int m;
		int n;
		int o;
		int p;

		stringstream datenstrohm(zeichenkette);

		datenstrohm >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> l >> m >> n >> o >> p;
		
		

		if (a == 1)
		{
			spielfeld[k][k + linienzähler] = 'x';
			zellelebendig[k][k + linienzähler] = 1;
		}
		if (b == 1)
		{
			spielfeld[k + 1][k + linienzähler] = 'x';
			zellelebendig[k + 1][k + linienzähler] = 1;
		}
		if (c == 1)
		{
			spielfeld[k + 2][k + linienzähler] = 'x';
			zellelebendig[k + 2][k + linienzähler] = 1;
		}
		if (d == 1)
		{
			spielfeld[k + 3][k + linienzähler] = 'x';
			zellelebendig[k + 3][k + linienzähler] = 1;
		}
		if (e == 1)
		{
			spielfeld[k + 4][k + linienzähler] = 'x';
			zellelebendig[k + 4][k + linienzähler] = 1;
		}
		if (f == 1)
		{
			spielfeld[k + 5][k + linienzähler] = 'x';
			zellelebendig[k + 5][k + linienzähler] = 1;
		}
		if (g == 1)
		{
			spielfeld[k + 6][k + linienzähler] = 'x';
			zellelebendig[k + 6][k + linienzähler] = 1;
		}
		if (h == 1)
		{
			spielfeld[k + 7][k + linienzähler] = 'x';
			zellelebendig[k + 7][k + linienzähler] = 1;
		}
		if (i == 1)
		{
			spielfeld[k + 8][k + linienzähler] = 'x';
			zellelebendig[k + 8][k + linienzähler] = 1;
		}
		if (j == 1)
		{
			spielfeld[k + 9][k + linienzähler] = 'x';
			zellelebendig[k + 9][k + linienzähler] = 1;
		}
		if (l == 1)
		{
			spielfeld[k + 10][k + linienzähler] = 'x';
			zellelebendig[k + 10][k + linienzähler] = 1;
		}
		if (m == 1)
		{
			spielfeld[k + 11][k + linienzähler] = 'x';
			zellelebendig[k + 11][k + linienzähler] = 1;
		}
		if (n == 1)
		{
			spielfeld[k + 12][k + linienzähler] = 'x';
			zellelebendig[k + 12][k + linienzähler] = 1;
		}
		if (o == 1)
		{
			spielfeld[k + 13][k + linienzähler] = 'x';
			zellelebendig[k + 13][k + linienzähler] = 1;
		}
		if (p == 1)
		{
			spielfeld[k + 14][k + linienzähler] = 'x';
			zellelebendig[k + 14][k + linienzähler] = 1;
		}
		linienzähler++;
	}
	return(0);
}