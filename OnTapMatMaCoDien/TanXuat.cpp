#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string input;
    cout << "Nhap: ";
    getline(cin, input);

    map<char, int> frequency;

    for (char c : input) {
        if (c != ' ') { 
            frequency[c]++;
        }
    }

    cout << "Tan xuat cac ki tu xuat hien:" << endl;
    for (const auto& pair : frequency) {
        cout << "Ki tu '" << pair.first << "' xuat hien " << pair.second << " lan." << endl;
    }

    return 0;
}