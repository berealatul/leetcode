#include <iostream>
#include <string>
using namespace std;

class node {
private:
	bool is_ans;
	string text;
	node* false_ans;
	node* true_ans;
public:
	node() {
		is_ans = true;
		text = "rock";
		false_ans = NULL;
		true_ans = NULL;
	}
	node(string s) {
		is_ans = true;
		text = s;
		false_ans = NULL;
		true_ans = NULL;
	}

	bool ask_question() {
		if (is_ans) {
			cout << "Ok, I'm ready to guess: is it " << text << "? (Answer Yes or No): ";
			string ans; cin >> ans;
			if (ans == "y") return true;
			else {
				cout << "What were you thinking of? ";
				cin >> ans;
				cout << "Help me learn. What is a question that would help me distinguish "
					<< text << " from " << ans << "?\n";
				string question; getline(cin, question);
				getline(cin, question);
				true_ans = new node(ans);
				false_ans = new node(text);
				text = question;
				is_ans = false;
				return false;
			}
		}
		else {
			cout << text << " (Answer Yes or No): ";
			string ans; cin >> ans;
			if (ans == "y") return true_ans->ask_question();
			else return false_ans->ask_question();
		}
	}
};

int main() {
	node firstnode;
	cout << "Would you like to play 20 questions? ";
	string ans; cin >> ans;
	while (ans == "y") {
		cout << "Think of any one word items and then press y and enter to go! "; cin >> ans;
		if (firstnode.ask_question()) cout << "\nI won!!!\n";
		else cout << "OK, I guess I lost...\n";
		cout << "Would you like to play again: ";
		cin >> ans;
		cout << endl;
	}

}