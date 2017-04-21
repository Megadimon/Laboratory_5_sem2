#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
	BinarySearchTree<int, char> tree;


	int n = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		char v = 0;
		cin >> k >> v;
		try
		{ 
			tree.insert(k, v);
		}
		catch (exception e)
		{
		  cout << e.what() << endl;
		}
	}


	cout << tree;

	system("pause");
	return 0;
}