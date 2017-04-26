#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename TKey, typename TData>
class BinarySearchTree;

template <typename TKey, typename TData>
class TreeNode
{
	friend class BinarySearchTree<TKey, TData>;
public:
	TKey _key;
	TData _data;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;

	TreeNode(TreeNode* parent, TKey key, TData data, TreeNode* left, TreeNode* right);

	TreeNode* getParent() { return _parent; }
	TKey getKey() { return _key; }
	TData getData() { return _data; }
	TreeNode* getLeft() { return _left; }
	TreeNode* getRight() { return _right; }

	void setParent(TreeNode* parent) { _parent = parent; }
	void setData(TData data) { _data = data; }
	void setLeft(TreeNode* left) { _left = left; if (left) left->setParent(this); }
	void setRight(TreeNode* right) { _right = right; if (right) right->setParent(this); }
};

template<typename TKey, typename TData>
TreeNode<TKey, TData>::TreeNode(TreeNode* parent, TKey key, TData data, TreeNode* left, TreeNode* right)
	: _data(data), _key(key)
{
	_left = left;
	_right = right;
	_parent = parent;
}

template <typename TKey, typename TData>
class BinarySearchTree
{
	TreeNode<TKey, TData>* _root;
public:
	TreeNode<TKey, TData>* getRoot() const { return _root; }


	int insert(int check, const TKey& key, const TData& data);
	TData* find(int check, const TKey& key);
	int remove(int check, const TKey& key);
	int print(int check, char subTree, int lvl) ;
	
	
	void recursiveInsert(TreeNode<TKey, TData>* subTree, const TKey& key, const TData& data);
	TData* recursiveFind(TreeNode<TKey, TData>* subTree, const TKey& key);
	TreeNode<TKey, TData>* recursiveFindNode(TreeNode<TKey, TData>* subTree, const TKey& key);
};


template <typename TKey, typename TData>
int BinarySearchTree<TKey, TData>::insert(int check, const TKey& key, const TData& data)
{
	if (!_root)
		_root = new TreeNode<TKey, TData>(0, key, data, 0, 0);
	else
		recursiveInsert(_root, key, data);
	return check;

}
template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::recursiveInsert(TreeNode<TKey, TData>* subTree, const TKey& key, const TData& data)
{
	
	 if (subTree->getKey() < key)
	{
		if (subTree->getRight())
			recursiveInsert(subTree->getRight(), key, data);
		else
			subTree->setRight(new TreeNode<TKey, TData>(0, key, data, 0, 0));
	}
	else
	{
		if (subTree->getLeft())
			recursiveInsert(subTree->getLeft(), key, data);
		else
			subTree->setLeft(new TreeNode<TKey, TData>(0, key, data, 0, 0));
	}
}
template <typename TKey, typename TData>
TData*  BinarySearchTree<TKey, TData>::find(int check, const TKey& data)
{
	return recursiveFind(_root, data);
	return check;
}

template<typename TKey, typename TData>
int BinarySearchTree<TKey, TData>::remove(int check, const TKey& key)
{
	TreeNode<TKey, TData>* node = recursiveFindNode(_root, key);

	if (node)
	{
		if (node->getRight())
		{
			TreeNode<TKey, TData>* min = node->getRight();
			while (min->getLeft()) min = min->getLeft();

			min->setLeft(node->getLeft());
			if (node == _root) { _root = node->getRight(); if (_root) _root->setParent(0); }
			else
			{
				if (node == node->getParent()->getRight()) { node->getParent()->setRight(node->getRight()); }
				else { node->getParent()->setLeft(node->getRight()); }
			}
		}
		else
		{
			if (node == _root) { _root = node->getLeft(); if (_root) _root->setParent(0); }
			else
			{
				if (node == node->getParent()->getRight()) { node->getParent()->setRight(node->getLeft()); }
				else { node->getParent()->setLeft(node->getLeft()); }
			}
		}

		delete node;
	}

	return check;
}

template <typename TKey, typename TData>
TData* BinarySearchTree<TKey, TData>::recursiveFind(TreeNode<TKey, TData>* subtree, const TKey& key)
{
	if (!subtree)
		return NULL;
	else if (subtree->getKey() == key)
		return &(subtree->_data);
	else if (subtree->getKey() < key)
		return recursiveFind(subtree->getRight(), key);
	else
		return recursiveFind(subtree->getLeft(), key);
}

template<typename TKey, typename TData>
TreeNode<TKey, TData>* BinarySearchTree<TKey, TData>::recursiveFindNode(TreeNode<TKey, TData>* subTree, const TKey & key)
{
	if (!subTree)
		return NULL;
	else if (subTree->getKey() == key)
		return subTree;
	else if (subTree->getKey() < key)
		return recursiveFindNode(subTree->getRight(), key);
	else
		return recursiveFindNode(subTree->getLeft(), key);
}

template <typename TKey, typename TData>
int BinarySearchTree<TKey, TData>::print(int check, char subTree, int lvl) 
{
	if (subTree->getRight()){}
		

	cout << ' ' << subTree->getData() << ' ';
	

	if (subTree->getLeft()){}
		

	return check;
}


