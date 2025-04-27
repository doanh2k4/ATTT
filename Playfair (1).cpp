/*
- loai bo ki tu trung
- Dien cac ki tu con lai trong bang chu cai vao chuoi
- Dat chuoi thu duoc vao ma tran 5x5
*/
#include<bits/stdc++.h>
using namespace std;

char a[5][5];
string KEY, P, C;
string bcc = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

string XoaTrungLap1(string KEY){
	set<char> onlychar;
	string chuoimoi = "";
	for(auto x:KEY){
		if(!onlychar.count(x)){ // neu chua co ky tu moi
			onlychar.insert(x);
			chuoimoi+=x;
		}
	}
	return chuoimoi;
}

string XoaTrungLap2(string KEY){
	for(int i =0; i<KEY.size();i++){
		for(int j =i+1;KEY.size();j++){
			if(KEY[i] == KEY[j]){
				KEY.erase(j,1);
				j--;
			}
		}
	}
	return KEY;
}

/*
	Tim P1, P2
	Neu P1 khac hang, cot voi P2 --> P1 thay = (x1,y2)
		P1 cung hang voi P2 --> P1 = (x1,y1+1 mod 5)
		P1 cung cot voi P2 --> P1 = (x1+1 mod 5,y1)
	*/

void InMaTran(){
	for(int i = 0; i<5; i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cout<<"Nhap khoa: ";
	getline(cin,KEY);
	KEY+=bcc;
	KEY = XoaTrungLap1(KEY);
	
	int index = 0;
	for(int i = 0; i<5; i++){
		for(int j=0;j<5;j++){
			a[i][j] = KEY[index];
			index++;
		}
	}
	InMaTran();
	cout<<"Nhap chuoi plaintext: ";
	getline(cin,P);
	
	//Chuan hoa chuoi plaintext
	for(int i = 0; i < P.size(); i+=2){ // ba lx lo on
		if(P[i] == P[i+1]){
			P.insert(i+1,"X");
		}
	}
	if(P.size() % 2 == 1){	// so luong ky tu trong chuoi le
		P+="X";
	}
	C = P;
	int i1,i2,j1,j2;
	for(int m =0; m<P.size(); m+=2){	// Duyet lan luot 2 ki tu canh nhau
		for(int i = 0; i<5;i++){
			for(int j = 0; j <5; j++){
				if(P[m] == a[i][j]){	//tim P1
					i1 = i;
					j1 = j;
				}
				if(P[m+1] == a[i][j]){
					i2 = i;
					j2 = j;
				}
			}
		}
		//Neu P1 khac hang, cot voi P2 --> P1 thay = (x1,y2)
		if(i1 != i2 && j1 != j2){
			C[m] = a[i1][j2];
			C[m+1] = a[i2][j1];
		} //P1 cung hang voi P2 --> P1 = (x1,y1+1 mod 5)
		else if(i1 == i2){
			C[m] = a[i1][(j1+1) % 5];
			C[m+1] = a[i2][(j2+1) % 5];
		}
		else if(j1 == j2){
			C[m] = a[(i1+1) % 5][j1];
			C[m+1] = a[(i2+1) % 5][j2];
		}
	}
	cout<<"Ma Hoa: "<< C;
}
