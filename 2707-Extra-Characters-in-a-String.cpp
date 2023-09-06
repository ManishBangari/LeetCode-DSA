#include<iostream>
#include<string.h>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int len=s.length();
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());

        vector<int> dp(len+1,0);

        for(int start=len-1;start>=0;start--){

            dp[start] = dp[start+1]+1;
            
            for(int end=start;end<len;end++){
                auto curr = s.substr(start,end - start +1);
                if(dictSet.count(curr)){
                    dp[start]=min(dp[start], dp[end+1]);
                }
            }
        }

        return dp[0];
    }
};