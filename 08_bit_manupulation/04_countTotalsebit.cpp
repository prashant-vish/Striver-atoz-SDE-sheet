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

// Time complexity O(log n)
// Space Compleixity O(1) because recursion will take almost zero space ;


class Solution {
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int findHighestPowerOfTwo(int n){
        int x=0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
    }
    int countSetBits(int n) {
        
        if(n==0){
            return 0;
        }
        
        int maxPowerofTwo=findHighestPowerOfTwo(n);
        int raiseto2=maxPowerofTwo*(1<<(maxPowerofTwo-1));
        int msbBits=n-(1<<maxPowerofTwo)+1;
        
        
        int rest=n-(1<<maxPowerofTwo);
        
        int ans=raiseto2+msbBits+countSetBits(rest);
        
        return ans;
        
    }
};