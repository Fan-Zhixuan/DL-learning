#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
/*关于旋转数组，最重要的是找到有序的那一半。与右侧边界比较，如果小于右侧边界则右侧有序，反之则左侧有序
  判断每次的中间值与目标值的大小是否处于有序的一侧，如果在有序一侧则回到最原始的二分法问题，如果不在有序一侧，则在另外一侧继续重复上述过程*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {//说明0到mid范围内的数字是有序的
                if (nums[0] <= target && target < nums[mid]) {//target在0到mid之间
                    r = mid - 1;
                }
                else {                 //target位于mid到n-1之间
                    l = mid + 1;
                }
            }
            else {                  //说明mid到n-1范围内的数字是是有序的
                if (nums[mid] < target && target <= nums[n - 1]) {////target在mid到n-1之间
                    l = mid + 1;
                }
                else {             //target在0到mid之间
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};



int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    Solution solution1 = Solution();
    vector<int> retult = solution1.search(nums, 7);
    cout << retult[0] << endl;
    cout << retult[1] << endl;
}