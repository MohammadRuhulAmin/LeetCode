#include <string>
#include <unordered_set>
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s = "hel";
    //decleration with insertion 
    unordered_set<char>mySet(s.begin(),s.end());
    for(char x: mySet){
    	cout << x << " ";
	}
	// for finding any element 
	if(mySet.find('e')!=mySet.end())cout << "Found !";
	
    return 0;
}




