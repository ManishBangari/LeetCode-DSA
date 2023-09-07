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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return nullptr;
        vector<int> vec;

        ListNode *temp = new ListNode();
        temp=head;

        while(temp!=nullptr){
            if(temp->val!=val)  vec.push_back(temp->val);
            temp=temp->next;
        }

        ListNode *newHead=nullptr;
        temp=head;

        for(int i : vec){
            ListNode *newNode = new ListNode(i);
            if(newHead==nullptr){
                newHead=newNode;
                temp=newHead;
            }else{
                temp->next=newNode;
                temp=temp->next;
            }
        }

        return newHead;
    }
};