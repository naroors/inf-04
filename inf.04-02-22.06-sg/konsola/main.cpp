#include <iostream>
#include <string>

using namespace std;

class Osoba {
    private:
        int id;
        string imie;
    public:
        static int licznikInstancji;

        Osoba() {
            id = 0;
            imie = "";
            licznikInstancji++;
        }

        Osoba(int id_val, const string& imie_val) {
            id = id_val;
            imie = imie_val;
            licznikInstancji++;
        }

        Osoba(const Osoba& other) {
            id = other.id;
            imie = other.imie;
            licznikInstancji++;
        }

        void przedstawSie(const string& argument) {
            if (imie.empty()) { 
                cout << "Brak danych" << endl;
            } else {
                cout << "Czesc " << argument << ", mam na imie " << imie << endl;
            }

        }
};

int Osoba::licznikInstancji = 0;

int main() {
    // test bezparametrow
    Osoba os1;
    cout << "Test os 1 (bezparametrowy): ";
    os1.przedstawSie("Kolego");

    // test z parametrami
    Osoba os2(1, "Anna");
    cout << "Test os 2 (z parametrami): ";
    os2.przedstawSie("Przyjacielu");

    // test konstruktora kopiujacego
    Osoba os3(os2);
    cout << "Test os 3 (kopiujacy z os 2): ";
    os3.przedstawSie("Znajomy");

    // test obiektu z pustym imieniem
    Osoba os4(2, "");
    cout << "Test os 4 (z parametrami, puste imie): ";
    os4.przedstawSie("Ty");

    // wys instancje    
    cout << "Liczba stworzonych obiektow Osoba: " << Osoba::licznikInstancji << endl; // Powinno być 4
    return 0;
}
