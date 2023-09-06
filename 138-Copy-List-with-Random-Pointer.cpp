#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        // Step 1: Create a new node for each original node and insert them in between
        Node* current = head;
        while (current != nullptr) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Step 2: Copy random pointers
        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the two linked lists
        Node* newHead = head->next;
        current = head;
        Node* newCurrent = newHead;
        while (current != nullptr) {
            current->next = current->next->next;
            current = current->next;
            if (newCurrent->next != nullptr) {
                newCurrent->next = newCurrent->next->next;
                newCurrent = newCurrent->next;
            }
        }

        return newHead;
    }
};