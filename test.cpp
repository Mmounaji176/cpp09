// Definition for singly-linked list.
#include <iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = l1;
        int c = 1;
        int res;
        while(tmp != NULL){
            res += tmp->val * c;
            c *= 10;
            tmp = tmp->next;
        }
        std::cout << res << std::endl;
    }
};

int main()
{
    Solution s;
    s.addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4))));
}