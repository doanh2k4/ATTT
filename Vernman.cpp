#include<bits/stdc++.h>
using namespace std;

//Phep dich trai <<
//Phep dich phai >>
//Phep XOR ^
//Phep AND &
//Phep NOT ~

int main(){
//	string P, C; 
//	char K;
//	cout<<"Nhap plaintext: "; getline(cin,P);
//	cout<<"Nhap K: "; cin>>K;
//	C = P;
//	for(int i =0 ; i<P.size();i++){
//		C[i] = P[i] ^ K;
//		
//	}
//	cout<<"Chuoi ma hoa: "<<C<<endl;
//	
//	for(int i =0 ; i<C.size();i++){
//		P[i] = C[i] ^ K;
//	}
//	cout<<"Chuoi giai ma: "<<P;
	string P, C; 
	string K;
	cout<<"Nhap plaintext: "; getline(cin,P);
	cout<<"Nhap K: "; getline(cin,K);
	C = P;
	for(int i =0 ; i<P.size();i++){
		C[i] = P[i] ^ K[i % K.size()];
		
	}
	cout<<"Chuoi ma hoa: "<<C<<endl;
	
	for(int i =0 ; i<C.size();i++){
		P[i] = C[i] ^ K[i % K.size()];
	}
	cout<<"Chuoi giai ma: "<<P;
}
