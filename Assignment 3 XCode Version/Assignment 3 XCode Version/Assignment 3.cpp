#include <iostream>
#include "BST.hpp"

void testEmptyTree() {
    Tree<int> tree;
    std::cout << "Empty tree:\n";
    std::cout << tree.to_string() << std::endl;
    std::cout << "Tree height: " << tree.height() << std::endl;
    std::cout << "Tree size: " << tree.size() << std::endl;
    std::cout << "Contains 5? " << tree.contains(5) << std::endl;
}

void testInsertAndBalance() {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(5);
    tree.insert(25);
    std::cout << "After insertions:\n";
    std::cout << tree.to_string() << std::endl;
}

void testMinAndMax() {
    Tree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    std::cout << "Minimum value: " << tree.min() << std::endl;
    std::cout << "Maximum value: " << tree.max() << std::endl;
}

void testContains() {
    Tree<int> tree;
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    std::cout << "Contains 25? " << tree.contains(25) << std::endl;
    std::cout << "Contains 7? " << tree.contains(7) << std::endl;
}

void testSuccessor() {
    Tree<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(25);
    std::cout << "Successor of 10: " << tree.successor(10) << std::endl;
    std::cout << "Successor of 25: " << tree.successor(25) << std::endl;
}

void testTraversalOrders() {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    std::cout << "Pre-order: " << tree.pre_order() << std::endl;
    std::cout << "In-order: " << tree.in_order() << std::endl;
    std::cout << "Post-order: " << tree.post_order() << std::endl;
}

int main() {
    std::cout << "=== Testing empty tree ===\n";
    testEmptyTree();

    std::cout << "=== Testing insert and balance ===\n";
    testInsertAndBalance();

    std::cout << "=== Testing min and max ===\n";
    testMinAndMax();

    std::cout << "=== Testing contains function ===\n";
    testContains();

    std::cout << "=== Testing successor function ===\n";
    testSuccessor();

    std::cout << "=== Testing tree traversals ===\n";
    testTraversalOrders();

    return 0;
}
