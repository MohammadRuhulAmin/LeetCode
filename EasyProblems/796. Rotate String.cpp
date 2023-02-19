#include<bits/stdc++.h>
using namespace std;


bool rotateString(string s, string goal) {
	string ts = s,tGoal = goal;
	sort(ts.begin(),ts.end());
	sort(tGoal.begin(),tGoal.end());
	if(ts != tGoal)return false;
	else{
		int len = goal.length();
		int r = 0;
		int l = 0;
		string ls = "",rs = "",ts = "";
		while(r<len){
			ls = "",rs = "",ts = "";
			for(int i = r;i<len;i++)rs+=goal[i];
			for(int i = l;i<r;i++)ls += goal[i];
			ts = rs + ls;
			cout << ts << endl;
			if(ts == s)return true;
			
			r++;
		}
		return false;
	}      
}
int main(){
	
	string s,goal;
	cin >> s >> goal;
	cout << rotateString(s,goal);
	
	return 0;
}
