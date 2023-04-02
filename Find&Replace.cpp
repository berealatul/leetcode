#include <iostream>
#include <string>
using namespace std;

int pos_first(string& os, string& rs) {
	if (os.find(rs) != string::npos) return os.find(rs);
	else - 1;
}

void replace_string(string& os, int start_pos, int len, string& strw) {
	os.replace(start_pos, len, strw);
}

bool search_and_replace(string& os, string& rs, string& strw) {
	int start_pos = pos_first(os, rs);
	if (start_pos < 0) return false;
	else {
		replace_string(os, start_pos, rs.length(), strw);
	}
	return true;
}

void search_and_replace_all(string& os, string& rs, string& strw) {
	while (search_and_replace(os, rs, strw)) {}
}


int main() {
	string os;
	cout << "Insert any string: "; getline(cin, os);
	string rs;
	cout << "Which phrase to replace: "; getline(cin, rs);
	string strw;
	cout << "Phrase to replace with: "; getline(cin, strw);
	cout << os << endl;
	search_and_replace_all(os, rs, strw);
	cout << os << endl;
}