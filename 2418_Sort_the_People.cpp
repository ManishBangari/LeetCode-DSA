#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        map<int, string, greater<int>> nameHeight;
        vector<string> sorted;

        for(int i=0;i<names.size();++i){
            nameHeight[heights[i]] = names[i];
        }

        for(auto it : nameHeight){
            sorted.push_back(it.second);
        }

        return sorted;
    }
};