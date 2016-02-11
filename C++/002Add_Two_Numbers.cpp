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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
	    ListNode *pResult = NULL;
	    ListNode *p = l1;
	    ListNode *q = l2;

	    //check if first or second equals to NULL
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
	    int carry = 0;
	    while ((p != NULL) && (q != NULL)) {
		
		    int sum = p->val + q->val + carry;
		    if (sum > 9) {
			    carry = 1;
			    sum = sum - 10;
		    }else {
			    carry = 0;
		    }
		
		    if (result == NULL) {
			    result = new ListNode(sum);
			    pResult = result;
		    }else {
			    pResult->next = new ListNode(sum);
			    pResult = pResult->next;
		    }

		    p = p->next;
		    q = q->next;
	    }

	    if (p == NULL) p = q;

	    while (p != NULL) {
		    int sum = p->val + carry;
		    if (sum > 9) {
			    carry = 1;
			    sum = sum - 10;
		    }else {
			    carry = 0;
		    }

		    pResult->next = new ListNode(sum);
		    pResult = pResult->next;
		    p = p->next;
        }

        if (carry) pResult->next = new ListNode(1);

	    return result;
    }
};