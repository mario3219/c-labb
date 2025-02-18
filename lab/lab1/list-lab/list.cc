#include <iostream>
#include "list.h"
using std::cout;

List::List() : first(nullptr) {
}

List::~List() {
	Node *temp = first;
	Node *next = nullptr;
	while (temp != nullptr) {
		next = temp->next;
		delete temp;
		temp = next;
	}
}

bool List::exists(int d) const {
	Node *temp = first;
	while (temp != nullptr) {
		if (temp->value == d) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int List::size() const {
	Node *temp = first;
	int sz = 0;
	while (temp != nullptr) {
		sz = sz + 1;
		temp = temp->next;
	}
	return sz;
}

bool List::empty() const {
	if (first == nullptr) {
		return true;
	} return false;
}

void List::insertFirst(int d) {
	Node* temp = first;
	first = new Node(d, temp);
}

void List::remove(int d, DeleteFlag df) {
	Node *temp = first;
	Node *last = nullptr;
	while (temp != nullptr) {
		if (df == DeleteFlag::LESS && temp->value < d) {
			break;
		}
		if (df == DeleteFlag::EQUAL && temp->value == d) {
			break;
		}
		if (df == DeleteFlag::GREATER && temp->value > d) {
			break;
		}
		last = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		return;
	}

	if (temp == first) {
		first = temp->next;
	} else {
		last->next = temp->next;
		delete temp;
	}
}

void List::print() const {
	Node *temp = first;
	cout << "\n";
	while (temp != nullptr) {
		cout << temp->value << "\n";
		temp = temp->next;
	}
}

