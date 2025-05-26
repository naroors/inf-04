#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>

using namespace std;

class Tablica {
    private:
        int* dane;
        int liczba_elementow;
    
    public:
        Tablica(int rozmiar) {
            if(rozmiar <= 0) {
                cerr << "Blad: Rozmiar tablicy musi byc wiekszy od zera. Ustawiam na 10." << endl;
                liczba_elementow = 10;
            } else {
                liczba_elementow = rozmiar;
            }

            dane = new int[liczba_elementow]; 

            for (int i = 0; i < liczba_elementow; i++) {
                dane[i] = rand() % 1000 + 1;
            }
            cout << "Tablica utworzona z " << liczba_elementow << " elementami." << endl;
        }

        ~Tablica() {
            delete[] dane;
            dane = nullptr;
            cout << "Pamiec tablicy zostala zwolniona. " << endl;
        }

        void wyswietl() {
            cout << "\n--- Wyswietlanie wszystkich elementow tablicy ---" << endl;
            for (int i = 0; i < liczba_elementow; i++) {
                cout << i << ": " << dane[i] << endl;
            }
        }

        int wyszukaj(int wartosc) {
            for (int i = 0; i < liczba_elementow; i++) {
                if (dane[i] == wartosc) {
                    return i;
                }
            }
            return -1;
        }

        int wyswietl_nieparzyste() {
            int licznik_nieparzystych = 0;
            cout << "\n--- Wyswietlanie wartosci nieparzystych ---" << endl;

            cout << "wartosci nieparzyste ";
            for (int i = 0; i < liczba_elementow; i++){ 
                if (dane[i] % 2 != 0) {
                    cout << dane[i] << " ";
                    licznik_nieparzystych++;
                }
            }

            cout << endl;

            return licznik_nieparzystych;
        }

        double licz_srednia() {
            if (liczba_elementow == 0) {
                return 0.0;
            }

            long long suma = 0;
            for (int i = 0; i < liczba_elementow; i++) {
                suma += dane[i];
            }

            return static_cast<double>(suma) / liczba_elementow;
        }
};

int main() {
    srand(time(0));

    Tablica mojaTablica(25);

    mojaTablica.wyswietl();

    int szukanaWartosc1 = rand() % 1000 + 1;
    cout << "\n--- Wyszukiwanie wartosci: " << szukanaWartosc1 << " ---" << endl;
     int indeks1 = mojaTablica.wyszukaj(szukanaWartosc1);
    if (indeks1 != -1) {
        cout << "Znaleziono wartosc " << szukanaWartosc1 << " na indeksie: " << indeks1 << endl;
    } else {
        cout << "Wartosc " << szukanaWartosc1 << " nie zostala znaleziona w tablicy." << endl;
    }

    int szukanaWartosc2 = 9999;
    cout << "\n--- Wyszukiwanie wartosci: " << szukanaWartosc2 << " ---" << endl;
    int indeks2 = mojaTablica.wyszukaj(szukanaWartosc2);
    if (indeks2 != -1) {
        cout << "Znaleziono wartosc " << szukanaWartosc2 << " na indeksie: " << indeks2 << endl;
    } else {
        cout << "wartosc " << szukanaWartosc2 << " nie zostala znaleziona w tablicy." << endl;
    }

    int iloscNieparzystych = mojaTablica.wyswietl_nieparzyste();
    cout << "Laczna liczba wartosci nieparzystych: " << iloscNieparzystych << endl;

    double srednia = mojaTablica.licz_srednia();
    cout << "\nSrednia arytmetyczna wszystkich wartosci w tablicy: " << srednia << endl;
    return 0;
}
