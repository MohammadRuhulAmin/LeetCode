#include<bits/stdc++.h>
using namespace std;
int main(){

	
	pair<int,string>person;
	person = make_pair(1,"Ruhul Amin");
	cout << person.first <<" " << person.second;
	pair<int,string>info;
	info = {12,"Sakib"};
	cout << info.first << " " << info.second << endl;
	pair<int,string> age_name[3];
	age_name[0].first = 12;
	age_name[0].second = "Ruhul";
	age_name[1].first = 14;
	age_name[1].second = "Sakib";
	age_name[2].first = 15;
	age_name[2].second = "Kallol";
	
	cout << endl;
	
	for(int i = 0;i<3;i++){
		cout << age_name[i].first << " " << age_name[i].second << endl;
	}
	swap(age_name[0],age_name[2]);
	cout << endl;
	for(int i = 0;i<3;i++){
		cout << age_name[i].first << " " << age_name[i].second << endl;
	}
//	
//	int length;
//	cin >> length;
//	pair<string,int>myInfo[length];
//	for(int i = 0;i<length;i++){
//		cin >> myInfo[i].first >> myInfo[i].second;
//	}
//	
//	cout << endl;
//	for(int i = 0;i<length;i++){
//		cout << myInfo[i].first << " " << myInfo[i].second << endl;
//	}
//	
//	swap(myInfo[1],myInfo[2]);
//	cout << endl;
//	for(int i = 0;i<length;i++){
//		cout << myInfo[i].first << " " << myInfo[i].second << endl;
//	}
//	
	
	vector<pair<int,string> >nameInf;
	int lengthx;cin >> lengthx;
	for(int i = 0;i<lengthx;i++){
		int x;
		string y;
		cin >> x >> y;
		pair<int,string> mp;
		mp = make_pair(x,y);
		nameInf.push_back(mp);
	}
	
	for(int i = 0;i<lengthx;i++){
		cout << nameInf[i].first << " " << nameInf[i].second << endl;
	}
	
	
	return 0;
}
