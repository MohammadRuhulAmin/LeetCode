class Solution {
public:
    int romanToInt(string s) {
        // MCMXCIV
        // 1000+900 +90+4
        int ans = 0;
        int length = s.length();
        vector< pair<char,int> > rn;
        rn.push_back(make_pair('I',1));
        rn.push_back(make_pair('V',5));
        rn.push_back(make_pair('X',10));
        rn.push_back(make_pair('L',50));
        rn.push_back(make_pair('C',100));
        rn.push_back(make_pair('D',500));
        rn.push_back(make_pair('M',1000));
        bool firstTake = true;
        int prev = 0;
        for(int i = length-1;i>=0;i--){
            char x = s[i];
            for(int j = 0;j<7;j++){
                if(x == rn[j].first){
                    if(firstTake){
                        firstTake = false;
                        prev = rn[j].second;
                    }
                    if(prev>rn[j].second){
                        ans-=rn[j].second;
                        
                    }
                    else ans += rn[j].second;
                    prev = rn[j].second;
                }
            }
        }
        return ans;
    }
};
