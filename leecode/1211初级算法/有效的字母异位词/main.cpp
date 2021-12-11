#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


bool isAnagram(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	unordered_map<int, int> frequencys;
	unordered_map<int, int> frequencyt;
	for (char c : s) {
		++frequencys[c];
	}
	for (char c : t) {
		++frequencyt[c];
	}
	for (int i = 0; i < s.size(); i++) {
		if (frequencys[s[i]] != frequencyt[s[i]]) {
			return false;
		}
	}
	return true;
}


int main() {
	int a = -123;
	string s = "anagram", t = "nagaram";

	cout << isAnagram(s, t) << endl;
}