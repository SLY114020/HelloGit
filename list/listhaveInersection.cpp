class Solution{
public:
	bool haveIntersection(ListNode* l1, ListNode* l2){
		if (l1 == NULL || l2 == NULL)
			return false;

		ListNode* lastNode = NULL;
		while (l1)
		{
			lastNode = l1;
			l1 = l1->next;
		}
		lastNode->next = l2;

		ListNode* quickNode = lastNode;
		ListNode* slowNode = lastNode;
		while (quickNode && quickNode)
		{
			ListNode* quickNext = quickNode->next;
			if (!quickNext)
				return false;
			quickNode = quickNext->next;
			slowNode = slowNode->next;
			if (quickNode == slowNode)
				return true;
		}
		return false;
	}
};