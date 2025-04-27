#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void prepareKeyMatrix(string key, char keyMatrix[5][5]) {
    vector<bool> used(26, false);
    used['J' - 'A'] = true;

    int row = 0, col = 0;
    for (char c : key) {
        if (c == 'J') c = 'I';
        if (!used[c - 'A']) {
            keyMatrix[row][col++] = c;
            used[c - 'A'] = true;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            keyMatrix[row][col++] = c;
            used[c - 'A'] = true;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
}

string preprocessPlaintext(string plaintext) {
    string processed = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            processed += toupper(c);
        }
    }
    for (size_t i = 0; i < processed.length() - 1; i += 2) {
        if (processed[i] == processed[i + 1]) {
            processed.insert(i + 1, "X");
        }
    }
    if (processed.length() % 2 != 0) {
        processed += 'X';
    }
    return processed;
}

void findPosition(char c, char keyMatrix[5][5], int &row, int &col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encryptPair(char a, char b, char keyMatrix[5][5]) {
    int row1, col1, row2, col2;
    findPosition(a, keyMatrix, row1, col1);
    findPosition(b, keyMatrix, row2, col2);

    if (row1 == row2) {
        return string(1, keyMatrix[row1][(col1 + 1) % 5]) + keyMatrix[row2][(col2 + 1) % 5];
    } else if (col1 == col2) {
        return string(1, keyMatrix[(row1 + 1) % 5][col1]) + keyMatrix[(row2 + 1) % 5][col2];
    } else {
        return string(1, keyMatrix[row1][col2]) + keyMatrix[row2][col1];
    }
}

string encrypt(string plaintext, string key) {
    char keyMatrix[5][5];
    prepareKeyMatrix(key, keyMatrix);
    plaintext = preprocessPlaintext(plaintext);

    string ciphertext = "";
    for (size_t i = 0; i < plaintext.length(); i += 2) {
        ciphertext += encryptPair(plaintext[i], plaintext[i + 1], keyMatrix);
    }
    return ciphertext;
}

string decryptPair(char a, char b, char keyMatrix[5][5]) {
    int row1, col1, row2, col2;
    findPosition(a, keyMatrix, row1, col1);
    findPosition(b, keyMatrix, row2, col2);

    if (row1 == row2) {
        return string(1, keyMatrix[row1][(col1 + 4) % 5]) + keyMatrix[row2][(col2 + 4) % 5];
    } else if (col1 == col2) {
        return string(1, keyMatrix[(row1 + 4) % 5][col1]) + keyMatrix[(row2 + 4) % 5][col2];
    } else {
        return string(1, keyMatrix[row1][col2]) + keyMatrix[row2][col1];
    }
}

string decrypt(string ciphertext, string key) {
    char keyMatrix[5][5];
    prepareKeyMatrix(key, keyMatrix);

    string plaintext = "";
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        plaintext += decryptPair(ciphertext[i], ciphertext[i + 1], keyMatrix);
    }
    return plaintext;
}

int main() {
    string key, plaintext;
    cout << "Nhap khoa: ";
    cin >> key;
    cout << "Nhap chuoi plaintext: ";
    cin >> plaintext;

    string ciphertext = encrypt(plaintext, key);
    cout << "Chuoi da ma hoa: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);
    cout << "Chuoi duoc giai ma: " << decryptedText << endl;

    return 0;
}