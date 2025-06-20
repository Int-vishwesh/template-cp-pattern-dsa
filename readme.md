# template Dsa or patterns personal documentation

- basically , the idea is to catchup again the concept that i might get forget after solving a questions on leetcode or other platforms.
- for revision purpose (notebook)

---

### Linked List

##### singly linked list

```
Struct ListNode {
 int val;
 ListNode* next;
 listNode(int x) : val(x), next(nullptr) {}
 };
```

##### traversing

```cpp
ListNode* head = new ListNode(1);
ListNode* head = new ListNode(2);
ListNode* cur = head; //temp ptr
while (cur != nullptr) {
  cout < cur-> val;
  cur = cur-> next;
  }
```

##### deletion

skipping the node to be deleted, not removing from memory

```cpp
 ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next; //skipping head or starting untill its same
        }

        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
```

default if head is given

```cpp
ListNode* cur = head;
while (cur != nullptr && cur-> next != nullptr) {
  ListNode* next_node = cur-> next;
  cur-> next = next_node-> next;
  delete next_node;
  }
```

if node is given which is to be deleted (basically overwriiting and then disconnecting)

```cpp
node->val=node->next->val;
ListNode* del=node->next;
node->next=node->next->next;
delete del;
```

##### middle of list

```cpp
ListNode* middleNode(ListNode* head) {
        int size=0;
        ListNode* count = head;
        while(count!=nullptr)
        {
          size++;
          count=count->next;
        }

        int half=size/2;
        int i=0;
        while(i<half)
        {
          head=head->next;
          i++;
        }
    return head;
    }
```

---

### cyclic sorting

i.e. to put the element at their respective indexes, 1 at 1, 3 at 3. 6 at 6 ....

```cpp
      int i = 0;
      while (i < nums.size()) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            }
            else {
                i++;
            }
      }
```

<hr>
---
