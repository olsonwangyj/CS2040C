#pragma once
#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <cassert>
#include <functional>
#include <string>

using std::string;

template <typename T>
std::string my_to_string(const T& t) {
  return std::to_string(t);
}

template <>
std::string my_to_string(const std::string& t) {
  return "\"" + t + "\"";
}

template <typename T> struct Node {
  T element;
  int height;
  Node<T> *left;
  Node<T> *right;

  Node(T element)
      : element{element}, height{0}, left{nullptr}, right{nullptr} {}
  Node(T element, int height)
      : element{element}, height{height}, left{nullptr}, right{nullptr} {}
};

template <typename T> class Tree {
private:
  size_t m_size = 0;
  Node<T> *m_root;

public:
  // Constructor
  Tree();

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~Tree();

  // Returns a pointer to the root
  Node<T> *root();

  // Checks whether the tree is empty
  bool empty() const;

  // Returns the number of elements
  size_t size() const;

  // Returns the height of the tree
  int height() const;

  // Inserts the specified element
  void insert(T element);

  // Checks whether the container contains the specified element
  bool contains(T element) const;

  // Returns the maximum element
  T max() const;

  // Returns the minimum element
  T min() const;

  // Returns the successor of the specified element
  T successor(T element);

  // Convert each element in the tree to string in pre-order.
  string pre_order();

  // Convert each element in the tree to string in order.
  string in_order();

  // Convert each element in the tree to string in post-order.
  string post_order();

  // Returns a string equivalent of the tree
  string to_string(bool with_height = true) const {
    return m_to_string(with_height, m_root, 0);
  }

private:
  string m_to_string(bool with_height, Node<T> *node, int ident) const {
    string res;
    if (node == nullptr) {
      return res;
    }
    if (node->right != nullptr) {
      res += m_to_string(with_height, node->right, ident + 2);
    }
    for (int i = 0; i < ident; i++) {
      res += " ";
    }
    res += my_to_string(node->element);
    if (with_height) {
      res += "(h=" + my_to_string(node->height) + ")";
    }
    res += "\n";
    if (node->left != nullptr) {
      res += m_to_string(with_height, node->left, ident + 2);
    }
    return res;
  }

    // Feel free to declare helper functions here, if necessary
    void deleteTree(Node<T>* root);
    Node<T>* helperInsert(T element, Node<T>* root);
    int updateHeight(Node<T>* root);
    Node<T>* checkBalance(Node<T>* root);
    Node<T>* leftRotate(Node<T>* root);
    Node<T>* rightRotate(Node<T>* root);
    bool helperContains(T element, Node<T>* root) const;
    Node<T>* helperSuccessor(T element, Node<T>* root);
    Node<T>* parent(Node<T>* root, T element);
    string _pre_order(Node<T> *node);
    string _in_order(Node<T> *node);
    string _post_order(Node<T> *node);
    int getBalance(Node<T>* root);
    int getHeight(Node<T>* root);
  };

// Constructor
template <typename T> Tree<T>::Tree() {
    m_root = nullptr;
  // TODO: Implement this method
}

// Destructor
template <typename T> Tree<T>::~Tree() {
    deleteTree(m_root);
  // TODO: Implement this method
}

template <typename T> void Tree<T>::deleteTree(Node<T>* root) {
    if (!root) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
};

// Returns a pointer to the root
template <typename T> Node<T> *Tree<T>::root() {
  // TODO: Implement this method
    return m_root;
}

// Checks whether the tree is empty
template <typename T> bool Tree<T>::empty() const {
  // TODO: Implement this method
    return m_size == 0;
}

// Returns the number of elements
template <typename T> size_t Tree<T>::size() const {
  // TODO: Implement this method
    return m_size;
}

// Returns the height of the tree
template <typename T> int Tree<T>::height() const {
  // TODO: Implement this method
    if (!m_root) return -1;
    return m_root->height;
}

// Inserts an element
template <typename T> void Tree<T>::insert(T element) {
  // TODO: Implement this method
    m_root = helperInsert(element, m_root);
    m_size++;
}

template <typename T> Node<T>* Tree<T>::helperInsert(T element, Node<T>* root) {
    if (!root) {
        return new Node<T>(element);
    } else if (element < root->element) {
        root->left = helperInsert(element, root->left);
    } else if (element > root->element) {
        root->right = helperInsert(element, root->right);
    } else {
        return root;
    }
    
    updateHeight(root);
    int balanceFactor = getBalance(root);
    
    if (balanceFactor > 1) {
        if (element < root->left->element) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    
    if (balanceFactor < -1) {
        if (element > root->right->element) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    
    /*Node<T>* cur = checkBalance(root);
    if (cur) {
        if (!cur->left || cur->left->height < cur->right->height) {
            Node<T>* tmp = cur->right;
            if (checkBalance(tmp) && (!tmp->right || tmp->right->height < tmp->left->height)) {
                tmp = rightRotate(tmp);
                return leftRotate(cur);
            } else {
                return leftRotate(cur);
            }
        } else if (!cur->right || cur->right->height < cur->left->height) {
            Node<T>* tmp = cur->left;
            if (checkBalance(tmp) && (!tmp->left || tmp->left->height < tmp->right->height)) {
                tmp = leftRotate(tmp);
                return rightRotate(cur);
            } else {
                return rightRotate(cur);
            }
        }
    }*/
    
    return root;
}

template <typename T> int Tree<T>::updateHeight(Node<T>* root) {
    if (!root) return -1;
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
    
    return root->height;
}

template <typename T> int Tree<T>::getHeight(Node<T>* root) {
    if (!root) return -1;
    return root->height;
}

/*template <typename T> Node<T>* Tree<T>::checkBalance(Node<T>* root) {
    if (!root) return NULL;
    
    int leftHeight = root->left ? root->left->height : -1;
    int rightHeight = root->right ? root->right->height : -1;
    if (abs(leftHeight - rightHeight) > 1) return root;
    
    Node<T>* left = checkBalance(root->left);
    if (left) return left;
    
    Node<T>* right = checkBalance(root->right);
    if (right) return right;
    
    return NULL;
}*/

template <typename T> int Tree<T>::getBalance(Node<T>* root) {
    if (!root) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

template <typename T> Node<T>* Tree<T>::leftRotate(Node<T>* root) {
    Node<T>* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    updateHeight(root);
    updateHeight(newRoot);
    
    return newRoot;
}

template <typename T> Node<T>* Tree<T>::rightRotate(Node<T>* root) {
    Node<T>* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    updateHeight(root);
    updateHeight(newRoot);
    
    return newRoot;
}

// Checks whether the container contains the specified element
template <typename T> bool Tree<T>::contains(T element) const {
  // TODO: Implement this method
    if (!m_root) return false;
    return helperContains(element, m_root);
}

template <typename T> bool Tree<T>::helperContains(T element, Node<T>* root) const {
    if (!root) return false;
    if (element == root->element) return true;
    if (element > root->element) return helperContains(element, root->right);
    if (element < root->element) return helperContains(element, root->left);
    
    return false;
}

// Returns the maximum element
template <typename T> T Tree<T>::max() const {
    if (!m_root) throw std::runtime_error("Tree is empty");
    
    Node<T>* cur = m_root;
    while (cur->right != NULL) cur = cur->right;
    
    return cur->element;
  // TODO: Implement this method
}

// Returns the minimum element
template <typename T> T Tree<T>::min() const {
    if (!m_root) throw std::runtime_error("Tree is empty");
    
    Node<T>* cur = m_root;
    while (cur->left != NULL) cur = cur->left;
    
    return cur->element;
  // TODO: Implement this method
}

// Returns the successor of the specified element
template <typename T> T Tree<T>::successor(T element) {
  // TODO: Implement this method
    if (!contains(element)) throw std::runtime_error("not contains");
    Node<T>* cur = helperSuccessor(element, m_root);
    if (!cur) throw std::out_of_range("not contains");
    
    if (cur->right) {
            cur = cur->right;
            while (cur->left) cur = cur->left;
            return cur->element;
    }

    Node<T>* tmp = parent(m_root, element);
    if (!tmp) throw std::out_of_range("not contains");
    return tmp->element;
}

template <typename T> Node<T>* Tree<T>::parent(Node<T>* root, T element) {
    if (!root) return NULL;
    
    Node<T>* pre = NULL;
    Node<T>* cur = root;
    
    while (cur->element != element) {
        if (element < cur->element) {
            pre = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    
    return pre;
}

template <typename T> Node<T>* Tree<T>::helperSuccessor(T element, Node<T>* root) {
    if (!root) return NULL;
    if (element == root->element) return root;
    if (element > root->element) return helperSuccessor(element, root->right);
    if (element < root->element) return helperSuccessor(element, root->left);
    
    return NULL;
}

template <typename T>
string Tree<T>::_pre_order(Node<T> *node) {
  return my_to_string(node->element)
    + (node->left == nullptr ? "" : " " + _pre_order(node->left))
    + (node->right == nullptr ? "" : " " + _pre_order(node->right));
}

template <typename T>
string Tree<T>::pre_order() {
  if (m_root == nullptr) {
    return "";
  }
  return _pre_order(m_root);
}

template <typename T>
string Tree<T>::_in_order(Node<T> *node) {
    string result = "";
        if (node->left) {
            result += _in_order(node->left) + " ";
        }
        result += my_to_string(node->element);
        if (node->right) {
            result += " " + _in_order(node->right);
        }
        return result;
}

template <typename T>
string Tree<T>::in_order() {
  // TODO: Implement this method
    if (m_root == nullptr) {
      return "";
    }
    return _in_order(m_root);
}

template <typename T>
string Tree<T>::_post_order(Node<T> *node) {
    string result = "";
        if (node->left) {
            result += _post_order(node->left) + " ";
        }
        if (node->right) {
            result += _post_order(node->right) + " ";
        }
        result += my_to_string(node->element);
        return result;
}

template <typename T>
string Tree<T>::post_order() {
  // TODO: Implement this method
    if (m_root == nullptr) {
      return "";
    }
    return _post_order(m_root);
}

#endif
