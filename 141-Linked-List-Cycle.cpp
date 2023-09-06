#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next == nullptr)   return false;

        ListNode *tort = head;
        ListNode *hare = head;

        while(hare!=nullptr && hare->next!=nullptr){
            
            hare=hare->next->next;
            tort=tort->next;

            if(hare==tort)   return true;    
        }

        return false;
    }
};