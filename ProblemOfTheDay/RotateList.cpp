#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // edge cases
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // reduce unnecessary rotations
        k = k % n;

        if (k == 0)
            return head;

        // make linked list circular
        tail->next = head;

        // move to new tail
        int steps = n - k;

        ListNode* newTail = head;

        while (--steps) {
            newTail = newTail->next;
        }

        // new head
        ListNode* newHead = newTail->next;

        // break circular link
        newTail->next = NULL;

        return newHead;
    }
};