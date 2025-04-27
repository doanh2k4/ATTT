#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Nhap chuoi: ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Chuoi rong" << endl;
        return 0;
    }

    char firstChar = input[0];
    int count = 0;

    for (char c : input) {
        if (c == firstChar) {
            count++;
        }
    }

    cout << "Ki tu dau tien '" << firstChar << "' xuat hien " << count << " lan trong chuoi" << endl;
 
    return 0;
}