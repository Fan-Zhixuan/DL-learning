#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
/*������ת���飬����Ҫ�����ҵ��������һ�롣���Ҳ�߽�Ƚϣ����С���Ҳ�߽����Ҳ����򣬷�֮���������
  �ж�ÿ�ε��м�ֵ��Ŀ��ֵ�Ĵ�С�Ƿ��������һ�࣬���������һ����ص���ԭʼ�Ķ��ַ����⣬�����������һ�࣬��������һ������ظ���������*/
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
            if (nums[0] <= nums[mid]) {//˵��0��mid��Χ�ڵ������������
                if (nums[0] <= target && target < nums[mid]) {//target��0��mid֮��
                    r = mid - 1;
                }
                else {                 //targetλ��mid��n-1֮��
                    l = mid + 1;
                }
            }
            else {                  //˵��mid��n-1��Χ�ڵ��������������
                if (nums[mid] < target && target <= nums[n - 1]) {////target��mid��n-1֮��
                    l = mid + 1;
                }
                else {             //target��0��mid֮��
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