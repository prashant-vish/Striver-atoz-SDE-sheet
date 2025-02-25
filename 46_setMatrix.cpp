#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            vector<pair<int, int>> hash;
            int m=matrix.size();
            int n=matrix[0].size();
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==0){
                        hash.push_back({i,j});
                    }
                }
            }
            for(auto it:hash){
                int row=it.first;
                int col=it.second;
                for(int i=0;i<n;i++){
                    matrix[row][i]=0;
                }
                 for(int i=0;i<m;i++){
                    matrix[i][col]=0;
                }
            }
        }
    };