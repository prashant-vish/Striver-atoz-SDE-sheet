#include <bits/stdc++.h>
using namespace std;
class Solution
{

    void selectionSort(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {

            int j = i;
            int k = i;

            while (j < n)
            {

                if (arr[j] < arr[k])
                {
                    k = j;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            swap(arr[i], arr[k]);
        }
    }
};