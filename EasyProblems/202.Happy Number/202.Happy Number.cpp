class Solution {
public:
    int digitSum(int n,int sum){
	if(n > 0){
		sum += pow(n%10,2);
		return digitSum(n/10,sum);	
	}
	return sum;
}

bool isHappy(int n){
	unordered_map<int,int>mp;
	int temp = 0;
	while(true){
		temp = digitSum(n,0);
		//cout << temp << endl;
		if(temp == 1)return true;
		if(mp.find(temp)!=mp.end())return false;
		else{
			n = temp;
			mp[temp]++;	
		}
		
	}
	return false;
}
};


