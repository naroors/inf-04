#include <iostream>

using namespace std;

int main() {
    int ROZMIAR_TABLICY = 10;
    int arr[ROZMIAR_TABLICY];


    cout << "wpisz dane do tablicy" << endl;
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        cout << "wpisz element " << i << " tablicy: ";
        cin >> arr[i];
    }

    cout << "Tablica: " << endl;
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        int min = i;

        for (int j = i + 1; j < ROZMIAR_TABLICY; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            int temp = arr[j];
            arr[j] = arr[min];
            arr[min] = temp;
        }
    }

    cout << "Posortowana tablica: " << endl;
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
