/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
 *反转单链表
 *@head 指向链表头结点指针
 *返回指向新的链表头结点指针
 */
ListNode* reverseList(ListNode* head)
{
  if(head == NULL || head->next == NULL)
    return head;

  ListNode* p = head;
  ListNode* q = p->next;
  head->next = NULL;

  while(q != NULL)
  {
    ListNode* r = q->next;
    q->next = p;
    p = q;
    q = r;
  }
  return p;
}


       
