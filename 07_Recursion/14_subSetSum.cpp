#include <bits/stdc++.h>
using namespace std;

// time complexity O(2^n+2^n*log2^n)
// space complexity O(n)


void solve(vector<int> &num, int idx, int sum, vector<int> &ans)
{

    if (idx >= num.size())
    {
        ans.push_back(sum);
        return;
    }

    sum += num[idx];
    solve(num, idx + 1, sum, ans);
    sum -= num[idx];

    solve(num, idx + 1, sum, ans);
}

vector<int> subsetSum(vector<int> &num)
{

    vector<int> ans;

    solve(num, 0, 0, ans);
    sort(ans.begin(), ans.end());

    return ans;
}