#include<bits/stdc++.h>
using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int viTri(char ch) {
    int p;
    if (ch >= 'a' && ch <= 'z') {
        p = ch - 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
        p = ch - 'A';
    }
    return p;
}

string maHoa(string input, int a, int b) {
    string cipherText = "";
    for (char ch : input) {
        if (isalpha(ch)) {
            int p = viTri(ch);
            int viTriMoi = (a * p + b) % 26; 
            if (ch >= 'a' && ch <= 'z') {
                cipherText += 'a' + viTriMoi;
            } else if (ch >= 'A' && ch <= 'Z') {
                cipherText += 'A' + viTriMoi;
            }
        } else {
            cipherText += ch; 
        }
    }
    return cipherText;
}

int nghichDao(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

string giaiMa(string cipherText, int a, int b) {
    string plainText = "";
    int a_inv = nghichDao(a, 26); 
    if (a_inv == -1) {
        return "Khong co nghich dao";
    } else {
        for (char ch : cipherText) {
            if (isalpha(ch)) {
                int p = viTri(ch);
                int viTriCu = (a_inv * (p - b + 26)) % 26; 
                if (ch >= 'a' && ch <= 'z') {
                    plainText += 'a' + viTriCu;
                } else if (ch >= 'A' && ch <= 'Z') {
                    plainText += 'A' + viTriCu;
                }
            } else {
                plainText += ch; 
            }
        }
    }
    return plainText;
}

string giaiMaBruteForce(string input) {
    cout << "Giai ma bang phuong phap bruteforce:" << endl;
    for (int a = 1; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            cout << "a = " << a << ", b = " << b << ": " << giaiMa(input, a, b) << endl;
        }
    }
    return "";
}

int main() {
    string s;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, s);
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    string cipherText = maHoa(s, a, b);
    cout << "Chuoi ma hoa: " << cipherText << endl;

    cout << "Giai ma chuoi: " << giaiMa(cipherText, a, b) << endl;

    giaiMaBruteForce(cipherText);
}