#include<bits/stdc++.h>
using namespace std;
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    map<int,int>table1;
    map<int,int>table2;
    int count = 0;
    for(const auto&num1:nums1){
    	for(const auto&num2:nums2){
    		int sum = num1+num2;
    		if(table1.find(sum) !=table1.end())table1[sum]++;
    		else table1[sum] = 1;
		}
	}
	cout << endl << "first table \n";
	for(const auto&ite:table1){
		cout << ite.first << " " << ite.second << endl;
	}
	cout << endl;
	for(const auto&num3:nums3){
		for(const auto&num4:nums4){
			int sum = num3+num4;
			sum*=-1;
			if(table1.find(sum) != table1.end()){
				count += table1[sum];
			}
		}
	}

	return count;
}
int main(){
	vector<int>nums1;
	vector<int>nums2;
	vector<int>nums3;
	vector<int>nums4;
	int range1,range2,range3,range4;
	cin >> range1;
	for(int i = 0;i<range1;i++){
		int x;cin >> x;
		nums1.push_back(x);
	}
	cin >> range2;
	for(int i = 0;i<range2;i++){
		int x;cin >> x;
		nums2.push_back(x);
	}
	cin >> range3;
	for(int i = 0;i<range3;i++){
		int x;cin >> x;
		nums3.push_back(x);
	}
	cin >> range4;
	for(int i = 0;i<range4;i++){
		int x;cin >> x;
		nums4.push_back(x);
	}
	cout << fourSumCount(nums1,nums2,nums3,nums4);
	return 0;
}