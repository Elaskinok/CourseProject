#pragma once
//класс "узел дерева"
template <class Type> class treeNode {
	Type data;
	unsigned char height;
	treeNode* left;
	treeNode* right;
	treeNode* prev;
public:
	treeNode() {
		data = 0;
		height = 1;
		left = nullptr;
		right = nullptr;
		prev = nullptr;
	}
	treeNode(Type a) {
		data = a;
		height = 1;
		left = nullptr;
		right = nullptr;
		prev = nullptr;
	}
	treeNode(const treeNode<Type>& node) {
		this->data = node.data;
		this->height = node.height;
		if (node.left != nullptr) {
			left = new treeNode<Type>;
			left = node.left;
		}
		if (node.right != nullptr) {
			right = new treeNode<Type>;
			right = node.right;
		}
		if (node.prev != nullptr) {
			prev = new treeNode<Type>;
			prev = node.prev;
		}
	}
	treeNode<Type>* findMin_subTree(treeNode<Type>* root_subTree) {
		return root_subTree->left ? findMin_subTree(root_subTree->left) : root_subTree;
	}
	treeNode<Type>* findMax_subTree(treeNode<Type>* root_subTree) {
		return root_subTree->right ? findMax_subTree(root_subTree->right) : root_subTree;
	}
	void showSubTree(const int level = 0) {
		const treeNode<Type> *node = this;
		if (node) node->right->showSubTree(level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "  ";
		if (node)
			std::cout << node->data << std::endl;
		else
			std::cout << "@" << std::endl;
		if (node) node->left->showSubTree(level + 1);
	}
	Type getData() { return data; }
	~treeNode() { }
	template <class Type> friend class Tree;
	template <class Type> friend class Iterator;
};

