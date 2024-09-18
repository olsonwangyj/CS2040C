
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <string>

template <typename T> struct Node {
  T element;
  Node<T> *next;

  Node(T element) : element{element}, next{nullptr} {}
  Node(T element, Node<T> *next) : element{element}, next{next} {}
};

template <typename T> class List {
private:
  size_t m_size;
  Node<T> *m_head;

  // Feel free to add helper functions here, if necessary

public:
  // Constructs an empty container
  List() : m_size{0}, m_head{nullptr} {}

  // Constructs the container with the contents of the initializer list
  List(std::initializer_list<T> init_list) : m_size{0}, m_head{nullptr} {
    auto it = init_list.end();
    while (--it != init_list.begin()) {
      push_head(*it);
    }
    push_head(*it);
  }

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~List() {
    // TODO: (Optional) Implement this method
      delete m_head;
  }

  // Copy constructor
  List(const List<T> &other) {
    // TODO: (Optional) Implement this method
      m_head = other;
  }

  // Copy assignment
  List<T> &operator=(const List<T> &other) {
    // TODO: (Optional) Implement this method
      if (this == other) return this;

      m_head = other.m_head;
      m_size = other.m_size;

      return this;
  }

  // Returns the contents of the head node
  const T& head() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }
    return m_head->element;
  }

  // Checks whether the container is empty
  bool empty() const { return m_size == 0; }

  // Returns the number of elements
  size_t size() const { return m_size; }

  // Inserts an element to the head
  void push_head(const T& element) {
    Node<T> *node = new Node<T>{element, m_head};
    m_head = node;
    m_size++;
  }

  // Removes the head element
  void pop_head() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }
    Node<T> *node = m_head;
    m_head = m_head->next;
    delete node;
    m_size--;
  }

  // Checks whether the container contains the specified element
  bool contains(const T& element) const {
    // TODO: Implement this method
      if (m_size <= 0) return false;

      Node<T>* ptr = m_head;
      while (ptr != NULL) {
          if (ptr->element == element) return true;

          ptr = ptr->next;
      }

    return false;
  }

  // Extracts the maximum element from the container
  T extract_max() {
    // TODO: Implement this method
      if (m_size <= 0) throw std::out_of_range("List is empty");

      T max = m_head->element;
      Node<T>* ptr = m_head;
      while (ptr != NULL) {
          if (ptr->element >= max) max = ptr->element;

          ptr = ptr->next;
      }

      return max;
  }

  // Reverse the container
  void reverse() {
    // TODO: Implement this method
      if (m_size <= 1) return;

      Node<T>* pre = m_head;
      Node<T>* cur = pre->next;
      Node<T>* next = cur->next;

      while (cur != NULL) {
          cur->next = pre;
          pre = cur;
          cur = next;
          if (next != NULL) next = next->next;
      }

      m_head = pre;
  }

  // Returns a std::string equivalent of the container
  std::string to_string() const {
    // TODO: Implement this method
      if (m_size == 0) return "{}";

      std::string ans = "{";
      Node<T>* ptr = m_head;
      while (ptr->next != NULL) {
          ans += std::to_string(ptr->element);
          ans += ", ";
          ptr = ptr->next;
      }

      ans += std::to_string(ptr->element);
      ans += "}";

    return ans;
  }

};

template<>
std::string List<std::string>::to_string() const {
    if (m_size == 0) return "{}";

    std::string ans = "{";
    Node<std::string>* ptr = m_head;
    while (ptr->next != NULL) {
        ans += "\"";
        ans += ptr->element;
        ans += "\", ";
        ptr = ptr->next;
    }

    ans += "\"";
    ans += ptr->element;
    ans += "\"";
    ans += "}";

    return ans;
}

#endif
