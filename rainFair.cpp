#include<bits/stdc++.h>
using namespace std;

int main(){
	string P,C,h1="",h2="";
	cout<<"Nhap chuoi plaintext: ";getline(cin,P);
	for(int i=0;i<P.size();i++){
		if(i%2==0) h1=h1+P[i];
		else h2=h2+P[i];
	}
	C=h1+h2;
	cout<<"Chuoi ma hoa: "<<C;
	cout<<"\nChuoi h1: "<<h1;
	cout<<"\nChuoi h2: "<<h2;
	
	//giai ma
	P="",h1="",h2="";
	//2 truong hop chuoi chan va chuoi le
	int n;
	if(C.size()%2==0){
		n =0;
	}else{
		n=1;
	}
	
	for(int i=0;i<C.size();i++){
		if((i<C.size()/2+n)){
			h1+=C[i];
		}else{
			h2+=C[i];
		}
	}
	cout<<"\nChuoi h1: "<<h1;
	cout<<"\nChuoi h2: "<<h2;
	for(int i=0;i<C.size()/2;i++){
		P=P+h1[i]+h2[i];

	}
	if(n==1){
		P+=h1[h1.size()-1];
	}
	cout<<"Chuoi giai ma: "<<P;
}

