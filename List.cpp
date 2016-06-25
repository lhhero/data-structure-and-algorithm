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
       
/*
 *两个链表的第一个公共节点
 *
 */
ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
{
  unsigned int len1 = GetListLength(pHead1);
  unsigned int len2 = GetListLength(pHead2);
  ListNode* pLenLong = pHead1;
  ListNode* pLenShort = pHead2;
  int dif = len1-len2;
  if(len1 < len2)
  {
    dif = len2-len1;
    pLenShort = pHead1;
    pLenLong = pHead2;
  }
  //长链表先走dif步,然后两个链表同时遍历
  for(int i = 0; i < dif; ++i)
    pLenLong = pLenLong->next;

  while((pLenLong != pLenShort) && (pLenLong != NULL) && (pLenShort != NULL)) 
  {
    pLenShort = pLenShort->next;
    pLenLong = pLenLong->next;
  }

  ListNode* pFirstCommonNode = pLenLong;
  return pFirstCommonNode;
}
unsigned int GetListLength(ListNode* head)
{
  unsigned int cnt = 0;
  ListNode* p = head;
  while(p != NULL)
  {
    cnt++;
    p = p->next;
  }
  return cnt;
}

/*
 *合并两个已排序的链表
 * 
 */
ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
{
  if(pHead1 == NULL)
    return pHead2;
  else if(pHead2 == NULL)
    return pHead1;

  ListNode* pMergeHead = NULL;
  ListNode* dummy = new ListNode(0);
  ListNode* cur = dummy->next;

  while(pHead1 && pHead2)
  {
    if(pHead1->val < pHead2->val)
    {
      cur->next = pHead1;
      pHead1 = pHead1->next;
    }
    else
    {
      cur->next = pHead2;
      pHead2 = pHead2->next;
    }

    if(pHead1)
      cur->next = pHead1;
    else
      cur->next = pHead2;
    cur = cur->next;
  }

  pMergeHead = dummy->next;
  delete dummy;
  return pMergeHead;
}

//递归解法
ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
{
  if(pHead1 == NULL)
    return pHead2;
  else if(pHead2 == NULL)
    return pHead1;

  ListNode* pMergeHead = NULL;
  if(pHead1->val < pHead2->val)
  {
    pMergeHead = pHead1;
    pMergeHead->next = Merge(pHead1->next,pHead2);
  }
  else
  {
    pMergeHead = pHead2;
    pMergeHead->next = Merge(pHead1,pHead2->next);
  }
  return pMergeHead;
}



/*
 *
 * 双向链表基本操作：创建双向链表，删除/插入节点
 */

/**
 * Definition for double-linked list.
 * struct DListNode {
 *     int val;
 *     DListNode *pre;
 *     DListNode *next;
 *     DListNode(int x) : val(x),next(NULL),pre(NULL) {}
 * };
 */
