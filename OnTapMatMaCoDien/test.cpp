#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void fillMatrix(const string &plaintext, char matrix[5][5]) {
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (index < plaintext.size()) {
                matrix[i][j] = plaintext[index++];
            } else {
                matrix[i][j] = ' '; 
            }
        }
    }
}

string encrypt(const char matrix[5][5]) {
    string ciphertext;
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 5; ++i) {
            ciphertext += matrix[i][j];
        }
    }
    return ciphertext;
}

string decrypt(const string &ciphertext) {
    char matrix[5][5];
    int index = 0;
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (index < ciphertext.size()) {
                matrix[i][j] = ciphertext[index++];
            }
        }
    }

    string plaintext;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            plaintext += matrix[i][j];
        }
    }
    return plaintext;
}

int main() {
    string plaintext;
    cout << "Nhập chuỗi plaintext (dài không quá 25 ký tự): ";
    getline(cin, plaintext);

    if (plaintext.size() > 25) {
        cout << "Chuỗi nhập vào quá dài! Vui lòng nhập lại.\n";
        return 1;
    }

    char matrix[5][5];
    fillMatrix(plaintext, matrix);

    cout << "Ma trận 5x5 từ chuỗi plaintext:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << setw(2) << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    string ciphertext = encrypt(matrix);
    cout << "Ciphertext: " << ciphertext << '\n';

    string decryptedText = decrypt(ciphertext);
    cout << "Giải mã ciphertext: " << decryptedText << '\n';

    return 0;
}