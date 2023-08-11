#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<int> count(amount+1);

        count[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                count[j] += count[j - coins[i]];
            }
        }

        return count[amount];
    }
};
