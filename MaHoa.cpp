#include<bits/stdc++.h>
using namespace std;

int KT_S(char c){
	return c - 'A';
}
char S_KT(int n){
	return 'A' + n;
}

int main(){
	
	//Mat ma Monoanphal
	string P,C,K;
	int a,b;
	cout<<"Nhap chuoi: "; getline(cin, P);
	string bcc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap K: "; getline(cin, K);
	for(int i =0; i<P.size();i++){
		int index = KT_S(P[i]);
		C+= K[index];
	}
	cout<<"Ma hoa: "<<C;
	
	P="";
	for(int i =0; i<C.size();i++){
		for(int j =0; j<K.size(); j++){
			if(C[i] == K[j]){
				P+=bcc[j];
			}
		}
	}
	cout<<"\nGiai ma: "<<P;
	
	//Mat ma Affine
//	string P,C;
//	int a,b;
//	cout<<"Nhap chuoi: "; getline(cin, P);
//	do{
//		cout<<"Nhap khoa a: "; cin>>a;
//	} while( a%2 == 0 || a == 13 );
//	cout<<"Nhap khoa b: "; cin>>b;
//	
//	for(int i = 0; i<P.size();i++){
//		int p = KT_S(P[i]);
//		int ct = (a*p+b)%26;
//		C += S_KT(ct);
//	}
//	cout<<"Chuoi ma hoa: "<<C;
//	P = "";
//	int nghichdao;
//	for(int i = 1; i<26; i+=2){
//		if((i*a)%26 == 1){
//			nghichdao = i;
//			break;
//		}
//	}
//	for(int i = 0; i<C.size();i++){
//		int c = KT_S(C[i]);
//		int p = nghichdao*(c - b)%26;
//		if(p<0) p+=26;
//		P += S_KT(p);
//	}
//	cout<<endl<<"Chuoi giai ma: "<<P;
	
	
	//Mat ma Caesar
//	string C;
//	cout<<"Nhap chuoi: ";
//	getline(cin,a);
//	int k;
//	cout<<"Nhap K: "; cin>>k;
//	for(int i =0;i<a.size();i++){
//		int p = KT_S(a[i]);
//		int ct = (p+k)%26;
//		C += S_KT(ct);
//	}
//	cout<<"Ma hoa: "<<C<<endl;
//	
//	for(int i =0;i<C.size();i++){
//		int c = KT_S(C[i]);
//		int p = (c - k)%26;
//		if(p<0) p+=26;
//		P += S_KT(p);
//	}
//	cout<<"Giai ma: "<<a<<endl;
}

