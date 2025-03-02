#include <bits/stdc++.h>
using namespace std;


// Brute Force 
// Time complexity O(n*n)
// Space Complexity O(n*n)

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> temp = matrix;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    temp[j][n - i - 1] = matrix[i][j];
                }
            }
            matrix = temp;
        }
};

// Optimal Code 
// Time complexity o(n*n)
// Space Complexity O(1)

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n=matrix.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }
    };