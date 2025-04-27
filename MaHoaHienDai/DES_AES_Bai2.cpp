#include<bits/stdc++.h>
using namespace std;

char F(char R,char K){
	return R+K;
}

string tachdoinoisau(string P){
	string C="XX";
	char K[3],L[3],R[3];
	cout<<"Nhap K: ";cin>>K[0];
	R[0]=P[0];
	L[0]=P[1];
	
	//Ma hoa
	for(int i=1;i<=2;i++){
		K[i]=K[0]<<i; // so nguyen << so luong dich
		R[i]=L[i-1]^F(R[i-1],K[i]);
		L[i]=R[i-1];
	}
	C[0]=L[2];
	C[1]=R[2];
	return C;
}

int main(){
	//Dung kieu String chi nhap 2 ki tu
	string P;
	cout<<"Nhap 1 khoi Plaintext P: ";getline(cin,P); // nhap 2 ki tu
	for(int i=0;i<P.size();i+=2)	{
		tachdoinoisau(P[i]);
	}
	cout<<"Khoi ma hoa: "<<C;
	
	
	
	
}

