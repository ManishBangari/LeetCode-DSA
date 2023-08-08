#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool found=false;
        int r=matrix.size(),c=matrix[0].size();

        for(auto v : matrix){
            if(v[0] > target)     break;
            if(v[0] <= target && v[c-1] >= target){
                auto it = find(v.begin(), v.end(), target);
                if(it != v.end()){    found=true;  break; }
            }
        }

        return found;
    }
};