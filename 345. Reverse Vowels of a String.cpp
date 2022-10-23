class Solution {
public:
    string reverseVowels(string s) {
        int length = s.length();
        char str[length];
        for(int i = 0;i<length;i++)str[i] = s[i];
        int st = 0;
        int end = length-1;
        while(st<end){
            bool lv = false;
            bool rv = false;
            if(str[st] == 'a' || str[st] == 'e' || str[st] == 'i' || str[st] == 'o' || str[st] == 'u' || str[st] == 'A' || str[st] == 'E' 
                || str[st] == 'I' || str[st] == 'O' || str[st] == 'U'){
                lv = true;
            }
            if(str[end] == 'a' || str[end] == 'e' || str[end] == 'i' || str[end] == 'o' || str[end] == 'u' || str[end] == 'A' || str[end] == 'E' 
                || str[end] == 'I' || str[end] == 'O' || str[end] == 'U'){
                rv = true;
            }
            if(lv && rv){
                char temp = str[st];
                str[st] = str[end];
                str[end] = temp;
                st++;
                end--;
            }
            else if(lv && !rv){
                end--;
            }
            else st++;
        }
        string ans = "";
        for(int i = 0;i<length;i++){
            ans +=str[i];
        }
        return ans;
    }
};
