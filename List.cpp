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

/*
 *查找链表倒数第K个节点,快慢指针的应用
 * 
 */
ListNode* FindKthToTail(ListNode* head,unsigned int k)
{
  if(head == NULL || k == 0)
      return NULL;
    
  ListNode* fast = head;
  ListNode* slow = NULL;

  for(int i = 0; i < k-1; ++i)  //快指针前进到底k-1个节点
  {
    if(fast->next != NULL)
      fast = fast->next;
    else                        //如果链表节点数少于k个
      return NULL;                      
  }
     
  slow = head;
  while(fast->next != NULL)
  {
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}
       
