#include <iostream>
using namespace std;

template <typename TKey, typename TData>
class BinarySearchTree;

template <typename TKey, typename TData>
class TreeNode
{
	friend class BinarySearchTree<TKey, TData>;

	TKey _key;
	TData _data;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;

public:
	TreeNode();
	TreeNode(TreeNode* parent, TKey key, TData data, TreeNode* left, TreeNode* right);

	TreeNode* getParent() { return _parent; }
	TKey getKey() { return _key; }
	TData getData() { return _data; }
	TreeNode* getLeft() { return _left; }
	TreeNode* getRight() { return _right; }

	void setParent(TreeNode* parent) { _parent = parent; }
	void setData(TData data) { _data = data; }
	void setLeft(TreeNode* left) { _left = left; left->setParent(this); }
	void setRight(TreeNode* right) { _right = right; right->setParent(this); }
};

template<typename TKey, typename TData>
TreeNode<TKey, TData>::TreeNode()
{
	_left = _right = _parent = 0;
}

template<typename TKey, typename TData>
TreeNode<TKey, TData>::TreeNode(TreeNode* parent, TKey key, TData data, TreeNode* left, TreeNode* right)
	: _data(data), _key(key)
{
	_left = left;
	_right = right;
	_parent = parent;
}
