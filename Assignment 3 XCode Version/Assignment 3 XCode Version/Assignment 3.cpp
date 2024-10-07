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

void testSingleElementTree() {
    Tree<int> tree;
    tree.insert(10);
    std::cout << "Single element tree (only 10):\n";
    std::cout << tree.to_string() << std::endl;
    std::cout << "Tree height: " << tree.height() << std::endl;
    std::cout << "Tree size: " << tree.size() << std::endl;
    std::cout << "Minimum value: " << tree.min() << std::endl;
    std::cout << "Maximum value: " << tree.max() << std::endl;
    std::cout << "Successor of 10: " << tree.successor(10) << std::endl; // Expect to fail, no successor
}

void testRotations() {
    Tree<int> tree;

    // Right-right case (requires left rotation)
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // Should trigger left rotation
    std::cout << "After right-right case:\n" << tree.to_string() << std::endl;

    // Left-right case (requires right-left rotation)
    Tree<int> tree2;
    tree2.insert(30);
    tree2.insert(10);
    tree2.insert(20); // Should trigger right-left rotation
    std::cout << "After left-right case:\n" << tree2.to_string() << std::endl;
}

void testSuccessorAndPredecessorEdgeCases() {
    Tree<int> tree;
    tree.insert(15);
    tree.insert(10);
    tree.insert(20);

    std::cout << "Successor of 20: " << tree.successor(20) << std::endl; // Should return -1 or invalid
}

void testContainsEmptyTree() {
    Tree<int> tree;
    std::cout << "Empty tree contains 5? " << tree.contains(5) << std::endl; // Should be false
}

void testContainsSingleNodeTree() {
    Tree<int> tree;
    tree.insert(10);
    std::cout << "Single node tree contains 10? " << tree.contains(10) << std::endl; // Should be true
    std::cout << "Single node tree contains 5? " << tree.contains(5) << std::endl;   // Should be false
}

void testContainsMultipleNodes() {
    Tree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Test nodes that exist
    std::cout << "Tree contains 50? " << tree.contains(50) << std::endl; // Should be true
    std::cout << "Tree contains 30? " << tree.contains(30) << std::endl; // Should be true
    std::cout << "Tree contains 80? " << tree.contains(80) << std::endl; // Should be true

    // Test nodes that don't exist
    std::cout << "Tree contains 10? " << tree.contains(10) << std::endl; // Should be false
    std::cout << "Tree contains 35? " << tree.contains(35) << std::endl; // Should be false
    std::cout << "Tree contains 90? " << tree.contains(90) << std::endl; // Should be false
}

void testContainsMinMax() {
    Tree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Check the minimum and maximum values
    std::cout << "Tree contains minimum (20)? " << tree.contains(20) << std::endl; // Should be true
    std::cout << "Tree contains maximum (80)? " << tree.contains(80) << std::endl; // Should be true

    // Check values just outside the range
    std::cout << "Tree contains value below minimum (19)? " << tree.contains(19) << std::endl; // Should be false
    std::cout << "Tree contains value above maximum (81)? " << tree.contains(81) << std::endl; // Should be false
}

void testContainsAfterDeletion() {
    Tree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    
    // Check before deletion
    std::cout << "Tree contains 30? " << tree.contains(30) << std::endl; // Should be true

}

void testContainsAfterRotations() {
    Tree<int> tree;

    // Insert elements that will cause right-right and left-left rotations
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // Right-right rotation
    tree.insert(5);
    tree.insert(4);  // Left-left rotation

    // Check values
    std::cout << "Tree contains 10? " << tree.contains(10) << std::endl; // Should be true
    std::cout << "Tree contains 30? " << tree.contains(30) << std::endl; // Should be true
    std::cout << "Tree contains 4? " << tree.contains(4) << std::endl;   // Should be true
    std::cout << "Tree contains 15? " << tree.contains(15) << std::endl; // Should be false
}

int main() {
    std::cout << "=== Testing contains with empty tree ===\n";
    testContainsEmptyTree();

    std::cout << "=== Testing contains with single node tree ===\n";
    testContainsSingleNodeTree();

    std::cout << "=== Testing contains with multiple nodes ===\n";
    testContainsMultipleNodes();

    std::cout << "=== Testing contains with min/max values ===\n";
    testContainsMinMax();

    std::cout << "=== Testing contains after deletion ===\n";
    testContainsAfterDeletion();
    
    std::cout << "=== Testing contains after rotations ===\n";
    testContainsAfterRotations();

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

    std::cout << "=== Testing single element tree ===\n";
    testSingleElementTree();

    std::cout << "=== Testing tree rotations ===\n";
    testRotations();

    std::cout << "=== Testing successor and predecessor edge cases ===\n";
    testSuccessorAndPredecessorEdgeCases();
    
    return 0;
}
