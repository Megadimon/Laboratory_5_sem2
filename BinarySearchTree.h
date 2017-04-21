#include"treeNode.h"
#include<exception>
#include<fstream>
#include<iostream>

using namespace std;


//struct kvPair
//{
//	int key;
//	int data;
//	kvPair(int k, int d)	
//	{
//		key = k;
//		data = d;
//	}
//};


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
	//kvPair find(int key);
	TData* find(const TKey& key);
	//void remove(int key);
	void print(ostream& str, TreeNode<TKey, TData>* subTree, int lvl) const;
	~BinarySearchTree();

private:

	void recursiveInsert(TreeNode<TKey, TData>* subTree, const TKey& key, const TData& data);
	TData* recursiveFind(TreeNode<TKey, TData>* subTree, const TKey& key);
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
		throw exception("Key already exist");
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

template <typename TKey, typename TData>
void BinarySearchTree<TKey, TData>::print(ostream& str, TreeNode<TKey, TData>* subTree, int lvl) const
{
	if (subTree->getRight())
		print(str, subTree->getRight(), lvl + 1);

	for (unsigned int i = 0; i < lvl; ++i)
		str << '-';
	str << ' ' << subTree->getData() << endl;

	if (subTree->getLeft())
		print(str, subTree->getLeft(), lvl + 1);
}


template <typename TKey, typename TData>
BinarySearchTree<TKey, TData>::~BinarySearchTree()
{
}


template <typename TKey, typename TData>
istream& operator >> (istream& str, BinarySearchTree<TKey, TData>& tree)
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

	return str;
}

template <typename TKey, typename TData>
ostream& operator<< (ostream& str, const BinarySearchTree<TKey, TData>& tree)
{
	tree.print(str, tree.getRoot(), 0);

	return str;
}

