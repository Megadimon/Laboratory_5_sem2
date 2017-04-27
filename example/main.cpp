#include <iostream>
#include <fstream>
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
	void setLeft(TreeNode* left) { _left = left; if (left) left->setParent(this); }
	void setRight(TreeNode* right) { _right = right; if (right) right->setParent(this); }
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


template <typename TKey, typename TData>
istream& operator >> (istream& str, const BinarySearchTree<TKey, TData>& tree);

template <typename TKey, typename TData>
ostream& operator<< (ostream& str, const BinarySearchTree<TKey, TData>& tree);

template <typename TKey, typename TData>
class BinarySearchTree
{
	TreeNode<TKey, TData>* _root;
public:
	BinarySearchTree();
	TreeNode<TKey, TData>* getRoot() const { return _root; }


	void insert(const TKey& key, const TData& data);
	TData* find(const TKey& key);
	void remove(const TKey& key);
	void print(ostream& str, TreeNode<TKey, TData>* subTree, int lvl, int* n) const;
	void print1(ostream& str, TreeNode<TKey, TData>* subTree, int lvl) const;
	~BinarySearchTree();

private:

	void recursiveInsert(TreeNode<TKey, TData>* subTree, const TKey& key, const TData& data);
	TData* recursiveFind(TreeNode<TKey, TData>* subTree, const TKey& key);
	TreeNode<TKey, TData>* recursiveFindNode(TreeNode<TKey, TData>* subTree, const TKey& key);
};


template <typename TKey, typename TData>
BinarySearchTree<TKey, TData>::BinarySearchTree()
{
	_root = 0;
}

template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::insert(const TKey& key, const TData& data)
{
	if (!_root)
		_root = new TreeNode<TKey, TData>(0, key, data, 0, 0);
	else
		recursiveInsert(_root, key, data);
}
template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::recursiveInsert(TreeNode<TKey, TData>* subTree, const TKey& key, const TData& data)
{
	if (subTree->getKey() == key)
	else if (subTree->getKey() < key)
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
TData*  BinarySearchTree<TKey, TData>::find(const TKey& data)
{
	return recursiveFind(_root, data);
}

template<typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::remove(const TKey& key)
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
void BinarySearchTree<TKey, TData>::print(ostream& str, TreeNode<TKey, TData>* subTree, int lvl, int* n) const
{
	if (subTree->getRight())
		print(str, subTree->getRight(), lvl + 1, n);

	str << ' ' << subTree->getData() << ' ';
	++(*n);

	if (subTree->getLeft())
		print(str, subTree->getLeft(), lvl + 1, n);
}

template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::print1(ostream& str, TreeNode<TKey, TData>* subTree, int lvl) const
{
	if (subTree->getRight())
		print1(str, subTree->getRight(), lvl + 1);

	for (int i = 0; i < lvl; ++i)
		str << '-';
	str << ' ' << subTree->getData() << endl;

	if (subTree->getLeft())
		print1(str, subTree->getLeft(), lvl + 1);
}


template <typename TKey, typename TData>
BinarySearchTree<TKey, TData>::~BinarySearchTree()
{
	while (_root)
		remove(_root->getKey());
}


template <typename TKey, typename TData>
istream& operator >> (istream& str, BinarySearchTree<TKey, TData>& tree)
{
	https://github.com/Megadimon/Laboratory_5_sem2/blob/master/include/Laboratory_5_sem2.hpp

	return str;
}

template <typename TKey, typename TData>
ostream& operator << (ostream& str, const BinarySearchTree<TKey, TData>& tree)
{
	char c = 0;
	str >> c;
	if (c != '[')
	return str;	
	TKey key;
	TData data;
	while (str.peek() != ']')
	{
		str >> key;
		str >> data;
		tree.insert(key, data);
	}
	str.get();

	return str;
}

int main()
{
	BinarySearchTree<int, char> tree;
   
	int n = 0;
	cin >> n;
	
	
	cout << tree;
	
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		cin >> k;
		tree.remove(k);

		cout << tree;
	}

	return 0;
}
