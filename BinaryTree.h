#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include <algorithm>
using namespace std;

class Tree {
	Node* root;
public:
	Tree() { root = nullptr; }

	Node* getNode() { return root; }
	
	void insert(int val) {
		auto buffer = new Node(val);

		if (!root) {
			root = buffer;
			//printTree(root);
			return;
		}

		auto pointer = root;
		while (pointer) {
			if (val > pointer->val) {
				if (!pointer->right) {
					pointer->right = buffer;
					//printTree(pointer);
					return;
				}
				pointer = pointer->right;
			}
			else {
				if (!pointer->left) {
					pointer->left = buffer;
					//printTree(pointer);
					return;
				}
				pointer = pointer->left;
			}
		}
	}

	bool find(int val) {
		auto current = root;
		while (current) {
			if (val < current->val) current = current->left;
			else if (val > current->val) current = current->right;
			else return true;
		}
		return false;
	}

private:
	void printTree(Node* pointer) {
		if (pointer->left) cout << "left - " << pointer->left->val << endl;
		cout << "middle - " << pointer->val << endl;
		if (pointer->right) cout << "right - " << pointer->right->val << endl;
		cout << "____________________" << endl;
	}
};

// order of transversal => root->left->right
void preOrderTransversal(Node* root, vector<int>& elements) {
	if (!root) return;

	elements.push_back(root->val);
	preOrderTransversal(root->left, elements);
	preOrderTransversal(root->right, elements);
}

// order of transversal => left->root->right
void inOrderTransversal(Node* root, vector<int>& elements) {
	if (!root) return;

	inOrderTransversal(root->left, elements);
	elements.push_back(root->val);
	inOrderTransversal(root->right, elements);
}

// order of transversal => left->right->root
void postOrderTransversal(Node* root, vector<int>& elements) {
	if (!root) return;

	postOrderTransversal(root->left, elements);
	postOrderTransversal(root->right, elements);
	elements.push_back(root->val);
}

// check if node is last node
bool isLeafNode(Node* root) {
	return (!root->left && !root->right);
}

// height of a binary tree
int height(Node* root) {
	if (!root || isLeafNode(root)) return 0;
	return 1 + max(height(root->left), height(root->right));
}

// minimum value of tree
int min(Node* root) {
	if (!root) return INT_MAX;
	if (isLeafNode(root)) return root->val;

	auto left = min(root->left);
	auto right = min(root->right);
	return min(min(left, right), root->val);
}

bool isTreeEqual(Node* first, Node* second) {
	if (!first && !second) return true;

	if (first && second) {
		return (first->val == second->val 
			    && isTreeEqual(first->left, second->left) 
			    && isTreeEqual(first->right, second->right));
	}
	return false;
}

// always consider the case of what is min and max value that node can stored and use bigger variables for min and max
bool isBST(Node* root, long min = LONG_MIN, long max = LONG_MAX) {
	if (!root) return true;
	if (root->val <= min || root->val >= max) return false;
	return (isBST(root->left, min, root->val)
		&& isBST(root->right, root->val, max));
}

void getNodesAtDistance(Node* root, int distance, vector<int>& elements) {
	if (!root) return;

	if (!distance) {
		elements.push_back(root->val);
		return;
	}
	getNodesAtDistance(root->left, distance - 1, elements);
	getNodesAtDistance(root->right, distance - 1, elements);
}

void levelOrderTransversal(Node* root, vector<int>& elements) {
	for (int i = 0; i <= height(root); i++) {
		getNodesAtDistance(root, i, elements);
	}
}
