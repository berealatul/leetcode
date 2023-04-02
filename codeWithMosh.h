#pragma once
#include <string>
#include <map>
using namespace std;

class codeWithMosh {
public:
	int countVowels(string& s) {
		int count = 0;
		string vowels = "aeiou";
		for (auto& c : s) {
			if (vowels.find(tolower(c)) != -1) count++;
		}
		return count;
	}

	void reverseString(string& s) {
		int left = 0;
		int right = s.length() - 1;
		while (left < right) swap(s[left++], s[right--]);
	}

	string reverseOrderOfWord(string& sentence) {
		string reversedSentence;

		int index = sentence.length() - 1;
		int wordEnd;
		bool wordFound = false;
		
		while (index > 0) {
			if (isalpha(sentence[index]) && !wordFound) {
				wordFound = true;
				wordEnd = index;
			}
			
			if (wordFound && sentence[index] == ' ') {
				reversedSentence += sentence.substr(index + 1, wordEnd - index) + " ";
				wordFound = false;
			}

			index--;
			
			if (!index) {
				if (wordFound) reversedSentence += sentence.substr(index, wordEnd - index + 1);
				else reversedSentence.pop_back();
			}
		}

		return reversedSentence;
	}

	bool areRotations(string& first, string& second) {
		return (first.length() == second.length()
			&& (first + first).find(second) != -1);
	}

	string removeDuplicate(string& s) {
		string newSentence;
		for (auto& c : s) {
			if (newSentence.find(c) == -1) newSentence += c;
		}
		return newSentence;
	}

	char mostRepeatedChar(string& s) {
		map<char, int> repetitionCount;

		for (auto& c : s) repetitionCount[c]++;

		int maximum = -1;
		char character;
		for (auto& pair : repetitionCount) {
			if (pair.second > maximum) {
				character = pair.first;
				maximum = pair.second;
			}
		}
		
		return character;
	}

	void capitalizeFirstChar(string& s) {
		if (!s.empty()) s[0] = toupper(s[0]);

		for (int i = 1, n = s.length(); i < n; i++) {
			if (s[i - 1] == ' ' && isalpha(s[i])) s[i] = toupper(s[i]);
		}
	}

	bool isAnagram(string& first, string& second) {
		if (first.length() != second.length()) return false;

		map<char, int> charCountFirst;
		for (auto& c : first) charCountFirst[c]++;

		for (auto& c : second) {
			charCountFirst[c]--;
			if (charCountFirst[c] < 0) return false;
		}

		return true;
	}

	bool isPalindrome(string& s) {
		if (s.empty()) return false;

		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			if (s[left++] != s[right--]) return false;
		}
		return true;
	}
};

