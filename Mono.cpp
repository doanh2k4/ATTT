#include<bits/stdc++.h>
using namespace std;

int KT_S(char c){
	return c-'A';
}

int S_KT(int n){
	return 'A'+n;
}

int main(){
	string P,K,C;
	string bcc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap chuoi Plain text: ";getline(cin,P);
	cout<<"Nhap chuoi K: ";getline(cin,K);
	
	for(int i=0;i<P.size();i++){
//		int j=bcc.find(P[i]);
		int index = KT_S(P[i]);//chuyen sang so
		C+=K[index];
	}
	
	cout<<"Chuoi ma hoa "<<C;
//	P="";
//	cout<<"Nhap chuoi can giai ma: ";getline(cin,C);
//	for(int i=0;i<C.size();i++){
//		for(int j=0;j<K.size();j++){// dung ham find();
//			if(C[i] == K[j]){//tim vi tri cua K trong chuoi ma hoa
//				P+=bcc[j];
//			}
//		}
//	}
//	cout<<"Giai ma: "<<P;

	P="";
	cout<<"\nNhap chuoi can giai ma: ";getline(cin,C);
	for(int i=0;i<C.size();i++){
		int j=K.find(C[i]);
		P+=bcc[j];
	}
	cout<<"Giai ma: "<<P;
}

