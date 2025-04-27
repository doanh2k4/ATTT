#include<bits/stdc++.h>
using namespace std;

int main(){
	string P,C;
	char K;
	cout<<"Nhap plain text: ";
//	^
//Phep dich trai <<
//Phep dich phai >>
//Not ~
//Xor ^
//OR |
//AND &

	getline(cin,P);
	cout<<"Nhap K: ";
	cin>>K;
	C=P;
//	while(K.size()<P.size()) {
//		K+=K;
//	}
	for(int i=0;i<P.size();i++){
		C[i] = P[i] ^ K;
	}
	cout<<"Chuoi ma hoa: "<<C;
//	P="";
	for(int i=0;i<C.size();i++){
		P[i] = C[i]^K;
	}
	cout<<"Chuoi giai ma: "<<P;
	
}

