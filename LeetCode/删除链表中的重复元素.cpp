class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* temp = head;
		ListNode* pre = NULL;
		std::set<int> s;
		while (temp)
		{
			auto it = s.find(temp->val);
			if (it != s.end())
			{
				pre->next = temp->next;
			}
			else
			{
				s.insert(temp->val);
				pre = temp;
			}
			temp = temp->next;
		}
		return head;
	}
};