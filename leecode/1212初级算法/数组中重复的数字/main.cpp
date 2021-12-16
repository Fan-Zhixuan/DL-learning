#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
	int n = nums.size();
	int i = 0;
	while (i < n) {
		if (nums[i] == nums[nums[i]]) {
			return nums[i];
		}
		if (i == nums[i]) {
			i++;
			continue;
		}
		swap(nums[i], nums[nums[i]]);
	}
	return -1;
}
int main() {
	return 0;
}