#include<bits/stdc++.h>
using namespace std;


int main(){
	map <string,int> myMap;
	myMap.insert({"Ruhul",12});
	myMap.insert({"Sakib",100});
	map<string,int>::iterator it;
	for(it = myMap.begin();it!= myMap.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	
	cout << myMap.count("Ruhul"); // if count returns 1 the key is exists in map otherwise it is not ! 
	
	return 0;
}
