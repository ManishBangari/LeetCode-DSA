#include<iostream>
#include<vector>

using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    long long val=1;
    int countOrders(int n) {
        /*  Recurrence Relation : 
            if(n==1)    f(1)=1;
            if(n>1)     f(n)=f(n-1)*n*(2*n-1)
        */

        if(n==1)    return 1;
        else{
           
            val = countOrders(n - 1);
            val = (val * n % MOD) * (2 * n - 1) % MOD; 
            return static_cast<int>(val); 
        }
    }
};