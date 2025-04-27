#include<bits/stdc++.h>
using namespace std;

char KT_S(char c){
	return c-'A';
}

char S_KT(int n){
	return 'A'+n;
}

int main(){
	string P,C; 
	int a,b;
	cout<<"Nhap chuoi plaintext: ";getline(cin,P);
	do{
		cout<<"Nhap a: ";cin>>a;	
	}while(a%2==0 || a%13==0);
	
	cout<<"Nhap b: ";cin>>b;
	//Ma hoa
	for(int i=0;i<P.size();i++){
		int p=KT_S(P[i]);
		int c=(a*p+b)%26;
		C=C+S_KT(c);
	}
	cout<<"Chuoi ma hoa: "<<C;
	//GIAI MA
		//Tim a^-1
	int nghichdao;
	P = "";
	for(int i=1;i<26;i+=2){
		if(a*i%26==1){
			nghichdao=i;
			break;
		}
	}
	for(int i=0;i<C.size();i++){
		int c=KT_S(C[i]);
		int p=nghichdao*(c-b)%26;
		if(p<0) p+=26;	//danh cho truong hop am
		P=P+S_KT(p);
	}
	
	cout<<"\nChuoi giai ma: "<<P;
	
	
}

