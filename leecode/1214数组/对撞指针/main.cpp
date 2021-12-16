#include <iostream>
#include <vector>

using namespace std;
bool isyuanyin(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
		return true;
	}
	else {
		return false;
	}
}
string reverseVowels(string s) {
	int left = 0, right = s.size() - 1;
	while (left != right) {
		if (!isyuanyin(s[left])) {
			left++;
		}
		if (!isyuanyin(s[right])) {
			right--;
		}
		if (isyuanyin(s[left]) && isyuanyin(s[right])){
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
}

int minSubArrayLen(int target, vector<int>& nums) {
	int start = 0, end = 0;
	int sum = 0;
	int n = nums.size();
	int ans = INT_MAX;
	while (end < n) {
		sum += nums[end];
		while (sum >= target) {
			ans = min(ans, end - start + 1);
			sum -= nums[start];
			start++;
		}

		end++;
	}
	return ans == INT_MAX ? 0 : ans;
}


int main() {
	return 0;
}