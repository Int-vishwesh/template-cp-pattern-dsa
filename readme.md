# template - Dsa - patterns (personal documentation)

> basically , the idea is to catchup or grasp again the concept that i might get forget after solving a questions on leetcode or other platforms.
> - for revision purpose (notebook)
> - Quick reference 
> - language C++

---

|table of content     |                                |                                     |
|---------------------|--------------------------------|-------------------------------------|
| data structures     | [Array/vectors]()                      |           |
|                     | [linked list](#linked-list)    | traversal, delettion, middle, reverse |
|                     | [stack](#stack)                |           |
| Patterns            | [Cyclic sorting](#cyclic-sorting) |        | 
|                     | [sliding window](#sliding-window)     |                         |
| Algorithms          |                  |                         |
|                     |                  |                         |

---
> ## Data Structures 
### Linked List

```cpp
//singly linkedlist
Struct ListNode {
 int val;
 ListNode* next;
 listNode(int x) : val(x), next(nullptr) {}
 };
```
<br>

> traversing
```cpp
ListNode* head = new ListNode(1);
ListNode* head = new ListNode(2);
ListNode* cur = head; //temp ptr
while (cur != nullptr) {
  cout < cur-> val;
  cur = cur-> next;
  }
```
<br>

> deletion

- skipping the node to be deleted, not removing from memory
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

- default if head is given
```cpp
ListNode* cur = head;
while (cur != nullptr && cur-> next != nullptr) {
  ListNode* next_node = cur-> next;
  cur-> next = next_node-> next;
  delete next_node;
  }
```

- if node is given which is to be deleted (basically overwriiting and then disconnecting)
```cpp
node->val=node->next->val;
ListNode* del=node->next;
node->next=node->next->next;
delete del;
```
<br>

> middle of list
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
<br>

> reversing
```cpp
ListNode* reverseList(ListNode* head) {
      ListNode* ans = nullptr;
      ListNode* curr = head;
      
      while (curr != nullptr) {
          ListNode* Temp = curr->next; 
          curr->next = ans;        
          ans = curr;          
          curr = Temp;      
      }
      
      return ans;
      }
```

### Stacks
> identification
- stack is applied if its array (most probably)
- when inner loops depends on outer loop i.e. j on i like int j=i;
- can give a improvised solution for bruute force approach if above condition is there


---

> ## Patterns
### cyclic sorting
> identification
- generally applied on data structures with indices
- when we need to sort data in a cyclic manner

> structure

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
### sliding window
> identification
- used when we need to find the maximum or minimum value in a subarray of a given size
- generally applied on array or string

> bruteforce fixed sliding window (non scalable)

```cpp
// NOTE - its not a sliding window but it seems the same when all test case have a fixed size window
int first_targetsum_subarray(vector<int>& nums, int targetsum)
{
    for(int i=0; i<nums.size()-3; i++)
    {
        if(nums[i]+nums[i+1]+nums[i+2]==targetsum) //window size = triplet here
        {
            return true;
        }
        else{
            false;
        }
    }
}
```

> fixed sliding window
```cpp
double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        //first window for one time sum
        for(int i=0; i<k; i++){
          sum+=nums[i];
        }

        int maxx = sum;

        //now iterative with adding from forward and removing from last
        for(int i=k; i<nums.size(); i++)
        {
          sum += nums[i]-nums[i-k];
          if(sum>maxx){
            maxx=sum;
          }
        }
        double ans = (double)maxx/k;
    return ans;
    }

```

---

> ## Algorithms
