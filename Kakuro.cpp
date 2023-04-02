#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> q) {
	cout << q[0] << " " << q[1] << endl;
}

void print_pairs(vector<vector<int>>& data) {
	for (auto a : data) print_array(a);
	cout << "End!" << endl;
}

vector<vector<int>> find_all_pairs(int n) {
	vector<vector<int>> data = {};
	if (n > 10) {
		int x = 9;
		while (x >= (n / 2)) {
			if (x != (n - x))	data.push_back({ x, n - x });
			x--;
		}
	}
	else {
		int x = 1;
		while (x <= (n / 2)) {
			if (x != (n - x)) data.push_back({ x, n - x });
			x++;
		}
	}
	return data;
}

void remove_diff(vector<vector<vector<int>>> & final, int s, int x) {
	vector<vector<int>> tmp;
	for (int j = 0, m = final[s].size(); j < m; j++) {
		if (final[s][j][0] == final[x][0][0] || final[s][j][1] == final[x][0][0]) {
			tmp.push_back({ final[s][j][0] , final[s][j][1] });
		}
		else if (final[s][j][0] == final[x][0][1] || final[s][j][1] == final[x][0][1]) {
			tmp.push_back({ final[s][j][0] , final[s][j][1] });
		}
	}
	final[s] = tmp;
}

void remove_equal(vector<vector<vector<int>>>& finals, int s, int x) {
	vector<vector<int>> tmp;
	for (int j = 0, m = finals[s].size(); j < m; j++) {
		if (finals[x][0][0] == finals[s][j][0] || finals[x][0][0] == finals[s][j][1]) {}
		else if (finals[x][0][1] == finals[s][j][0] || finals[x][0][1] == finals[s][j][1]) {}
		else tmp.push_back({ finals[s][j][0] , finals[s][j][1] });
	}
	finals[s] = tmp;
}

void remove_pairs(vector<vector<vector<int>>> & final, int x) {
	int y = (x % 2 == 0) ? (x + 1) : (x - 1);
	remove_equal(final, y, x);

	int s = x - 2;
	// remove earlier garbage elements
	while (true) {
		if (s > -1) {
			remove_diff(final, s, x);
			s--;
		}
		else break;
	}

	//remove later garbage elements
	int l = final.size();
	s = x + 2;
	while (true) {
		if (s < l) {
			remove_diff(final, s, x);
			s++;
		}
		else break;
	}
}

void find_comb(vector<int>& c) {
	vector<vector<vector<int>>> final;
	for (auto a : c) final.push_back(find_all_pairs(a));
	for (auto a : final) print_pairs(a);
	cout << endl;

	for (int i = 0, n = final.size() - 1; i < n; i++) {
		if (final[i].size() == 1) remove_pairs(final, i);
	}
	for (auto a : final) print_pairs(a);
}

int main() {
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	vector<int> c = { r1, r2, c1, c2, d1, d2 };
	find_comb(c);
}