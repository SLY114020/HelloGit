class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* quickNode = head;
		ListNode* slowNode = head;
		while (quickNode != NULL && slowNode != NULL)
		{
			if (quickNode->next)
				quickNode = quickNode->next->next;
			else
				return false;
			slowNode = slowNode->next;
			if (quickNode == slowNode)
				return true;
		}
		return false;
	}
};