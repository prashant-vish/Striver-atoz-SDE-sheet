class Solution{
    public:
        int evenlyDivides(int N){
            
            int x=N;
            int cnt=0;
            while(N){
                
                int r=N%10;
                if(r!=0&&x%r==0){
                    cnt++;
                }
                N=N/10;
            }
            return cnt;
        }
    };