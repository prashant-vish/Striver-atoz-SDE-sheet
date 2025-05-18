
// Optimal Solution

// Time complexity  2* log(n)
// space complexity log(n) stack space 

class Solution {
public:

    long long countPow(long long a, long long b){
        if(b==0){
            return 1;
        }
        long long half= countPow(a, b/2);
        long long result=(half*half)%(1000000007);

        if(b%2==1){
            result=(a*result)%(1000000007);
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        
        long long even=countPow(5,(n+1)/2);
        long long odd=countPow(4,n/2);
        return (even*odd)%(1000000007);

    }
};