#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector<int> verticalMax;
        int n=grid[0].size(), maxIncr=0;

        for(int i=0;i<n;++i){
            int max=0;
            for(int j=0;j<n;++j){
                if(max<grid[j][i])  max=grid[j][i];
            }
            verticalMax.push_back(max);
        }

        for( auto v : grid){
            int maxHorz=*max_element(v.begin(), v.end());

            for(int i=0;i<n;i++){
                maxIncr+=min(maxHorz,verticalMax[i])-v[i];
            }
        }

        return maxIncr;
    }
};