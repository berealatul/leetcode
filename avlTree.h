#pragma once
#include <iostream>
#include <vector>
#include "myFunction.h"
#include "TreeNode.h"
using namespace std;

int height(TreeNode* root);
int balanceFactor(TreeNode* root);
bool isLeftHeavy(TreeNode* root);
bool isRightHeavy(TreeNode* root);
TreeNode* balance(TreeNode* root);
TreeNode* rotateLeft(TreeNode* root);
TreeNode* rotateRight(TreeNode* root);


TreeNode* insert(TreeNode* root, int val) {
	if (!root) return new TreeNode(val);

	if (val < root->val) root->left = insert(root->left, val);
	else root->right = insert(root->right, val);
	return balance(root);
}

TreeNode* balance(TreeNode* root) {
	if (isLeftHeavy(root)) {
		if (balanceFactor(root->left) < 0) {
			root->left = rotateLeft(root->left);
		}
		return rotateRight(root);
	}
	else if (isRightHeavy(root)) {
		if (balanceFactor(root->right) > 0) {
			root->right = rotateRight(root->right);
		}
		return rotateLeft(root);
	}
	return root;
}

bool isLeftHeavy(TreeNode* root) {
	return balanceFactor(root) > 1;
}

bool isRightHeavy(TreeNode* root) {
	return balanceFactor(root) < -1;
}

TreeNode* rotateLeft(TreeNode* root) {
	auto newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	return newRoot;
}

TreeNode* rotateRight(TreeNode* root) {
	auto newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	return newRoot;
}

int balanceFactor(TreeNode* root) {
	if (!root) return 0;
	return height(root->left) - height(root->right);
}

bool isLeaf(TreeNode* root) {
	return !root->left && !root->right;
}

int height(TreeNode* root) {
	if (!root) return -1;
	if (isLeaf(root)) return 0;
	return 1 + max(height(root->left), height(root->right));
}

void getNodeAtDistance(TreeNode* root, int distance, vector<int>& elements) {
	if (!root) return;
	if (!distance) {
		elements.push_back(root->val);
	}
	getNodeAtDistance(root->left, distance - 1, elements);
	getNodeAtDistance(root->right, distance - 1, elements);
}

void levelOrderTransversal(TreeNode* root) {
	vector<vector<int>> output;
	for (int i = 0, n = height(root); i <= n; i++) {
		vector<int> elements;
		getNodeAtDistance(root, i, elements);
		output.push_back(elements);
	}
	printInt2D(output);
}

void inOrderTransversal(TreeNode* root, vector<int>& elements) {
	if (!root) return;
	inOrderTransversal(root->left, elements);
	elements.push_back(root->val);
	inOrderTransversal(root->right, elements);
}

vector<int> inOrderTransversal(TreeNode* root) {
	vector<int> elements;
	inOrderTransversal(root, elements);
	return elements;
}
