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


// 相交的点
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* tempA = headA;
		ListNode* lastNode = NULL;
		while (tempA)
		{
			lastNode = tempA;
			tempA = tempA->next;
		}
		lastNode->next = headB;

		ListNode* quickNode = headA;
		ListNode* slowNode = headA;
		ListNode* intersection = NULL;
		while (quickNode && quickNode->next)
		{
			quickNode = quickNode->next->next;
			slowNode = slowNode->next;
			if (quickNode == slowNode)
			{
				quickNode = headA;
				while (quickNode != slowNode)
				{
					quickNode = quickNode->next;
					slowNode = slowNode->next;
				}
				intersection = quickNode;
				break;
			}
		}
		lastNode->next = NULL;
		return intersection;
	}
};
