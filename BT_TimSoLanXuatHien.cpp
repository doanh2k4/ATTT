/*
-Ðem ky tu dau tien xuat hien bao nhieu lan ?
-Ðem cac ky tu trong chuoi xuat hien bao nhieu lan?
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s; int d=0;
	cout<<"Nhap chuoi: ";
	getline(cin,s);
	for(int i=0; i<s.length();i++)
		if(s[i]==s[0]) d++;
	cout<<"So lan xuat hien ki tu dau tien la: "<<d<<endl;
	
	unordered_map<char, int> charCount;

    for (char c : s) {
        // Kiem tra xem ký tu dã có trong unordered_map chua
        if (charCount.find(c) != charCount.end()) {
            charCount[c]++;
        } else {
            charCount[c] = 1;
        }
    }

    for (const auto& pair : charCount) {
        cout << pair.first << ": xuat hien " << pair.second << " lan" << endl;
    }

}
