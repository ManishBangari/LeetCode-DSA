#include<iostream>
#include<vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        vector<int> candies(ratings.size(),1);

        if(size<2)  return 1;
        for(int i=1;i<size;i++){
            if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        }        
        
        for(int i : candies)    cout<<i<<' ';
        cout<<"\n";

        for(int i=size-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) 
            candies[i] = i>=1 ? max(candies[i],candies[i+1]+1) : candies[i+1]+1;
        }

        for(int i : candies)    cout<<i<<' ';

        return accumulate(candies.begin(),candies.end(),0);
    }
};