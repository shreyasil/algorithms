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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        
        while (l1 or l2) {
            if (l1 and l2) {
                if (l1->val < l2->val) {
                    head->next = l1;
                    head = head->next;
                    l1 = l1->next;
                } else {
                    head->next = l2;
                    head = head->next;
                    l2 = l2->next;
                }
            } else if (l1) {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            } else if (l2) {
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            }
        }
        return ptr->next;
    }
};
