class Solution {
public:
    bool isPalindrome(int x) {
      int temp = x;
      long long int rev = 0;
      while(x>0){
          int l = x%10;
          x/=10;
          rev*=10;
          rev += l;
          
      }
        if(rev == temp)return true;
        return false;
    }
};
