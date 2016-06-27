typedef struct BinTreeNode{
	int val;
	BinTreeNode* left;
	BinTreeNode* right;
}
/**
 * PreOederTraverse1 前序遍历，递归形式
 * @param root -根结点
 * Returns: nothing
 */
void PreOederTraverse1(BinTreeNode* root)
{
	if(root == NULL)
		return;

	cout << root->val << " ";
	PreOederTraverse1(root->left);//遍历左子树
	PreOederTraverse1(root->right);//遍历右子树
}

/**
 * PreOederTraverse2 前序遍历，非递归形式
 * 
 */
void PreOederTraverse2(BinTreeNode* root)
{
	if(root == NULL)
		return;
	stack<BinTreeNode*> s;
	BinTreeNode* p = root;
	while(p != NULL || !s.empty())
	{
		while(p != NULL)
		{
			cout << p->val << " ";
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

/**
 * InOederTraverse1 中序遍历，递归形式
 */
void InOederTraverse1(BinTreeNode* root)
{
	if(root == NULL)
		return;

	InOederTraverse1(root->left);//遍历左子树
	cout << root->val << " ";
	InOederTraverse1(root->right);//遍历右子树
}

/**
 * InOederTraverse2 中序遍历，非递归形式
 * @param root
 */
void InOederTraverse2(BinTreeNode* root)
{
	if(root == NULL)
		return;
	stack<BinTreeNode*> s;
	BinTreeNode* p = root;
	while(p != NULL || !s.empty())
	{
		while(p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			cout << p->val << " ";
			s.pop();
			p = p->right;
		}
	}
}


/**
 * PostOederTraverse1 后序遍历，递归形式
 */
void PostOederTraverse1(BinTreeNode* root)
{
	if(root == NULL)
		return;

	PostOederTraverse1(root->left);//遍历左子树
	PostOederTraverse1(root->right);//遍历右子树
	cout << root->val << " ";
}

/**
 * PostOederTraverse2 后序遍历，非递归形式
 * @param root
 */
void PostOrderTraverse(BinTreeNode *root)     //非递归后序遍历
{
    stack<BinTreeNode*> s;
    BinTreeNode *cur;                      //当前结点 
    BinTreeNode *pre = NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur = s.top();
        if((cur->left==NULL&&cur->right==NULL)||
           (pre != NULL && (pre == cur->left || pre == cur->right)))
        {
            cout<< cur->val << " ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
            s.pop();
            pre = cur; 
        }
        else
        {
            if(cur->right != NULL)
                s.push(cur->right);
            if(cur->left != NULL)    
                s.push(cur->left);
        }
    }    
}


/**
 * LevelTraverse 层序遍历，BFS
 * @param root
 */
void LevelTraverse(BinTreeNode* root)
{
	if(root == NULL)
		return;
	queue<BinTreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		BinTreeNode* pNode = q.top();
		q.pop();
		cout << pNode->val << " ";

		if(pNode->left != NULL)
			q.push(pNode->left);  //左结点入队列
		if(pNode->right != NULL)
			q.push(pNode->right); //右结点入队列
	}
}
