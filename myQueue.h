#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <stack>
using namespace std;

class arrayQueue {
	vector<int> list;
	int front, rear, size;
public:
	arrayQueue(int size) : front(-1), rear(0), size(size) { list.resize(size); }

	void enqueue(int val) {
		if (isFull()) { throw invalid_argument("Queue Full"); }

		if (front == -1) front = 0;

		list[rear] = val;
		rear = (rear + 1) % size;
	}

	int dequeue() {
		if (isEmpty()) { throw invalid_argument("Queue Empty");	}
		int buffer = list[front];
		front = (front + 1) % size;
		return buffer;
	}

	bool isFull() {
		return (rear == front || (!front && rear == size));
	}

	bool isEmpty() { return front == -1; }

	int peek() {
		if (isEmpty()) throw invalid_argument("Queue Empty");
		return list[front];  
	}
};

class stackQueue {
	stack<int> first;
	stack<int> second;
public:
	void enqueue(int val) { first.push(val); }

	void dequeue() {
		if (isEmpty()) { 
			throw invalid_argument("Queue Empty");
		}
		
		if (second.empty()) { reverseStack(); }
		second.pop();
	}

	int peek() {
		if (isEmpty()) {
			throw invalid_argument("Queue Empty");
		}

		if (second.empty()) { reverseStack(); }
		return second.top();
	}

	bool isEmpty() {
		return (first.empty() && second.empty());
	}

private:
	void reverseStack() {
		while (!first.empty()) {
			second.push(first.top());
			first.pop();
		}
	}
};

class priorityQueue {
	vector<int> list;
	int count = 0;
public:
	priorityQueue(int size) { list.resize(size, 0); }

	void enqueue(int val) {
		count++;
		if (list.empty()) list.push_back(val);
		else {
			list.push_back(INT_MIN);
			int i;
			for (i = list.size() - 2; i >= 0; i--) {
				if (list[i] > val) list[i + 1] = list[i];
				else break;
			}
			list[i + 1] = val;
		}
	}

	void dequeue() {
		if (!count) throw invalid_argument("Queue Empty");
		for (int i = 0; i < count; i++) {
			list[i] = list[i + 1];
		}
		list[count] = 0;
	}

	int peek() {
		if (!count) throw invalid_argument("Queue Empty");
		return list[0];
	}

	void print() {
		for (auto& x : list) cout << x << " ";
		cout << endl;
	}
};