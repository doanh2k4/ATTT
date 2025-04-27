#include <iostream>
#include <bitset>
#include <string>

using namespace std;


string vernamEncrypt(const string& plaintext, const string& key) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.size(); ++i) {
        char encryptedChar = plaintext[i] ^ key[i % key.size()];
        ciphertext += encryptedChar;
    }
    return ciphertext;
}

string vernamDecrypt(const string& ciphertext, const string& key) {
    string decryptedText = "";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        char decryptedChar = ciphertext[i] ^ key[i % key.size()];
        decryptedText += decryptedChar;
    }
    return decryptedText;
}

int main() {
    string plaintext = "HA NOI";
    string key = "10010011";

    string keyChar = "";
    keyChar += static_cast<char>(bitset<8>(key).to_ulong());

    string ciphertext = vernamEncrypt(plaintext, keyChar);
    cout << "Ciphertext (dạng nhị phân): ";
    for (char c : ciphertext) {
        cout << bitset<8>(c) << " ";
    }
    cout << endl;

    string decryptedText = vernamDecrypt(ciphertext, keyChar);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}