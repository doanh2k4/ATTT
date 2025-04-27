#include<bits/stdc++.h>
using namespace std;

//Loai bo chu trung lap trong tu khoa

//Diem them chuoi tren nhung ki tu con lai cua bang chu cai

//Dat chuoi thu duoc vao ma tran 5x5

set<char> str;

string catchuoi(string s){
//	for(int i=0;i<s.size();i++){
//		str.insert(s[i]);
//	}
//	string key = "";
//	for(auto x:str){
//		cout<<" "<<x;
//		key+=x;
//		
//	}
//	return key;	
//	cout<<"\nChuoi moi ne:"<<key;	
	string res = "";
	set<char> st;
	for(auto c:s){
		if(!st.count(c)){
			st.insert(c);
			res+=c;
		}
	}
	return res;
}

int main(){
	string s;
	string bcc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap s: ";getline(cin,s);
//	for(int i=0;i<s.size();i++){
//		str.insert(s[i]);
//	}
//	string key = "";
//	for(auto x:str){
//		cout<<" "<<x;
//		key+=x;
//		
//	}
//	
//	cout<<"\nChuoi moi ne:"<<key;
	s=s+bcc;
	s = catchuoi(s);
	char a[5][5];
	int index = 0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			a[i][j]=s[index];
			index++;
		}
	}
	
	cout<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j];
		}
	}
}

