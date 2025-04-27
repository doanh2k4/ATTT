#include<bits/stdc++.h>
using namespace std;

int main(){
	string P, C;
	string P1="", P2="";
	cout<<"Nhap plaintext: "; getline(cin,P);
	for(int i=0;i<P.size();i++){
		if(i%2==0){
			P1+=P[i];
		}else{
			P2+=P[i];
		}
	}
	C = P1 + P2;
	cout<<"P1: "<<P1<<endl;
	cout<<"P2: "<<P2<<endl;
	cout<<"Chuoi ma hoa: "<<P1 + P2<<endl;
	
	string h1 = "", h2 = "", P = "";
	int n;
	if(C.size() % 2 == 0){
		n = 0;
	}else{
		n = 1;
	}
	for(int i=0;i<C.size();i++){
		if(i< C.size()/2 + n){
			h1 += C[i];
		}
	}
}
