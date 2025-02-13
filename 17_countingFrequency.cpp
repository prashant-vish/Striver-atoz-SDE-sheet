#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        int array[N] = {0};
        for (int i = 0; i < N; i++)
        {
            if (arr[i] > N)
                continue;
            if (arr[i] <= P)
            {
                array[arr[i] - 1]++;
            }
        }
        arr.clear();
        for (int i = 0; i < N; i++)
        {
            //   cout<< array[i]<<"";
            //   arr[i]=array[i];
            arr.push_back(array[i]);
        }
    }
};