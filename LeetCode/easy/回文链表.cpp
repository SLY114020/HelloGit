class Solution {
public:
	bool isPalindrome(ListNode* head) {
		bool needcheck = true;
		return checkIsResever(head, head, needcheck);
	}
	bool checkAndMove(ListNode* head, ListNode*& curHead)
	{
		if ((curHead)->val == head->val)
		{
			curHead = curHead->next;
			return true;
		}
		return false;
	}
	bool checkIsResever(ListNode* head, ListNode*& curHead, bool& needcheck)
	{
		if (head->next)
		{
			bool ret = checkIsResever(head->next, curHead, needcheck);
			if (!ret)
			{
				needcheck = false;
				return false;
			}
			if (!needcheck)
				return ret;
			if (head == curHead)
			{
				needcheck = false;
				return true;
			}
			if ((curHead)->next == head)
			{
				needcheck = false;
			}
			return checkAndMove(head, curHead);
		}
		return checkAndMove(head, curHead);
	}
};