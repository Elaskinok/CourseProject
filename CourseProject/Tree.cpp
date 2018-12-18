#include "Tree.h"
#include "FindNodeException.h"
template <class Type> treeNode<Type>* Tree<Type>::find(Type data, treeNode<Type>* root_subTree) {
	if (root_subTree->data == data)
		return root_subTree;
	if (root_subTree->left != nullptr) {
		treeNode<Type>* temp = find(data, root_subTree->left);
		if (temp) return temp;
	}
	if (root_subTree->right != nullptr) {
		treeNode<Type>* temp = find(data, root_subTree->right);
		if (temp) return temp;
	}
	return nullptr;
}

template <class Type> size_t Tree<Type>::size() {
	size_t result = 0;
	for (Tree<Type>::iterator it = this->begin(); it != this->end(); ++it)
		result++;
	return result;
}

template <class Type> treeNode<Type>* Tree<Type>::find(Type data) {
	if (root == nullptr) return nullptr;
	treeNode<Type>* temp = find(data, root);
	if (temp == nullptr) throw FindNodeException("Node isn't found!", "EE0001");
	return temp;
}

template <class Type> void Tree<Type>::clear(treeNode<Type>* root_subTree) {
	if (root_subTree->left != nullptr) clear(root_subTree->left);
	if (root_subTree->right != nullptr) clear(root_subTree->right);
	if (root_subTree != nullptr) delete root_subTree;
}

template <class Type> void Tree<Type>::clear() {
	if (root == nullptr) return;
	clear(root);
	root = nullptr;
}

template <class Type> void Tree<Type>::remove(Type data) {
	if (root == nullptr) return;
	if (!find(data)) throw FindNodeException("Node isn't found!", "EE0001");
	root = remove(root, data);
	repairTree(root, nullptr);
}

template <class Type> void Tree<Type>::show() {
	if (root == nullptr) return;
	root->showSubTree();
}



template <class Type> unsigned char Tree<Type>::height(treeNode<Type>* root_subTree) {
	return root_subTree ? root_subTree->height : 0;
}

template <class Type> int Tree<Type>::balanceFactor(treeNode<Type>* root_subTree) {
	return height(root_subTree->right) - height(root_subTree->left);
}

template <class Type> void Tree<Type>::fixHeight(treeNode<Type>* root_subTree) {
	unsigned char hl = height(root_subTree->left);
	unsigned char hr = height(root_subTree->right);
	root_subTree->height = (hl>hr ? hl : hr) + 1;
}

template <class Type> treeNode<Type>* Tree<Type>::insert(treeNode<Type>* root_subTree, Type data) {
	if (!root_subTree) return new treeNode<Type>(data);
	if (data < root_subTree->data) {
		root_subTree->left = insert(root_subTree->left, data);
		root_subTree->left->prev = root_subTree;
	}
	else if(data > root_subTree->data){
		root_subTree->right = insert(root_subTree->right, data);
		root_subTree->right->prev = root_subTree;
	}
	return balance(root_subTree);
}

template <class Type> void Tree<Type>::repairTree(treeNode<Type>* root_subTree, treeNode<Type>* previous) {
	if (root_subTree == nullptr) return;
	if (root_subTree->left != nullptr) repairTree(root_subTree->left, root_subTree);
	if (root_subTree->right != nullptr) repairTree(root_subTree->right, root_subTree);
	root_subTree->prev = previous;
}


template <class Type> void Tree<Type>::insert(Type data) {
	root = insert(root, data);
	repairTree(root, nullptr);
}

template <class Type> treeNode<Type>* Tree<Type>::balance(treeNode<Type>* root_subTree) {
	fixHeight(root_subTree);
	if (balanceFactor(root_subTree) == 2)
	{
		if (balanceFactor(root_subTree->right) < 0)
			root_subTree->right = rotateRight(root_subTree->right);
		return rotateLeft(root_subTree);
	}
	if (balanceFactor(root_subTree) == -2)
	{
		if (balanceFactor(root_subTree->left) > 0)
			root_subTree->left = rotateLeft(root_subTree->left);
		return rotateRight(root_subTree);
	}
	return root_subTree;
}

template <class Type> treeNode<Type>* Tree<Type>::rotateRight(treeNode<Type>* root_subTree) {
	treeNode<Type>* temp = root_subTree->left;
	root_subTree->left = temp->right;
	temp->right = root_subTree;
	fixHeight(root_subTree);
	fixHeight(temp);
	return temp;
}

template <class Type> treeNode<Type>* Tree<Type>::rotateLeft(treeNode<Type>* root_subTree) {
	treeNode<Type>* temp = root_subTree->right;
	root_subTree->right = temp->left;
	temp->left = root_subTree;
	fixHeight(root_subTree);
	fixHeight(temp);
	return temp;
}

template <class Type> treeNode<Type>* Tree<Type>::findMin(treeNode<Type>* root_subTree) {
	return root_subTree->left ? findMin(root_subTree->left) : root_subTree;
}

template <class Type> treeNode<Type>* Tree<Type>::findMax(treeNode<Type>* root_subTree) {
	return root_subTree->right ? findMax(root_subTree->right) : root_subTree;
}

template <class Type> treeNode<Type>* Tree<Type>::removeMin(treeNode<Type>* root_subTree) {
	if (root_subTree->left == 0)
		return root_subTree->right;
	root_subTree->left = removeMin(root_subTree->left);
	return balance(root_subTree);
}

template <class Type> treeNode<Type>* Tree<Type>::remove(treeNode<Type>* root_subTree, Type data) {
	if (!root_subTree) return nullptr;
	if (data < root_subTree->data)
		root_subTree->left = remove(root_subTree->left, data);
	else if (data > root_subTree->data)
		root_subTree->right = remove(root_subTree->right, data);
	else //  data == root_subTree->data 
	{
		treeNode<Type>* q = root_subTree->left;
		treeNode<Type>* r = root_subTree->right;
		delete root_subTree;
		if (!r) return q;
		treeNode<Type>* min = findMin(r);
		min->right = removeMin(r);
		min->left = q;
		return balance(min);
	}
	return balance(root_subTree);
}