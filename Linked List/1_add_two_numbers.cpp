#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdint.h>
#include <regex>
#include <sstream>
#include <locale>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        int carry = 0;
        while (l1 and l2) {
            int sum = l1->val + l2->val + carry;
            ptr->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            ptr = ptr->next;
        }
        
        while (l1) {
            int sum = l1->val + carry;
            ptr->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            ptr = ptr->next;
        }
        
        while (l2) {
            int sum = l2->val + carry;
            ptr->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            ptr = ptr->next;
        }
        
        if (carry) {
            ptr->next = new ListNode(carry);
        }
        
        return head->next;
    }
};

