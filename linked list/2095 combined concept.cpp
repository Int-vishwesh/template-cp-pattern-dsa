#include <iostream>
using namespace std;

// Basic singly linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* count = head;
        int size = 0;
        while (count != nullptr) {
            size++;
            count = count->next;
        }

        if (size == 0 || size == 1) {
            return nullptr;
        }

        int half = size / 2;
        ListNode* mid = head;
        ListNode* prev = nullptr;
        int i = 0;
        while (i < half) {
            prev = mid;
            mid = mid->next;
            i++;
        }
        prev->next = mid->next;
        delete mid;
        return head;
    }
};

// Print any linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create initial linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}
