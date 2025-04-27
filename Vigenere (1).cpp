#include<bits/stdc++.h>
using namespace std;

int KT_S(char c){
	return c - 'A';
}
char S_KT(int n){
	return 'A' + n;
}

int main(){
	string P,C = "",K;
	cout<<"Nhap chuoi plaintext: ";
	getline(cin,P);
	cout<<"Nhap chuoi khoa: ";
	getline(cin,K);
	
	//Chuan hoa chuoi khoa
	while(P.size() > K.size()){
		K+= K;
	}
	
	for(int i=0;i<P.size();i++){
		int k = KT_S(K[i]);
		C += S_KT((KT_S(P[i]) + k) % 26);
	}
	cout<<"Chuoi ma hoa: "<<C;
	P = "";
	for(int i=0;i<C.size();i++){
		int k = KT_S(K[i]);
		int p = (KT_S(C[i]) - k) % 26;
		if(p<0){
			p+=26;
		}
		P += S_KT(p);
	}
	cout<<"\nGiai ma: "<<P;
	
}
