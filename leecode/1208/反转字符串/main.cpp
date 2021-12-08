#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();  //获取数组长度
        int low = 0;
        int high = n - 1;
        for (low, high; low < high; ++low, --high)
            swap(s[low], s[high]);  //swap()交换内部两个元素
    }
};

int main()
{

}