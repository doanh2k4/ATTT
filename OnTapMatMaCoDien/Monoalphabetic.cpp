#include <bits/stdc++.h>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int vtTri(char c) {
    if (c >= 'a' && c <= 'z') 
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A';
}

string maHoa(string s, string key) {
    string cipherText = "";
    for (char c : s) {
        if (isalpha(c)) {
            int p = vtTri(c);
            if (islower(c)) {
                cipherText += key[p];
            } else {
                cipherText += toupper(key[p]);
            }
        } else {
            cipherText += c;
        }
    }
    return cipherText;
}

string giaiMa(string s, string key) {
    string plainText = "";
    unordered_map<char, char> reverseKey;

    for (int i = 0; i < 26; i++) {
        reverseKey[key[i]] = alphabet[i];
        reverseKey[toupper(key[i])] = alphabetUpper[i];
    }

    for (char c : s) {
        if (isalpha(c)) {
            plainText += reverseKey[c];
        } else {
            plainText += c;
        }
    }
    return plainText;
}

int main() {
    string input, key;

    cout << "Nhap chuoi can giai ma: ";
    getline(cin, input);
    cout << "Nhap khoa k: ";
    cin >> key;

    cout << "Chuoi ma hoa: " << maHoa(input, key) << endl;

    cout << "Chuoi giai ma: " << giaiMa(maHoa(input, key), key) << endl;

    return 0;
}