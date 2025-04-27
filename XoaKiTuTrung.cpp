#include<bits/stdc++.h>
using namespace std;

int main(){
	string K;char A[5][5];
	cout<<"Nhap chuoi khoa K: ";getline(cin,K);	
	string BCC = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	K=K+BCC;
	//Xoa trung lap
	for(int i=0;i<K.size();i++){
		for(int j=i+1;j<K.size();j++){
			if(K[j]==K[i]){
				K.erase(j,1);
				j--;
			}
		}
	}
	cout<<"Chuoi ma hoa: "<<K;
	//Dat vao ma tran
	cout<<"chuoi moi: "<<K;
	int d=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			A[i][j]=K[d];d++;
		}
	}
	cout<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
//Tìm xem P1 xuat hien o vi tri nào trong ma tran (h1,c1)
//Tìm xem P2 xuat hien o vi tri nào trong ma tran (h2,c2)
//
//Neu h1 khác h2 và c1 khác c2 => p1 thay bang (h1,c2)
//
//				p2 thay bang (h2,c1)
//
//Neu h1=h2
//
//Neu c1=c2

//cang gan plaintext bao mat kem
//cang gan duong ke ngang cang che dau tot
}

