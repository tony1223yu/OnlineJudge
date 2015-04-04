/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int tmp = 0;
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *curr = NULL;

        while (l1 != NULL && l2 != NULL)
        {
            tmp = carry + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            
            carry = tmp / 10;
            tmp = tmp % 10;

            if (curr == NULL)
            {
                curr = ans;
                curr -> val = tmp;
            }
            else
            {
                curr -> next = new ListNode(tmp);
                curr = curr -> next;
            }
        }

        if (l1 != NULL)
        {
            while (l1)
            {
                tmp = carry + l1->val;

                carry = tmp / 10;
                tmp = tmp % 10;

                l1 = l1 -> next;
                curr -> next = new ListNode(tmp);
                curr = curr -> next;
            }
        }
        else if (l2 != NULL)
        {
            while (l2)
            {
                tmp = carry + l2->val;

                carry = tmp / 10;
                tmp = tmp % 10;

                l2 = l2 -> next;
                curr -> next = new ListNode(tmp);
                curr = curr -> next;
            }
        }

        if (carry)
            curr -> next = new ListNode(carry);

        return ans;
    }
};
