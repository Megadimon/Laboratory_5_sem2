#include <iostream>
#include<vector>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
	BinarySearchTree<int, char> tree;
	vector<exception> errors;


	int n = 0;

	cin >> tree;


	for (int i = 0; i < errors.size(); ++i)
		cout << errors[i].what() << endl;
	
	cout << tree;

	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		cin >> k;
		tree.remove(k);

		cout << tree;
	}

	system("pause");
	return 0;
}