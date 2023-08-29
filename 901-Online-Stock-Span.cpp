#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {}
    
    int next(int price) {
        int curr_span=1;

        while(!st.empty() && price>=st.top().second){
            curr_span+=st.top().first;
            st.pop();
        }

        st.push({curr_span, price});
        return st.top().first;
    }
};