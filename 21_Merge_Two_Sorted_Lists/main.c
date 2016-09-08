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

struct ListNode* createListNode() {
    return calloc(1, sizeof(struct ListNode));
}

#define DIGESTNODE(cur, node, list) \
{ \
    if (cur) { \
        cur->next = node; \
        cur = cur->next; \
    } else \
        cur = node; \
    node->val = list->val; \
    node = node->next; \
    list = list->next; \
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *cur = NULL, *head = NULL, *node = NULL;
    int order = 0; //0 increase, 1 decrease

    if (!l1 && !l2)
        return NULL;

    /* check order */
    if (l1) {
        if(l1->next) {
            if(l1->val > l1->next->val)
               order = 1;
        }
    } else if (l2) {
        if(l2->next) {
            if(l2->val > l2->next->val)
                order = 1;
        }
    }

    node = createListNode();
    if (!node)
        return NULL;
    head = node;

    while(l1 || l2) {
        if(!node)
            node = createListNode();
        if(!node)
            return NULL;

        if(l1 && l2) {
            if(l1->val < l2->val) {
                if(order == 0) {
                    DIGESTNODE(cur, node, l1);
                    continue;
                } else {
                    DIGESTNODE(cur, node, l2);
                    continue;
                }
            } else {
                if (order == 0) {
                    DIGESTNODE(cur, node, l2);
                    continue;
                } else {
                    DIGESTNODE(cur, node, l1);
                    continue;
                }
            }
        } else if(l1) {
            DIGESTNODE(cur, node, l1);
            continue;
        } else if (l2) {
            DIGESTNODE(cur, node, l2);
            continue;
        }
    }

    return head;
}

void dumpList(struct ListNode *l)
{
    for(; l; l = l->next)
        printf("%d ", l->val);
    printf("\n");
}

void freeList(struct ListNode *l)
{
    for(; l;) {
        struct ListNode *tmp = l->next;
        printf("free %p \n", l);
        free(l);
        l = tmp;
    }
}

int main() {
    struct ListNode a, a1, a2;
    struct ListNode b, b1, b2;
    struct ListNode *l;

    a.val = 1;
    a1.val = 3;
    a2.val = 5;
    a.next = &a1;
    a1.next = &a2;
    a2.next = NULL;

    b.val = 2;
    b1.val = 4;
    b2.val = 6;
    b.next = &b1;
    b1.next = &b2;
    b2.next = NULL;

    l = mergeTwoLists(NULL, &b);
    dumpList(l);

    freeList(l);
    return 0;
}
