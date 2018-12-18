#pragma once
#include "treeNode.h"
//шаблонный класс дерево
template <class Type> class Tree {
	treeNode<Type>* root;
	treeNode<Type>* find(Type data, treeNode<Type>* root_subTree);
	void clear(treeNode<Type>* root_subTree);
	//insert------------------------------------------------------------------------
	treeNode<Type>* insert(treeNode<Type>* root_subTree, Type data);
	unsigned char height(treeNode<Type>* root_subTree);
	int balanceFactor(treeNode<Type>* root_subTree);
	void fixHeight(treeNode<Type>* root_subTree);
	treeNode<Type>* rotateRight(treeNode<Type>* root_subTree);
	treeNode<Type>* rotateLeft(treeNode<Type>* root_subTree);
	treeNode<Type>* balance(treeNode<Type>* root_subTree);
	//------------------------------------------------------------------------------
	//remove------------------------------------------------------------------------
	treeNode<Type>* findMin(treeNode<Type>* root_subTree);
	treeNode<Type>* removeMin(treeNode<Type>* root_subTree);
	treeNode<Type>* remove(treeNode<Type>* root_subTree, Type data);
	//------------------------------------------------------------------------------
	treeNode<Type>* findMax(treeNode<Type>* root_subTree);
	void repairTree(treeNode<Type>* root_subTree, treeNode<Type>* previous);
public:
	Tree() { root = nullptr; }
	Tree(Type data) {
		root = new treeNode<Type>(data);
	}
	~Tree() { }
	bool isEmpty() { return (root == nullptr) ? true : false; }
	unsigned char getHeight() { return root->height; }
///****************************************************************
	treeNode<Type>* find(Type data);
	size_t size();
	void clear();
	void show();
		//remove Element from Tree
	void remove(Type data);
	void insert(Type data);
///***************************************************************
	template <class Type> friend class myIterator;
	template <class Type> friend class Iterator;
	using iterator = typename Iterator<Type>;
	Iterator<Type> begin() { return root == nullptr ? Iterator<Type>::Iterator(nullptr) : 
		Iterator<Type>::Iterator(findMin(root)); }
	Iterator<Type> end() { return root == nullptr ? Iterator<Type>::Iterator(nullptr) :
		Iterator<Type>::Iterator(findMax(root)->right); }
};

