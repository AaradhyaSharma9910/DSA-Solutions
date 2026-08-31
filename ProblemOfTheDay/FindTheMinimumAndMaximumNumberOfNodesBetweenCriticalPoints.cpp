#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> result = {-1, -1};

        int minDistance = INT_MAX;

        ListNode* previousNode = head;
        ListNode* currentNode = head->next;

        int currentIndex = 1;
        int previousCriticalIndex = -1;
        int firstCriticalIndex = -1;

        while (currentNode->next != nullptr) {

            // Check if current node is a critical point
            if ((currentNode->val < previousNode->val &&
                 currentNode->val < currentNode->next->val) ||

                (currentNode->val > previousNode->val &&
                 currentNode->val > currentNode->next->val)) {

                // First critical point
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = currentIndex;
                }

                // Calculate distance from previous critical point
                if (previousCriticalIndex != -1) {
                    minDistance = min(
                        minDistance,
                        currentIndex - previousCriticalIndex
                    );
                }

                previousCriticalIndex = currentIndex;
            }

            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        // If at least two critical points exist
        if (minDistance != INT_MAX) {
            int maxDistance =
                previousCriticalIndex - firstCriticalIndex;

            result = {minDistance, maxDistance};
        }

        return result;
    }
};

int main() {

    // Example: [5, 3, 1, 2, 5, 1, 2]

    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    Solution obj;

    vector<int> ans = obj.nodesBetweenCriticalPoints(head);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}