class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 1;
        int count = 0;
        while(n>0){
            int x = n&i;
            if(x)count++;
            n = n>>1;
        }
        return count;
    }
};
