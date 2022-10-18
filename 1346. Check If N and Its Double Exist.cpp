#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    sort(arr.begin(),arr.end());
	int length = arr.size();
        for(int i = 0;i<length;i++){
            int x = arr[i];
            for(int j = 0;j<length;j++){
                if(i!=j){
                    if(x*2 == arr[j] || arr[j]*2 == x)return true;
                }
            }
        }
        return false;
    }
   
};
/*
    -20 -19 -14 -6 0 4 8 14 
*/

//
//int main(){
//	vector<int> arr;
//	int length;
//	cin >> length;
//	for(int i = 0;i<length;i++){
//		int x;
//		cin >> x;
//		arr.push_back(x);
//		
//	}
//	cout << checkIfExist(arr);	
//	
//	
//	return 0;
//}
