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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> Nodes;
        if (head == nullptr) {
            while (k-- > 0) {
                Nodes.push_back(nullptr);
            }
            return Nodes;
        }

        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            temp = temp->next;
            ++n;
        }

        int maxDiv = n / k;
        int rem = n % k;

        temp = head;

        for (int i = 0; i < k; i++) {
            ListNode* newHead = temp;
            int size = maxDiv + (rem > 0 ? 1 : 0);

            for (int j = 0; j < size - 1; j++) {
                temp = temp->next;
            }

            if (temp != nullptr) {
                ListNode* nextNode = temp->next;
                temp->next = nullptr;
                temp = nextNode;
            }

            Nodes.push_back(newHead);
            rem--;
        }

        return Nodes;
    }
};
