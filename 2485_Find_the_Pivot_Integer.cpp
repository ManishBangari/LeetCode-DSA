#include<iostream>

using namespace std;

class Solution {
public:
    int x=-1;
    int pivotInteger(int n) {

        int totSum=(n*(n+1))/2;
        int left=totSum,right=n, i=n;

        while(i>=n/2){
            if(left==right) return i;
            else{
                left-=i;
                --i;
                right+=i;
            } 
        }

        return -1;
    }
};