#include <iostream>
using namespace std;


class TreeNode 
{
	
	int _data;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;

public:
	TreeNode();
	TreeNode(TreeNode* parent,int data, TreeNode* left, TreeNode* right);

	TreeNode* getParent() { return _parent; }
	int getData() { return _data; }
	TreeNode* getLeft() { return _left; }
	TreeNode* getRight() { return _right; }
	
	void setParent(TreeNode* parent) { _parent = parent; }
	void setData(int data) { _data = data; }
	void setLeft(TreeNode* left) { _left = left; left->setParent(this); }
	void setRight(TreeNode* right) { _right = right; right->setParent(this); }
};

TreeNode::TreeNode()
{
	_data = 0;
	_left = _right = _parent = 0;
}
TreeNode::TreeNode(TreeNode* parent,int data, TreeNode* left, TreeNode* right)
{
	_data = data;
	_left = left;
	_right = right;
	_parent = parent;
}
