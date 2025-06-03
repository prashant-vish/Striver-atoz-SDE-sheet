#include <bits/stdc++.h>
using namespace std;


vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int xorr=0;
        for(long long int i=0; i<N; i++){
            xorr^=Arr[i];
        }
        
        long long int rgtmost=(xorr&(xorr-1))^xorr;
        
        long long a=0, b=0;
        
        for(long long int i=0; i<N; i++){
            if(Arr[i] & rgtmost){
                a^=Arr[i];
            }else{
                b^=Arr[i];
            }
        }
        
        if(a<b) swap(a, b);
        
        return {a, b};
    }