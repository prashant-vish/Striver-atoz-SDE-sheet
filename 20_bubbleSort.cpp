// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        int flag;
        for (int i = 0; i < n - 1; i++)
        {

            flag = 0;
            for (int j = 0; j < n - 1 - i; j++)
            {

                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
    }
};