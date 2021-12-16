#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int i = 0, j = 0;
	int n = nums.size();
	for (i = 0; i < n; i++) {
		if (nums[i] != 0) {
			nums[j] = nums[i];
			j++;
		}
	}
	for (j; j < n; j++) {
		nums[j] = 0;
	}
}
int removeElement(vector<int>& nums, int val) {
	int i = 0, j = 0;
	int n = nums.size();
	for (i = 0; i < n; i++) {
		if (nums[i] != val) {
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}

int removeDuplicates(vector<int>& nums) {
	int i = 0, j = 0;
	int n = nums.size();
	for (i = 0; i < n; i++) {
		if (nums[i] != nums[i + 1]) {
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}

int main() {
	return 0;
}