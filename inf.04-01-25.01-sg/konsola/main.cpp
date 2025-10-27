#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class ArrayManager {
    int *tablica;
    int rozmiar;

    public:
        ArrayManager(int n) { // konstruktor
            rozmiar = n;
            tablica = new int[n];
            srand(time(0));
            for (int i = 0; i < rozmiar; i++) {
                tablica[i] = rand() % 1000 + 1;
            }
        }

        ~ArrayManager() { // destruktor
            delete[] tablica;
        }

        void showAll() {
            for (int i = 0; i < rozmiar; i++) {
                cout << i << ": " << tablica[i] << endl;
            }
        }

        int findValue(int x) {
            for (int i = 0; i < rozmiar; i++) {
                if (tablica[i] == x) return i;
            }
            return -1;
        }

        int showOdd() {
            int count = 0;
            for (int i = 0; i < rozmiar; i++) {
                if (tablica[i] % 2) {
                    cout << tablica[i] << endl;
                    count++;
                }
            }
            return count;
        }

        int average() {
            int sum = 0;
            for (int i = 0; i < rozmiar; i++) {
                sum += tablica[i];
            }
            return sum/rozmiar;
        }

};

int main() {
    int n = 21;
    ArrayManager arr(n);

    cout << "Wszystkie elementy: " << endl;
    arr.showAll();

    int szukana;
    cout << "Wpisz liczbe do wyszukania: " << endl;
    cin >> szukana;
    int idx = arr.findValue(szukana); // sprawdzenie na ktorym miejscu sie znajduje
    if(idx != -1) cout << "Znaleziono na pozycji: " << idx << endl;
    else cout << "Nie znaleziono wsrod wylosowaych." << endl;

    cout << "Liczby nieparzyste: " << endl;
    int count = arr.showOdd();
    cout << "Razem nieparzystych: " << count << endl;
    cout << "Srednia wszystkich elementow: " << arr.average() << endl;


    return 0;
}
