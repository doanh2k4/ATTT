#include <iostream>
#include <string>
using namespace std;

string encryptRainFence(string text, int key) {
    string ciphertext = "";
    int len = text.length();
    for (int i = 0; i < key; i++) {
        for (int j = i; j < len; j += key) {
            ciphertext += text[j];
        }
    }
    return ciphertext;
}

string decryptRainFence(string ciphertext, int key) {
    int len = ciphertext.length();
    string plaintext(len, ' ');
    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = i; j < len; j += key) {
            plaintext[j] = ciphertext[index++];
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    int key;

    cout << "Nhap plaintext: ";
    getline(cin, plaintext);

    cout << "Nhap key: ";
    cin >> key;

    ciphertext = encryptRainFence(plaintext, key);
    cout << "Chuoi ma hoa: " << ciphertext << endl;

    string decryptedText = decryptRainFence(ciphertext, key);
    cout << "Chuoi giai ma: " << decryptedText << endl;

    return 0;
}