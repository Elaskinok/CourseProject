#pragma once
#include "Tree.h"
//класс-итератор для дерева
template <class Type> class Iterator {
	treeNode<Type>* node;
	treeNode<Type>* min;
	treeNode<Type>* max;
	treeNode<Type>* findRoot(treeNode<Type>* node) { return node->prev == nullptr ? node : findRoot(node->prev); }
public:
	Type operator*() { return node == nullptr ? Type() : node->data; }
	Type* operator->() { return &node->data; }
	Iterator<Type> operator++();
	Iterator<Type> operator++(int);
	Iterator<Type> operator--();
	Iterator<Type> operator--(int);
	Iterator<Type> operator+=(int value);
	bool operator!=(const Iterator& obj) { return node != obj.node ? true : false; }
	bool operator==(const Iterator& obj) { return node == obj.node ? true : false; }
	bool good() { return node == nullptr ? false : true; }
	Iterator() { node = nullptr; min = nullptr; max = nullptr; }
	Iterator(treeNode<Type>* node) {
		this->node = node;
		if (node != nullptr) {
			min = node->findMin_subTree(findRoot(node));
			max = node->findMax_subTree(findRoot(node));
		}
		else {
			min = nullptr;
			max = nullptr;
		}
	}
};

