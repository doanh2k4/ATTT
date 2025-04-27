#include <iostream>
#include <string>
using namespace std;

string vigenereEncrypt(const string &plaintext, const string &key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            char keyBase = isupper(keyChar) ? 'A' : 'a';
            ciphertext += (plainChar - base + (keyChar - keyBase)) % 26 + base;
        } else {
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

string vigenereDecrypt(const string &ciphertext, const string &key) {
    string plaintext = "";
    int keyLength = key.length();

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(cipherChar)) {
            char base = isupper(cipherChar) ? 'A' : 'a';
            char keyBase = isupper(keyChar) ? 'A' : 'a';
            plaintext += (cipherChar - base - (keyChar - keyBase) + 26) % 26 + base;
        } else {
            plaintext += cipherChar; 
        }
    }

    return plaintext;
}

int main() {
    string plaintext, key;


    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, plaintext);
    cout << "Nhap khoa: ";
    getline(cin, key);

    string ciphertext = vigenereEncrypt(plaintext, key);
    cout << "Chuoi da ma hoa: " << ciphertext << endl;

    string decryptedText = vigenereDecrypt(ciphertext, key);
    cout << "Chuoi duoc giai ma: " << decryptedText << endl;

    return 0;
}