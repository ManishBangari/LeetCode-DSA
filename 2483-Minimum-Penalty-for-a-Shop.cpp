#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int prefixSum=0, earliestTime=0;

        for(char c : customers)    prefixSum += c=='Y' ? 1 : 0;
        
        int minTime=prefixSum, time=prefixSum;

        for(int i=0;i<customers.length();i++){
            time+=customers[i]=='Y' ? -1 : 1;

            if(time<minTime){  earliestTime=i+1; minTime=time;   }
        }

        return earliestTime;    
    }
};