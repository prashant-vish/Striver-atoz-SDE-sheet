class Solution {
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        
        int sum=0;
        for(int i=1;i<=n;i++){
            int cnt=0;
            while(i!=0){
                i=i&(i-1);
                cnt++;
            }
            sum+=cnt;
        
    }
        
        return sum;
    }
};