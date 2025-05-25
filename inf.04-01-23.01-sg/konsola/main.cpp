#include <iostream>

using namespace std;

class NWD {
    public: 
        static int obliczNWD(int a, int b) {
            while (a != b) {
                if (a > b) {
                    a = a - b;
                } else if (a < b) {
                    b = b - a;
                }
            }

            return a;
        }
};

int main() {
    int a,b;
    cout << "Wprowadz dane" << endl;
    cout << "Wprowadz a: ";
    cin >> a;
    while(a <= 0) {
        cout << "Liczba musi byc dodatnia. Sprobuj ponownie." << endl;
        cin >> a;
    }
    cout << "Wprowadz b: ";
    cin >> b;
    while(b <= 0) {
        cout << "Liczba musi byc dodatnia. Sprobuj ponownie." << endl;
        cin >> b;
    }

    cout<< NWD::obliczNWD(a,b);
    return 0;
}
