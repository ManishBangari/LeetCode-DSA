#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        unordered_map<int,vector<int>> ump;

        for(int i=0;i<groupSizes.size();i++){
            int groupSize = groupSizes[i];

            auto it=ump.find(groupSize);
            if(it==ump.end()){
               ump[groupSize] = vector<int>{i};
            }else{
                ump[groupSize].push_back(i); 
            }
        }

        for(auto it : ump){
            vector<int> vec;
            vector<int> v=it.second;

            for(int i=0;i<v.size();i++){
                if(vec.size()==it.first){
                    groups.push_back(vec);
                    vec.clear();
                }
                vec.push_back(v[i]);
            }

            if(vec.size()!=0)   groups.push_back(vec);
        }

        return groups;
    }
};