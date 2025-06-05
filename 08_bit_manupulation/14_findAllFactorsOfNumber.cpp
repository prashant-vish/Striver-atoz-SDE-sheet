#include <bits/stdc++.h>
using namespace std;

// brute force 
// time complexity - O(n)
// space complexity - O(1)

class Solution {
  public:
    void print_divisors(int n) {
        
        for(int i=1;i<=n;i++){
            if(n%i==0){
                cout<<i<<" ";
            }
        }
        
        return ;
    }
};

// optimal solution 
// time complexity - O(sqrt(N)+sqrt(N)log(sqrt(n)))
// space complexity - O(sqrt(N))

class Solution
{
public:
    void print_divisors(int n)
    {

        vector<int> ans;
        for (int i = 1; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                ans.push_back(i);
                if (i != n / i)
                    ans.push_back(n / i);
            }
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        return;
    }
};