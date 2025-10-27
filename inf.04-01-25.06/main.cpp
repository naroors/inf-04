#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generujZestawy(int zestaw[6]) {
    bool czyWylosowana[50] = { false }; // indeksy od 1..49 jako false

    int i = 0;
    while (i < 6) {
        int liczba = rand() % 49 + 1;
        if (!czyWylosowana[liczba]) {
            czyWylosowana[liczba] = true;
            zestaw[i] = liczba;
            i++;
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    cout << "Ile wygenerowac losowan?" << endl;
    cin >> n;

    int statystyka[50] = {0};

    cout << "Zestawy wylosowanych liczb: " << endl;
    for (int k = 1; k <= n; k++) {
        int zestaw[6];
        generujZestawy(zestaw);
        cout << "Losowanie " << k << ": ";
        for (int i = 0; i < 6; i++) {
            cout << zestaw[i] << " ";
            statystyka[zestaw[i]]++;
        }
        cout << endl;
    }

    for (int i = 1; i < 49; i++) {
        cout << "Wystapienia liczby " << i << ": " << statystyka[i] << endl;
    }

}
