class Solution {
public:
    int mySqrt(int x) {
        long long int high = x;
        long long int low = 0;
        long long int mid;
        long long int ans;
        while(low<=high){
            mid = (high+low)/2;
            long long int temp = mid*mid;
            if(temp == x){
                return mid;
            }
            else if(temp>x)high = mid-1;
            else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};
