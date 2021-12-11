#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int firstUniqChar(string s) {
	unordered_map<int, int> frequency;
	for (char c : s) {
		++frequency[c];
	}
	for (int i = 0; i < s.size(); i++) {
		if (frequency[s[i]] == 1) {
			return i;
		}
	}
	return -1;
}


int main() {
	int a = -123;

	cout << a << endl;
}