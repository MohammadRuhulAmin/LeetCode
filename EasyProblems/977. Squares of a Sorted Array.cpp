#include<bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int len = nums.size()-1;
        int l = 0;
        int r = len;
        for(int i = len;i>=0;i--){
            if(abs(nums[l]) >nums[r] ){
                ans[i] = nums[l]*nums[l];
                l++;
            }
            else{
                ans[i] = nums[r]*nums[r];
                r--;
            }
        }
        return ans;
}

int main(){
	
	vector<int> nums;
	int length;
	cin >> length;
	for(int i = 0;i<length;i++){
		int x;cin >> x;
		nums.push_back(x);
	}	
	vector <int> vr = sortedSquares(nums);
	for(int i = 0;i<vr.size();i++)cout << vr[i] << " ";
	return 0;
}
