#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==nullptr) return head;
        vector<int> vec;
        int i=1;

        ListNode *temp=new ListNode();
        temp=head;

        while(i<=right){
            if(i>=left) vec.push_back(temp->val); 
            temp=temp->next;
            ++i;
        }

        reverse(vec.begin(), vec.end());

        i=1;
        temp=head;

        while (i <= right) {
            if (i >= left) temp->val = vec[i - left];
            temp = temp->next;
            ++i;
        }

        return head;
    }
};