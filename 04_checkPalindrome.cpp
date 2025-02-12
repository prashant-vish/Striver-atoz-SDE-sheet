class Solution {
    public:
        bool isPalindrome(int x) {
            
            if(x<0)
                return false;
            long long num=x;
            long long sum=0;
            while(num){
               long long  r=num%10;
                sum=sum*10+r;
                num=num/10;
            }
            if(sum==x){
                return true;
            }
            else
                return false;
        }
    };