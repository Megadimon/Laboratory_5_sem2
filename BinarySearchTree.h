#include"treeNode.h"
#include<fstream>
#include<iostream>

using namespace std;


class BinarySearchTree
{
	TreeNode* _root;
public:
	BinarySearchTree();
	void insert(int data);
	
	bool find(int data);	
	~BinarySearchTree();

private:

	void recursiveInsert(TreeNode* subTree, int data);
	bool recursiveFind(TreeNode* subTree, int data);
	void print(ostream& str, TreeNode* subTree, int lvl) const;

	friend ostream& operator<< (ostream& str, const BinarySearchTree& tree);
};
istream& operator>> (istream& str, const BinarySearchTree& tree);

BinarySearchTree::BinarySearchTree()
{
	_root = 0;
}

void BinarySearchTree::insert(int data)
{
	if (!_root)
		_root = new TreeNode(0, data, 0, 0);
	else
		recursiveInsert(_root, data);
}

void BinarySearchTree::recursiveInsert(TreeNode* subTree, int data)
{
	if (subTree->getData() == data)
		cout << "Elemet " << data << " is exist" << endl;
	else if (subTree->getData() < data)
	{
		if (subTree->getRight())
			recursiveInsert(subTree->getRight(),data);
		else
			subTree->setRight(new TreeNode(0, data, 0, 0));
	}
	else
	{
		if (subTree->getLeft())
			recursiveInsert(subTree->getLeft(),data);
		else
			subTree->setLeft(new TreeNode(0,data, 0, 0));
	}
}

bool  BinarySearchTree::find(int data)
{
	return recursiveFind(_root, data);
}
S
bool BinarySearchTree::recursiveFind(TreeNode* subtree, int data)
{
	if (!subtree)
		return false;
	else if (subtree->getData() == data)
		return true;
	else if (subtree->getData() < data)
		return recursiveFind(subtree->getRight(), data);
	else
		return recursiveFind(subtree->getLeft(), data);
}

void BinarySearchTree::print(ostream& str, TreeNode* subTree, int lvl) const
{
	if (subTree->getRight())
		print(str, subTree->getRight(), lvl + 1);

	for (unsigned int i = 0; i < lvl; ++i)
		str << '-';
	str << ' ' << subTree->getData() << endl;
	
	if (subTree->getLeft())
		print(str, subTree->getLeft(), lvl + 1);
}


BinarySearchTree::~BinarySearchTree()
{
}



istream& operator >> (istream& str, BinarySearchTree& tree)
{
	char c = 0;
	str >> c;
	if (c != '[')
		return str;
	int data = 0;
	while (str.peek() != ']')
	{
		str >> data;
		tree.insert(data);
	}

	return str;
}
ostream& operator<< (ostream& str, const BinarySearchTree& tree)
{
	tree.print(str, tree._root, 0);

	return str;
}