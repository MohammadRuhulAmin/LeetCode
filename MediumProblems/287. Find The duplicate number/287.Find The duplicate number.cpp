#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int range = nums.size();
    map<int,int>data_set;
    for(int i = 0;i<range;i++){
    	map<int,int>::iterator it = data_set.find(nums[i]);
    	if(it == data_set.end()){
    		data_set[nums[i]] = i;
		}
		else if(it !=data_set.end())return it->first;
    	
	}
	return false;
}

int main(){
	vector<int>nums;
	int range;
	cin  >> range;
	for(int i = 0;i<range;i++){
		int x;cin >> x;
		nums.push_back(x);
	}
	cout << findDuplicate(nums);
	return 0;
}