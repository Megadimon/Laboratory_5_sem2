#include <Laboratory_5_sem2.hpp>
#include <catch.hpp>

SCENARIO("insert") {
    BinarySearchTree<int, char> r;
    BinarySearchTree<int, char>* TreeNode;
    int rv = r.insert(10, TreeNode);
    
    REQUIRE( rv == 10);
}
/*
SCENARIO("print") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.print(11, root);
    
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

