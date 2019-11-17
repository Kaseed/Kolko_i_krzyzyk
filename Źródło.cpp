#include <iostream>

using namespace std;

char TAB[9];

// Funkcja wyswietl pokazuje cala plansze do gry

void Wyswietl()
{
	for (int i = 0; i < 9; i++)
	{
		if ((i+1) % 3 == 1)
			cout << "-------" << endl<<'-';
		cout << TAB[i]<<'-';
		if ((i + 1) % 3 == 0)
		{
			cout << endl;
			if(i==8)
				cout << "-------" << endl;
		}
	}
}

	// Bot do gry


int Bot_gra(char tab[])
{
	// PIERWSZY RUCH
	if (tab[1 - 1] != 'X' && tab[3 - 1] != 'X' && tab[7 - 1] != 'X' && tab[9 - 1] != 'X')
	{
		// bot sprawdza czy w rogu znajduje sie przeciwnik
		if (tab[1 - 1] == 'O' || tab[3 - 1] == 'O' || tab[7 - 1] == 'O' || tab[9 - 1] == 'O')
		{
			if (tab[1 - 1] == 'O')
				return 9;
			if (tab[3 - 1] == 'O')
				return 7;
			if (tab[7 - 1] == 'O')
				return 3;
			if (tab[9 - 1] == 'O')
				return 1;
		}
		// bot sprawdza czy przy boku znajduje sie przeciwnik
		else if (tab[2 - 1] == 'O' || tab[4 - 1] == 'O' || tab[6 - 1] == 'O' || tab[8 - 1] == 'O')
		{
			if (tab[2 - 1] == 'O')
				return 1;
			if (tab[4 - 1] == 'O')
				return 1;
			if (tab[6 - 1] == 'O')
				return 9;
			if (tab[8 - 1] == 'O')
				return 9;
		}
		return 1;

	}

	//BOT SPRAWDZA CZY MA MOZLIWOSC WYKONAC ZWYCIESKI RUCH
	
	//Sprawdza mozliwosc zwyciestwa w poziomie
	for (int i = 0; i < 9; i += 3)
	{
		if ((tab[i] == 'X' && tab[i + 1] == 'X') || (tab[i + 1] == 'X' && tab[i + 2] == 'X') || (tab[i + 2] == 'X' && tab[i] == 'X'))
		{
			if (tab[i] == ' ')
				return (i + 1 );
			if (tab[i+1] == ' ')
				return ( i + 2 );
			if (tab[i+2] == ' ')
				return ( i + 3 );
		}
	}

	//Sprawdza mozliwosc zwyciestwa w pionie
	for (int i = 0; i < 3; i++)
	{
		if ((tab[i] == 'X' && tab[i + 3] == 'X') || (tab[i + 3] == 'X' && tab[i + 6] == 'X') || (tab[i] == 'X' && tab[i + 6] == 'X'))
		{
			if (tab[i] == ' ')
				return ( i + 1 );
			if (tab[i + 3] == ' ')
				return (i + 4);
			if (tab[i + 6] == ' ')
				return (i + 7);
		}
	}

	//Sprawdza mozliwosc zwyciestwa po skosach
	if ((tab[0] == 'X' && tab[4] == 'X') || (tab[4] == 'X' && tab[8] == 'X') || (tab[8] == 'X' && tab[0] == 'X'))
	{
		if (tab[0] == ' ')
			return 1;
		if (tab[4] == ' ')
			return 5;
		if (tab[8] == ' ')
			return 9;
	}
	if ((tab[2] == 'X' && tab[4] == 'X') || (tab[4] == 'X' && tab[6] == 'X') || (tab[2] == 'X' && tab[6] == 'X'))
	{
		if (tab[2] == ' ')
			return 3;
		if (tab[4] == ' ')
			return 5;
		if (tab[6] == ' ')
			return 7;
	}

	// BOT SPRAWDZA CZY PRZECIWNIK MOZE WYKONAC ZWYCIESKI RUCH

	//Sprawdza mozliwosc zwyciestwa w poziomie
	for (int i = 0; i < 9; i += 3)
	{
		if ((tab[i] == 'O' && tab[i + 1] == 'O') || (tab[i + 1] == 'O' && tab[i + 2] == 'O') || (tab[i + 2] == 'O' && tab[i] == 'O'))
		{
			if (tab[i] == ' ')
				return ( i + 1 );
			if (tab[i + 1] == ' ')
				return (i + 2);
			if (tab[i + 2] == ' ')
				return (i + 3);
		}
	}

	//Sprawdza mozliwosc zwyciestwa w pionie
	for (int i = 0; i < 3; i++)
	{
		if ((tab[i] == 'O' && tab[i + 3] == 'O') || (tab[i + 3] == 'O' && tab[i + 6] == 'O') || (tab[i] == 'O' && tab[i + 6] == 'O'))
		{
			if (tab[i] == ' ')
				return ( i + 1 );
			if (tab[i + 3] == ' ')
				return (i + 4);
			if (tab[i + 6] == ' ')
				return (i + 7);
		}
	}

	//Sprawdza mozliwosc zwyciestwa po skosach
	if ((tab[0] == 'O' && tab[4] == 'O') || (tab[4] == 'O' && tab[8] == 'O') || (tab[8] == 'O' && tab[0] == 'O'))
	{
		if (tab[0] == ' ')
			return 1;
		if (tab[4] == ' ')
			return 5;
		if (tab[8] == ' ')
			return 9;
	}
	if ((tab[2] == 'O' && tab[4] == 'O') || (tab[4] == 'O' && tab[6] == 'O') || (tab[2] == 'O' && tab[6] == 'O'))
	{
		if (tab[2] == ' ')
			return 3;
		if (tab[4] == ' ')
			return 5;
		if (tab[6] == ' ')
			return 7;
	}

	// BOT PROBUJE STWORZYC OKAZJE DO ZWYCIESTWA

	for (int i = 0; i < 9; i++)
	{
		if (TAB[i] == 'X')
		{
			if ( i+ 1 < 9 && TAB[i + 1] == ' ')
				return (i + 2);
			if ( i - 1 >= 0 && TAB[i - 1] == ' ')
				return i;
			if (i - 3 >= 0 && TAB[i - 3] == ' ')
				return (i - 2);
			if ( i + 3 < 9 && TAB[i + 3] == ' ')
				return (i + 4);
		}
	}
	
}


//funkcja Ruch pobiera dane gracza i zmienia go jesli wykona poprawny ruch
//funkcja Ruch zwraca wartosc gracza krory nie wykonal ruchu


bool Ruch(char tab[9], bool player,int tryb)
{
	int a;
	while (true)
	{
		//Wybor kto wprowadza dane;
		if (tryb == 0 || player == 0)
			cin >> a;
		else
			a = Bot_gra(tab);

		system("cls");

		if (a > 0 && a < 10 && tab[a - 1] == ' ')
		{
			if (player == 1)
			{
				cout << "Ruch gracza \'X\'\n";
				tab[a - 1] = 'X';
				return 0;
			}
			else
			{
				cout << "Ruch gracza \'O\'\n";
				tab[a - 1] = 'O';
				return 1;
			}
		}
		else
		{
			cout << "Podano nieprawidlowy zakres!\nPodaj nowa liczbe." << endl;
			Wyswietl();
		}

	}
}

//funkcja Winner sprawdza kolejno czy w jakimkolwiek rzedzie nie ma zwycieksiej kombinacji
//funkcja Winner zwraca 1 jesli wystepuje zwyciestwo lub 0 jesli nie wystepuje 

bool Winner(char tab[9])
{
	for(int i = 0 ; i < 9 ; i+=3)
	{
		if (tab[i] == tab[i+1] && tab[i] == tab[i+2] && tab[i] != ' ')
			return 1;
	}
	for (int i = 0; i < 3; i ++)
	{
		if (tab[i] == tab[i + 3] && tab[i] == tab[i + 6] && tab[i] != ' ')
			return 1;
	}
	if (tab[0] == tab[4] && tab[0] == tab[8] && tab[0] != ' ')
		return 1;
	if (tab[2] == tab[4] && tab[2] == tab[6] && tab[2] != ' ')
		return 1;
		return 0;
}


int main()
{
	bool player = 0, Win = 0;
	int remis=0, tryb = 0;
	// Gracz bool 0 to O
	// Gracz bool 1 to X
	// int remis bedzie zliczac ile ruchow zostalo wykonanych

	for (int i = 0; i < 9; i++)
	{
		TAB[i] = ' ';
	}

	// Wybor trybu

	cout << "Wybierz tryb gry:\n0 - Tryb z drugim graczem\n1 - Tryb z botem\n";
	do
	{
		cin >> tryb;
	} while (tryb != 0 && tryb != 1);

	system("cls");
	cout << "Ruch gracza \'O\'\n";
	// Gra wlasciwa

	do
	{
		
		
		Wyswietl();

		player = Ruch(TAB, player, tryb);

		//system("cls");

		Win = Winner(TAB);

		remis++;

		



	} while (Win == 0 && remis<9);

	//Funkcja najpierw zmienia gracza po ruchu a nastepnie sprawdza zwyciestwo 
	//Gracz ktory nie wykonal zwycieskiego ruchu jest automatycznie przegramym

	if (Win == 1)
	{
		if (player == 1)
			cout << "Gratulacje gracz Kolko";
		else
			cout << "Gratulacje gracz Krzyzyk";
		cout << " wygral. Oto jego kombinacja:" << endl;
	}
	else
		cout << "Zaden gracz nie wygral. Oto wynik pojedynku" << endl;
	Wyswietl();


	system("PAUSE");
	return 0;
}