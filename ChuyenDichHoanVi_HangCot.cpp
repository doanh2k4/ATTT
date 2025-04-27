#include<bits/stdc++.h>
using namespace std;

char a[5][5];

void InMaTran(){
	for(int i = 0; i<5; i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	string P,C;
	cout<<"Nhap chuoi plaintext: ";
	getline(cin,P);
	
	int index = 0;
	for(int i = 0; i<5; i++){
		for(int j=0;j<5;j++){
			if(index >= P.size()){
				a[i][j] = 'X';
			}else{
				a[i][j] = P[index];
				index++;
			}
		}
	}
	InMaTran();
	
	for(int j=0;j<5;j++){
		for(int i=0;i<5;i++){
			C += a[i][j];
		}
	}
	cout<<"Ma hoa: "<<C<<endl;
	P="";
	index = 0;
	for(int i = 0; i<5; i++){
		for(int j=0;j<5;j++){
			a[j][i] = C[index];
			index++;
		}
	}
	InMaTran();
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			P += a[i][j];	
		}
	}
	cout<<"Giai ma: "<<P<<endl;	
}
