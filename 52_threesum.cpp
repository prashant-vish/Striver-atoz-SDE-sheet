#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach:
// Time complexity: O(n^3logn)
// Space complexity: O(n)

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {

        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n - 2; i++)
        { // O(n)
            for (int j = i + 1; j < n - 1; j++)
            { // O(n)
                for (int k = j + 1; k < n; k++)
                { // O(n)

                    int sum = arr[i] + arr[j] + arr[k];
                    if (sum == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp); // O(nlogn)
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// Better approach:
// Time complexity: O(n^2*(logn))
// Space complexity: O(n)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {

        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        { // O(n)
            unordered_map<int, int> mpp;
            for (int j = i + 1; j < n; j++)
            { // O(n)

                int rem = -(arr[i] + arr[j]);
                if (mpp.find(rem) != mpp.end())
                { // 0(logn)
                    vector<int> temp = {arr[i], arr[j], rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // O(logn)
                }
                else
                {
                    mpp[arr[j]] = j;
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// Optimal approach:


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {

        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            // remove duplicates:
            if (i != 0 && arr[i] == arr[i - 1])
                continue;

            // moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip the duplicates:
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};