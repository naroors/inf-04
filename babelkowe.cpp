#include <iostream>

using namespace std;

int main() {
    int arr[8] = {34,56,23,89,12,11,98,43};

    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
 
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
