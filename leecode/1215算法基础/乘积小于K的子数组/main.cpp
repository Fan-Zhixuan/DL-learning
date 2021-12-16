#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int len = nums.size();
	int ans = 0;
	int left = 0;
	int tmp = 1;
	for (int i = 0; i < len; i++) {
		tmp *= nums[i];
		while (tmp >= k) {
			tmp /= nums[left];
			left++;
		}
		ans+= i - left + 1;
	}
	return ans;
}