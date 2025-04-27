#include<bits/stdc++.h>
using namespace std;

int KT_S(char c){
	return c-'A';
}

char S_KT(int n){
	return 'A'+n;
}

int main(){
//	string P;
//	string K;
//	cout<<"Nhap plain text: ";getline(cin,P);
//	cout<<"Nhap K: ";getline(cin,K);
//	string chuoimoi="";
//	while(K.size()<P.size()){
//		P+=K;
//	}
//	cout<<P;
//	for(int i=0;i<P.size();i++){
//		int cm = (KT_S(P[i])+KT_S(K[i]))%26;
//		chuoimoi+=S_KT(cm);
//	}
//	cout<<"\nChuoi ma hoa: "<<chuoimoi;
	string P,C = "",K;
	cout<<"Nhap chuoi plaintext: ";getline(cin,P);
	cout<<"Nhap chuoi khoa K: ";getline(cin,K);
	//Ma hoa
	int j=0;
	for(int i=0;i<P.size();i++){
		int p=KT_S(P[i]);
		int k=KT_S(K[j]);
		int c=(p+k)%26;
		C=C+S_KT(c);
		j++;
		if(j==K.size()) j=0;
	}
	cout<<"Chuoi ma hoa: "<<C;
	
	j=0;
	P="";
	
	for(int i=0;i<C.size();i++){
		int c=KT_S(C[i]);
		int k=KT_S(K[j]);
		int p=(c-k+26)%26;
		P=P+S_KT(p);
		j++;
		if(j==K.size()) j=0;
	}
	cout<<"\NChuoi giai ma: "<<P;	

}

