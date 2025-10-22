#include <iostream>      // pozwala na używanie cout do wypisywania danych
#include <vector>        // dzięki temu możemy korzystać z dynamicznych tablic (wektorów)

using namespace std;      // ułatwia pisanie, żeby nie pisać std:: przed każdym słowem

// ---------------------------------------------------------------
// Funkcja 'merge' łączy dwie posortowane części jednej tablicy w jedną większą, też posortowaną
// ---------------------------------------------------------------
void merge(vector<int>& arr, int left, int mid, int right) {
    // Liczymy długości obu połówek
    int n1 = mid - left + 1;   // lewa część ma n1 elementów
    int n2 = right - mid;      // prawa część ma n2 elementów

    // Tworzymy dwie tymczasowe tablice na skopiowanie danych
    vector<int> L(n1);         // tablica dla lewej połowy
    vector<int> R(n2);         // tablica dla prawej połowy

    // Kopiujemy dane z oryginalnego wektora do tablic pomocniczych
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];  // kopiujemy elementy od indeksu 'left' do 'mid'
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]; // kopiujemy elementy od 'mid+1' do 'right'
    }

    // Teraz mamy dwie posortowane tablice: L oraz R
    // Połączymy je w jedną posortowaną całość i wpiszemy z powrotem do arr

    int i = 0;       // wskaźnik na aktualny element w L
    int j = 0;       // wskaźnik na aktualny element w R
    int k = left;    // wskaźnik gdzie wstawiać w arr

    // Dopóki w obu tablicach są jeszcze elementy
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {   // jeśli element z lewej mniejszy lub równy temu z prawej
            arr[k] = L[i];    // wstawiamy z lewej części
            i++;              // przesuwamy wskaźnik w L
        } else {
            arr[k] = R[j];    // wstawiamy z prawej części
            j++;              // przesuwamy wskaźnik w R
        }
        k++;                   // przesuwamy wskaźnik w oryginalnej tablicy
    }

    // Jeśli coś jeszcze zostało w lewej połowie — przepisujemy resztę
    while (i < n1) {
        arr[k] = L[i];        // wstaw pozostałe elementy L do arr
        i++;
        k++;
    }

    // Jeśli coś zostało w prawej połowie — przepisujemy resztę
    while (j < n2) {
        arr[k] = R[j];        // wstaw pozostałe elementy R do arr
        j++;
        k++;
    }
}

// ---------------------------------------------------------------
// Funkcja mergeSort dzieli tablicę na coraz mniejsze części (rekurencyjnie)
// aż każda część ma jeden element, a potem scala wszystko w całość
// ---------------------------------------------------------------
void mergeSort(vector<int>& arr, int left, int right) {
    // Jeżeli mamy więcej niż jeden element, sortujemy dalej
    if (left < right) {
        // Szukamy środka podziału tablicy
        int mid = left + (right - left) / 2;  // bezpieczny sposób (unikamy przepełnienia)

        // Najpierw sortujemy lewą połowę
        mergeSort(arr, left, mid);

        // Potem sortujemy prawą połowę
        mergeSort(arr, mid + 1, right);

        // Na koniec łączymy obie posortowane połowy
        merge(arr, left, mid, right);
    }
}

// ---------------------------------------------------------------
// Funkcja główna — tu program się zaczyna
// ---------------------------------------------------------------
int main() {
    // Tworzymy wektor z przykładowymi liczbami (do posortowania)
    vector<int> arr = { 1, 56, 324, 86, 34, 12, 87, 23 };

    // Wywołujemy sortowanie — sortujemy całą tablicę (od 0 do arr.size()-1)
    mergeSort(arr, 0, arr.size() - 1);

    // Wypisujemy wynik sortowania na ekran
    cout << "Wynik sortowania algorytmu Merge Sort: ";
    for (auto x : arr) {        // przechodzimy po wszystkich elementach w arr
        cout << x << " ";        // wypisujemy element i spację
    }
    cout << endl;               // koniec linii

    return 0;                   // koniec programu
}
