//POP 2020-12-17  projekt 1 Winiarski Przemysław EiT 3 186256 Code::Blocks 17.12
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct zero
{
    int x;
    int y;
};

bool czywyl(int iLiczba, int* tab, int ile)
{
    if (ile <= 0)
        return false;
    int i = 0;
    do
    {
        if (tab[i] == iLiczba)
            return true;
        i++;
    } while (i < ile);
    return false;
}

int wylosuj(int n)
{
    return rand() % (n * n);
}

void wypisz(int** tab2, int n)
{
    for (int i = 0; i < (n * 4 - (n - 3)); i++)
        cout << "-";

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; j++)
        {
            if (tab2[i][j] == 0)
                cout << "  " << " ";
            else
                cout << setw(2) << tab2[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    for (int i = 0; i < (n * 4 - (n - 3)); i++)
        cout << "-";

    cout << endl;
}

bool uloz(int** tab3, int n)
{
    int licznik = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab3[i][j] == licznik)
                licznik++;
        }
    }
    if (licznik == (n * n))
        return true;
    else
        return false;
}

zero znajdz0(int** tab4, int n)
{
    zero polzero;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab4[i][j] == 0)
            {
                polzero.x = i; polzero.y = j;
                break;
            }
        }
    }
    return polzero;
}

void wypiszruchy()
{
    cout << endl;
    cout << "Podaj typ ruchu" << endl << endl
        << "1 z gory na dol |v|" << endl
        << "2 z dolu do gory |^|" << endl
        << "3 z prawej do lewej |<---|" << endl
        << "4 z lewej do prawej |--->|" << endl
        << "5 z skok z gory na dol |v|v|" << endl
        << "6 z skok z dolu do gory |^|^|" << endl
        << "7 z skok z prawej do lewej |<---|<---|" << endl
        << "8 z skok z lewej do prawej |--->|--->|" << endl;

    cout << endl;

    cout << "Twoj wybor to ";
}

int main()
{
    srand(time(NULL));
    int n;
    string sn;
    cout << "Podaj rozmiar tablicy od 3-8 ";
    do
    {
        cin >> sn;
        n = atoi(sn.c_str());
    } while (n < 3 or n>8);
    cout << endl;

    int* tab = new int[n * n];
    int ilewyl = 0;
    do
    {
        int liczba = wylosuj(n);
        if (czywyl(liczba, tab, ilewyl) == false)
        {
            tab[ilewyl] = liczba;
            ilewyl++;
        } //if
    } while (ilewyl < n * n);

    int** board = new int* [n];
    for (int i = 0; i < n; i++)
        board[i] = new int[n];
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            board[i][j] = tab[k];
            k++;
        }

    /*int tabuloz[16];
    for(int h=0;h<15;h++)
        {
            tabuloz[h]=h+1;
        }
        tabuloz[15]=0;
    int z=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            board[i][j]=tabuloz[z];
            z++;
        }*/

    zero polzero;
    string stypruchu;
    int typruchu;
    int a;
    do
    {
        wypisz(board, n);
        polzero = znajdz0(board, n);
        wypiszruchy();

        do
        {
            cin >> stypruchu;
            typruchu = atoi(stypruchu.c_str());
        } while (typruchu < 1 or typruchu>8);

        cout << endl;

        switch (typruchu)
        {
        case 1:
            if (polzero.x != 0)
            {
                a = board[polzero.x - 1][polzero.y];
                board[polzero.x - 1][polzero.y] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 2:
            if (polzero.x != n - 1)
            {
                a = board[polzero.x + 1][polzero.y];
                board[polzero.x + 1][polzero.y] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 3:
            if (polzero.y != n - 1)
            {
                a = board[polzero.x][polzero.y + 1];
                board[polzero.x][polzero.y + 1] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 4:
            if (polzero.y != 0)
            {
                a = board[polzero.x][polzero.y - 1];
                board[polzero.x][polzero.y - 1] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 5:
            if (polzero.x > 1)
            {
                a = board[polzero.x - 2][polzero.y];
                board[polzero.x - 2][polzero.y] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 6:
            if (polzero.x < n - 2)
            {
                a = board[polzero.x + 2][polzero.y];
                board[polzero.x + 2][polzero.y] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 7:
            if (polzero.y < n - 2)
            {
                a = board[polzero.x][polzero.y + 2];
                board[polzero.x][polzero.y + 2] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        case 8:
            if (polzero.y > 1)
            {
                a = board[polzero.x][polzero.y - 2];
                board[polzero.x][polzero.y - 2] = board[polzero.x][polzero.y];
                board[polzero.x][polzero.y] = a;
                break;
            }
            else
                cout << "Niemozliwe" << endl << endl;
            break;
        }
    } while (uloz(board, n) != true);
    wypisz(board, n);
    cout << "Gratulacje ulozyles gre :) ";
    return 0;
}