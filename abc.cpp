#include<bits/stdc++.h>
using namespace std;

int KT_S(char c){
	return c-'A';
}

int S_KT(int n){
	return 'A'+n;
}

int main(){
//	int k;
	string s;
	cout<<"Nhap s(s la chu in hoa) = ";
	getline(cin,s);
	int a;
	do{
		cout<<"a = ";
		cin>>a;
	}while(a%2==0 || a%13 ==0);
//	cout<<"k = ";
//	cin>>k;
	//MA HOA
//	for(int i=0;i<s.size();i++){
//		s[i]=KT_S(s[i]);
//		s[i]=(s[i]+k)%26;
//		s[i]=S_KT(s[i]);
//	}
//	cout<<"chuoi sau khi ma hoa: "<<s;
	//GIAI MA
//	for(int i=0;i<s.size();i++){
//		s[i]=KT_S(s[i]);
//		s[i]=(s[i]-k)%26;
//		if(s[i]<0){
//			s[i]=s[i]+26;
//		}
//		s[i]=S_KT(s[i]);
//	}
//	cout<<"\nchuoi truoc khi ma hoa: "<<s;
//	
//	for(int k=0;k<=25;k++){
//		for(int i=0;i<s.size();i++){
//			s[i]=KT_S(s[i]);
//			s[i]=(s[i]-k)%26;
//			if(s[i]<0){
//				s[i]=s[i]+26;
//			}
//			s[i]=S_KT(s[i]);
//		}
//		cout<<"\nchuoi giai ma: "<<s<<" voi k = "<<endl;
//			
//	}
	
	for(int k=1;k<=25;k++){
		string c = "";
		for(int i=0;i<s.size();i++){
			int p =KT_S(s[i]);
			int ct=(p-k)%26;
			if(ct<0){
				ct=ct+26;
			}
			c+=S_KT(ct);
		}
		cout<<"\nchuoi giai ma: "<<c<<" voi k = "<<k;
//		s = "";
	}
//	
//	string P,C; int K;
//	cout<<"Nhap chuoi plaintext: ";getline(cin,P);
//	cout<<"Nhap K: ";cin>>K;
//	for(int i=0;i<P.size();i++){
//		int p=KT_S(P[i]);
//		int c=(p+K)%26;
//		C+=S_KT(c);
//	}
//	cout<<"Chuoi ma hoa: "<<C;
}

