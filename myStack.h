#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class myStack {
	vector<int> list;
	int size;
	int count;
public:
	myStack(int size) {
		list.resize(size);
		this->size = size;
		count = 0;
	}

	void push(int val) { 
		if (count == size) throw invalid_argument("Stack is full");
		else list[count++] = val;
	}

	void pop() {
		if (!count) throw invalid_argument("stack is empty");
		else count--;
	}

	int peek() { 
		if (count) return list[count - 1];
		else throw invalid_argument("Stack is empty");
	}

	bool isEmpty() { return count == 0; }
};

