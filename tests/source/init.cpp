#include <Laboratory_5_sem2.hpp>
#include <catch.hpp>

SCENARIO ("constructor"){
	BinarySearchTree<int,char> BST;
	REQUIRE(BST.Get_Root() == 0);
}
    

SCENARIO("insert") {
   BinarySearchTree<int, char> BST;
	BST.insert(1,'a');
	REQUIRE(BST.key == 1);
	REQUIRE(BST.data == 'a');
   
   
}
/*
SCENARIO("print") {
    BinarySearchTree<int, char> r;
    BinarySearchTree<int, char>* TreeNode;
    int rv = r.print(11, 'a', 1);
    
    REQUIRE( rv == 11);
}

SCENARIO("Search") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Search(12, root);
    
    REQUIRE( rv == 12);
}
SCENARIO("Deletionh") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Search(13, root);
    
    REQUIRE( rv == 13);
}
SCENARIO("FreeTree") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Search(14, root);
    
    REQUIRE( rv == 14);
}*/

