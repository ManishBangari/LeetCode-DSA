#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(),comp);
        int maxLen=0, curr=INT_MIN;

        for(const auto &p : pairs){
            if(p[0]>curr){  maxLen++; curr=p[1];    }
        }
        
        return maxLen;
    }
};