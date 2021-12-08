#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0, p1, i;
        p0 = p1 = i = 0;
        for (i = 0; i < n; ++i)
        {
            if (nums[i] == 1) {
                swap(nums[p1], nums[i]);
                ++p1;
            }
            else if (nums[i] == 0) {
                swap(nums[p0], nums[i]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};
int main()
{
    return 0;
}