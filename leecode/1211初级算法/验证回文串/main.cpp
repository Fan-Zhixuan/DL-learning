#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPalindrome(string s) {
	int n = s.size();
	int low = 0, high = n - 1;
	while (low < high) {
		while (!isalnum(s[low])) {
			low++;
		}
		while (!isalnum(s[high])) {
			high--;
		}
		if (low < high) {
			if (tolower(s[low]) != tolower(s[high])) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	return 0;

}