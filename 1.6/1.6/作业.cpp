//��������
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//��������λ��
int FindTree(struct TreeNode* alt, struct TreeNode* n)
{
	if (alt == NULL)
		return 0;
	if (alt == n)
		return 1;
	int left = FindTree(alt->left, n)//����飬���Ҳ�
	int right = FindTree(alt->right, n);
	if (left == 1)
		return 1;
	if (right == 1)
		return 1;

	return 0;

}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	if (root == NULL)
		return 0;
	if (root == p || root == q)
		return root;
	//��Ʋ������� p��q ������

	int pleft = FindTree(root->left, p);
	int qleft = FindTree(root->left, q);

	if (qleft == 1 && pleft == 1)
		return lowestCommonAncestor(root->left, p, q);
	if (qleft == 0 && pleft == 0)
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;


}

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:

	TreeNode* prev = NULL;

	void Tree2Node(TreeNode* cur)
	{
		if (cur == NULL)
			return;


		Tree2Node(cur->left);
		cur->left = prev;
		//ֻ�е�prev ��һ�ε� 0 ��ʱ����ܽ������������
		if (prev)
		prev->right = cur;
		prev = cur;
		Tree2Node(cur->right);


	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		Tree2Node(pRootOfTree);


		TreeNode* head = pRootOfTree;
		while (head && head->left)
		{
			head = head->left;
		}
		return head;

	}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
void _tree2str(struct TreeNode* root, char* s1)
{
	if (root == NULL)
		return;
	//��ӡͷ
	char buff[12] = { '\0' };
	sprintf(buff, "%d", root->val);
	strcat(s1, buff);
	//��ӡ�����
	if (root->left == NULL)
	{
		if (root->right == NULL)
			return;
		else
			strcat(s1, "()");
	}
	else
	{
		strcat(s1, "(");
		_tree2str(root->left, s1);
		strcat(s1, ")");
	}
	//��ӡ�Ҳ���
	if (root->right == NULL)
		return;
	else
	{
		strcat(s1, "(");
		_tree2str(root->right, s1);
		strcat(s1, ")");
	}


}

char* tree2str(struct TreeNode* t)
{
	char* s1 = (char*)malloc(1024 * 1024);
	_tree2str(t, s1);
	return s1;

}