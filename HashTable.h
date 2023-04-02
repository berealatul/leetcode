#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class HashTable {
	class Node {
	public:
		string val;
		Node* next;
		Node(string val) : val(val), next(nullptr) {}
	};
	map<int, Node*> table;
public:
	void put(int key, string value) {
		Node* buffer = new Node(value);

		if (!table.count(key)) {
			table.insert(make_pair(key, buffer));
		}
		else {
			Node* pointer = table[key];
			while (pointer->next) pointer = pointer->next;
			pointer->next = buffer;
		}
	}

	int get(int key) {
		if (table.count(key)) {
			Node* pointer = table[key];
			while (pointer) {
				cout << key << " - " << pointer->val << endl;
				pointer = pointer->next;
			}
		}
		else throw invalid_argument("Doesn't Exist");
	}

	void remove(int key) {
		if (table.count(key)) table.erase(key);
		else throw invalid_argument("Doesn't Exist");
	}

	void print() {
		for (auto& pair : table) {
			Node* pointer = pair.second;
			while (pointer) {
				cout << pair.first << " - " << pointer->val << endl;
				pointer = pointer->next;
			}
			cout << endl;
		}
	}
};