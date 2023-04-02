#pragma once
struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val) : val(val), left(nullptr), right(nullptr) {}
};