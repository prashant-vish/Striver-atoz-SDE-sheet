//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long ans=0;
        
        for(int i=1;i<=N;i++){
            
            int divisor=N/i;
            
            ans=ans+divisor*i;
        }
        return ans;
    }
};