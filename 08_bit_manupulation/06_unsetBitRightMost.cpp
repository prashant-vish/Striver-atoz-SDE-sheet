class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int t=n;
        int i=0;
        int mini=0;
        while(n){
            i++;
            if(!mini && n%2==0){
                mini=i;
            }
            n=n/2;
        }
        
        return (!mini)?t|(1<<(i)):t|(1<<(mini-1));
    }
};