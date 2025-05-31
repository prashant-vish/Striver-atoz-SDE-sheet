



// Brute force 
// time complexity : n*2^31;

class Solution {

  public:
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