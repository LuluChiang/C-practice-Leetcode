#include "LinkedList.h"

#define NULL (void*)0


/*
237. Delete Node in a Linked List

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
Given linked list -- head = [4,5,1,9], which looks like following:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list
should become 4 -> 1 -> 9 after calling your function.

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list
should become 4 -> 5 -> 9 after calling your function.

Note:
The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
*/
void deleteNode(struct ListNode* node) 
{	
	// solution: Since we do not have access to the node before the one we want to delete, we cannot modify the next pointer of that node in any way. Instead, we have to replace the value of the node we want to delete with the value in the node after it, and then delete the node after it.
	node->val = node->next->val;
	node->next = node->next->next;
}

/*
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
struct ListNode* removeElements(struct ListNode* head, int val) 
{
	/*		*** Really poweful solution ***		
	if (head == null) return null;
	head.next = removeElements(head.next, val);
	return head.val == val ? head.next : head;
	*/

	struct ListNode *curr_node = head;
	struct ListNode *next_node = head->next;
	while (next_node != NULL)
	{
		if (next_node->val == val)
			curr_node->next = next_node->next;
		else
			curr_node = next_node;
		next_node = next_node->next;
	}
	return head;

}
/*
876. Middle of the Linked List

Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

*/
struct ListNode* middleNode(struct ListNode* head) 
{
	struct ListNode *mid = head;
	struct ListNode *run = head;
	while (1)
	{
		if (run->next == NULL)
			return mid;
		else
		{
			if (run->next->next == NULL)
				return mid->next;
			else
			{
				run = run->next->next;
				mid = mid->next;
			}
		}
	}
}
/*
206. Reverse Linked List

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
struct ListNode* reverseList(struct ListNode* head) 
{
	struct ListNode *pre_node = (struct ListNode*)NULL;
	struct ListNode *curr_node = head;
	struct ListNode *next_node = head;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		curr_node->next = pre_node;	
		pre_node = curr_node;
		curr_node = next_node;
	}
	return pre_node;
}
/*
83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
/*  **Iterative**
	struct ListNode *curr_node = head;
	while (curr_node != NULL && curr_node->next != NULL)
	{
		if (curr_node->val == curr_node->next->val)
			curr_node->next = curr_node->next->next;
		else
			curr_node = curr_node->next;
	}
	return head;
*/

/*	**recursive**			*/		
	if (head == NULL || head->next==NULL)
		return head;
	head->next = deleteDuplicates(head->next);
	if (head->val == head->next->val)
		return head->next;
	else
		return head;
	//return head->val == head->next->val ? head->next : head;
}

/* 
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) //*
{
/*	**Recursive			
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l2->next, l1);
		return l2;
	}
*/

	struct ListNode *head = (struct ListNode*)NULL;
	struct ListNode *curr_node = head;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			curr_node->next = l1;
			l1 = l1->next;
		}
		else
		{
			curr_node->next = l2;
			l2 = l2->next;
		}
		curr_node = curr_node->next;
	}
	return head->next;

}