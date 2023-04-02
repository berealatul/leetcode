#pragma once
#include <iostream>
#include <vector>
using namespace std;

class treeValidate {
public:
	vector<int> getTreeData() {
		return data;
	}

	void validateTreeData(vector<int>& output, string order) {
		vector<int> ans = getAnswerFor(order);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " - " << output[i];
			if (ans[i] != output[i]) cout << " error";
			cout << endl;
		}
	}

	vector<int> getAnswerFor(string order) {
		if (order == "level") {
			cout << "Level Order Transversal Validating" << endl;
			return level;
		}
		else if (order == "pre") {
			cout << "Pre Order Transversal Validating" << endl;
			return pre;
		}
		else if (order == "in") {
			cout << "In Order Transversal Validating" << endl;
			return in;
		}
		else {
			cout << "Post Order Transversal Validating" << endl;
			return post;
		}
	}

private:
	vector<int> data = { 20, 30, 24, 26, 10, 6, 14, 3, 8 };
	vector<int> level = { 20, 10, 30, 6, 14, 24, 3, 8, 26 };
	vector<int> pre = { 20, 10, 6, 3, 8, 14, 30, 24, 26 };
	vector<int> in = { 3, 6, 8, 10, 14, 20, 24, 26, 30 };
	vector<int> post = { 3, 8, 6, 14, 10, 26, 24, 30, 20 };
};

