vector<int>ans;
    double range= nums.size();
    double cal = range/3;
    int finalRange = floor(cal);
    map<int,int>mp;
    for(int i = 0;i<nums.size();i++){
    	int item = nums[i];
    	if(mp.find(item) == mp.end())mp[item] = 1;
    	else mp[item]++;
	}
	for(const auto&ite:mp){
		if(ite.second>finalRange)ans.push_back(ite.first);
	}
    
	
    
    return ans;