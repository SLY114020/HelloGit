class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* newHead = head;
		ListNode* preNode = NULL;
		while (head)
		{
			ListNode* curhead = head;
			head = head->next;
			curhead->next = preNode;
			preNode = curhead;
		}
		return preNode;
	}
};