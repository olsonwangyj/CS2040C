#include "LinkedList.h"
#include <stdexcept>

// copy the following code to coursemology without the above line of "#include "LinkedList.h""

// Returns the value at head
int List::head() {
	// TODO: Implement this method
	if (m_size == 0) throw std::out_of_range("List is empty");
	return this->m_head->next->element;
}

// Checks whether the container is empty
bool List::empty() const {
	// TODO: Implement this method
	return this->m_size == 0;
}

// Returns the number of elements
size_t List::size() const {
	// TODO: Implement this method
	return this->m_size;
}

// Inserts an element to the head
void List::push_head(int element) {
	// TODO: Implement this method
	if (m_size == 0) {
		m_head = new Node(element);
	}

	Node* tmp = new Node(element);
	tmp->next = m_head->next;
	m_head->next = tmp;
	m_size++;
}

// Removes the head element
int List::pop_head() {
	// TODO: Implement this method
	if (m_size == 0) throw std::out_of_range("List is empty");

	Node* tmp = m_head->next;
	m_head->next = tmp->next;
	int ans = tmp->element;
	delete tmp;
	m_size--;
	return ans;
}

// Checks whether the container contains the specified element
bool List::contains(int element) const {
	// TODO: Implement this method
	if (m_size == 0) return false;

	Node* ptr = m_head->next;
	while (ptr != NULL) {
		if (ptr->element == element) return true;
		ptr = ptr->next;
	}

	return false;
}

// Returns a std::string equivalent of the container
std::string List::to_string() const {
	// TODO: Implement this method
	if (m_size == 0) return "{}";

	std::string str;
	str += "{";
	Node* ptr = m_head->next;
	while (ptr->next != NULL) {
		str += std::to_string(ptr->element);
		str += ", ";
		ptr = ptr->next;
	}

	str += std::to_string(ptr->element);
	str += "}";

	return str;
}
