#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(int &a, int &b){
        // Convert both integers to strings
        string strA = to_string(a);
        string strB = to_string(b);
    
        // Concatenate the strings in two different orders
        string order1 = strA + strB;
        string order2 = strB + strA;
    
        // Compare the concatenated strings to determine the order
        return order1 > order2;
    }

    string largestNumber(vector<int>& nums) {
        
        string largestNum="";
        
        sort(nums.begin(), nums.end(), cmp);

        for(int i : nums)   largestNum+=to_string(i);
        
        // Remove leading zeros from the result
        int i = 0;
        while (i < largestNum.length() - 1 && largestNum[i] == '0') i++;
    
        return largestNum.substr(i);
    }
};