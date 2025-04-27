#include <bits/stdc++.h>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int viTri(char ch){
    int p;
    if(ch >= 'a' && ch <= 'z'){
        p = ch - 'a';
    } else if(ch >= 'A' && ch <= 'Z'){
        p = ch - 'A';
    }
    return p;
}

string maHoa(string input, int k){
    string cipherText = "";
    for(char ch : input){
        if(isalpha(ch)) {
            int p = viTri(ch);
            int c;
            if(islower(ch)) {
                c = (p + k) % 26; 
                cipherText += alphabet[c];
            } else {
                c = (p + k) % 26 + 26; 
                cipherText += alphabet[c];
            }
        } else {
            cipherText += ch; 
        }
    }
    return cipherText;
}

string giaiMa(string input, int k){
    string plainText = "";
    for(char ch : input){
        if(isalpha(ch)) { 
            int p = viTri(ch);
            int c;
            if(islower(ch)) {
                c = (p - k + 26) % 26; 
                plainText += alphabet[c];
            } else {
                c = (p - k + 26) % 26 + 26; 
                plainText += alphabet[c];
            }
        } else {
            plainText += ch; 
        }
    }
    return plainText;
}

string giaiMaBruteForce(string input){
    for(int k = 1; k < 26; k++){
        cout << "K = " << k << ": " << giaiMa(input, k) << endl;
    }
    return "";
}


int main() {
    string s;
    int k;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, s);
    cout << "Nhap khoang dich: ";
    cin >> k;

    cout << "Chuoi ma hoa: " << maHoa(s, k) << endl;

    cout << "Chuoi giai ma: " << giaiMa(maHoa(s, k), k) << endl;

    cout << "Giai ma brute force: " << endl << giaiMaBruteForce(maHoa(s, k));
}