#include <iostream>
#include <string>

using namespace std;

class LancuchNarzedzia {
    public:
        static int policzSamogloski(string tekst) { // przyjmuje int, zwraca string
            int licznikSamoglosek = 0;
            string znaki = "aąeęiouóyAĄEĘIOUÓY";

            for (int i = 0; i < tekst.length(); i++) { // przejscie przez dlugosc podanego tekstu
                for (int j = 0; j < znaki.length(); j++) { // przjescie przez dlugosc stringu z samogloskami
                    if (tekst[i] == znaki[j]) { // sprawdzenie czy element tablicy tekst jest rowny samoglosce z "znaki"
                        licznikSamoglosek++; // +1 do licznika jesli tak.
                    }
                }
            }

            return licznikSamoglosek; // zwracamy licznik

        }

        static string usunPowtorzenia(string tekstWejsciowy) { //  przyjmuje i zwraca string
            if (tekstWejsciowy.empty() == true) { // sprawdzenie czy lancuch (string) jest pusty
                return ""; // jesli tak, zwracamy pusty string
            }

            string wynik = ""; // ustawiamy poczatkowy wynik na pusty string
            wynik += tekstWejsciowy[0]; // dodajemy pierwszy unikalny element

            for (int i = 1; i < tekstWejsciowy.length(); i++) { // przejscie przez dlugosc ta tekstu wejsciowego
                if (tekstWejsciowy[i] != tekstWejsciowy[i-1]) { // sprawdzenie czy element z tablicy wpisanego wejsciowego jest rozny od elementu przed nim
                    wynik += tekstWejsciowy[i]; // jesli tak, dodajemy ten element do stringa z wynikiem
                }
            }

            return wynik; // zwracamy wynik
        }

};


int main() {
    cout << LancuchNarzedzia::policzSamogloski("Przykład tekstu") << endl; // testowanie 
    cout << LancuchNarzedzia::usunPowtorzenia("Abba;;;to zespol"); // testowanie 

    return 0;
}