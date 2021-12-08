#include <iostream>
#include <vector>

using namespace std;
#define n 5
class Solution {
public:
    int singleNumber(int* nums,int size) {
        int ret = 0;
        int i = 0;
        for (i = 0; i < size;i++)
            ret ^= nums[i];
        return ret;
    }
};
int main()
{
    //vector<int> nums;
    int ret;
    int nums[n] = { 1, 2, 3, 2, 3 };
    //nums.push_back(1);
    //nums.push_back(2);
    //nums.push_back(3);
    //nums.push_back(2);
    //nums.push_back(3);
    Solution solution = Solution();
    ret = solution.singleNumber(nums,n);
    cout << ret << endl;
}