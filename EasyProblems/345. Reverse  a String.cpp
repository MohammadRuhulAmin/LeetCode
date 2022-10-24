class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        int start = 0;
        int end = length-1;
        while(start<end){
            s[start]^= s[end];
            s[end]^= s[start];
            s[start]^= s[end];
            start++;end--;
            
        }
        for(int i = 0;i<length;i++)cout << s[i];
        
    }
};
