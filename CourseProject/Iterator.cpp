#include "Iterator.h"

template <class Type> Iterator<Type> Iterator<Type>::operator++() {
	if (node == nullptr) return *this;
	if (node == max) { node = nullptr; return *this; }
	if (node->right != nullptr) node = node->findMin_subTree(node->right);
	else if (node->prev != nullptr) {
		if (node->data > node->prev->data) node = node->prev->prev;
		else node = node->prev;
	}
	return *this;
}

template <class Type> Iterator<Type> Iterator<Type>::operator++(int) {
	if (node == nullptr) return *this;
	if (node == max) { node = nullptr; return *this; }
	if (node->right != nullptr) node = node->findMin_subTree(node->right);
	else if (node->prev != nullptr) {
		if (node->data > node->prev->data) node = node->prev->prev;
		else node = node->prev;
	}
	return *this;
}

template <class Type> Iterator<Type> Iterator<Type>::operator--() {
	if (node == nullptr) return *this;
	if (node == min) { node = nullptr; return *this; }
	if (node->left != nullptr) node = node->findMax_subTree(node->left);
	else if (node->prev != nullptr) {
		if (node->data < node->prev->data) node = node->prev->prev;
		else node = node->prev;
	}
	return *this;
}


template <class Type> Iterator<Type> Iterator<Type>::operator--(int) {
	if (node == nullptr) return *this;
	if (node == min) { node = nullptr; return *this; }
	if (node->left != nullptr) node = node->findMax_subTree(node->left);
	else if (node->prev != nullptr) {
		if (node->data < node->prev->data) node = node->prev->prev;
		else node = node->prev;
	}
	return *this;
}

template <class Type> Iterator<Type> Iterator<Type>::operator+=(int value) {
	for (int i = 0; i < value; i++) {
		if (node == nullptr) return *this;
		this->operator++();
	}
	return *this;
}