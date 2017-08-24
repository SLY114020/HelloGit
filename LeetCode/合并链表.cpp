struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l2;
		ListNode* head = new ListNode(1);
		ListNode* n = head;
		while (l1 != NULL && l2 != NULL)
		{
			
			if (l1->val > l2->val)
			{
				n->next = l2;
				n = l2;
				l2 = l2->next;
			}
			else
			{
				n->next = l1;
				n = l1;
				l1 = l1->next;
			}
		}
		if (l1 == NULL)
		{
			n->next = l2;
		}
		if (l2 == NULL)
		{
			n->next = l1;
		}
		return  head->next;
	}
};
