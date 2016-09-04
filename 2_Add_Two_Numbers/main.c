/*
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createListNode()
{
	struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));

	printf("malloc %p\n", node);
	node->val = 0;
	node->next = NULL;
	return node;
}

struct ListNode *getValuedListNode(int val)
{
	struct ListNode *node = createListNode();

	node->val = val;
	return node;
}

struct ListNode* listCombine(struct ListNode *list, struct ListNode *l1, struct ListNode *l2, int carry)
{
	if (!l1 && !l2) {
		if (list)
			free(list);
		return list;
	}

	if (list) {
		int l1_val = 0;
		int l2_val = 0;
		struct ListNode *l1_next = NULL;
		struct ListNode *l2_next = NULL;

		if (l1) {
			l1_val = l1->val;
			l1_next = l1->next;
		}
		if (l2) {
			l2_val = l2->val;
			l2_next = l2->next;
		}

		list->val = l1_val + l2_val + carry;

		if (list->val >= 10) {
			list->val %= 10;
			carry = 1;
		} else
			carry = 0;

		if (l1_next || l2_next)
			list->next = listCombine(createListNode(), l1_next, l2_next, carry);
		else {
			if (carry == 1)
				list->next = getValuedListNode(1);
			else
				list->next = NULL;
		}
	}
	return list;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* list = createListNode();

	if (list) {
		list = listCombine(list, l1, l2, 0);
	}
	return list;
}

void cleanUp(struct ListNode *list)
{
	while (list) {
		struct ListNode* next = list->next;
		printf("free %p\n", list);
		free(list);
		list = next;
	}
}

int main() {
	struct ListNode a1;
	struct ListNode a2;
	struct ListNode a3;
	struct ListNode b1;
	struct ListNode b2;
	struct ListNode b3;
	struct ListNode *sum = NULL;
	struct ListNode *list = NULL;

	a1.val = 1;
	a1.next = NULL;

	b1.val = 9;
	b1.next = NULL;

	list = sum = addTwoNumbers(&a1, &b1);

	while (sum) {
		printf("%d ", sum->val);
		sum = sum->next;
	}
	printf("\n");

	cleanUp(list);

	return 0;
}

