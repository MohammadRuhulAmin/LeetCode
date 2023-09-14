class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        for(int i = 0;i<s.size();i++){
        	string temp = s.substr(i,k);
        	if(temp.length() == k)
            st.insert(temp);
        }
        return st.size() == pow(2,k)?true:false;
    }
};