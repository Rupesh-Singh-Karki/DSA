#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the cross pattern: ";
    cin >> size;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == size / 2 || j == size / 2) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    return 0;
}