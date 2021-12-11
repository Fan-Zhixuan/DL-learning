#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getRow1(int rowIndex) {
        /*原始方法，定义一个二维vector，C结束时为一个完整的杨辉三角形*/
        vector<vector<int>> C(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {//遍历行数
            C[i].resize(i + 1);
            C[i][0] = C[i][i] = 1;//开头结尾置为1
            for (int j = 1; j < i; ++j) {    //遍历位置
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        return C[rowIndex];
    }

    vector<int> getRow2(int rowIndex) {
        /*优化1：使用滚动数组，优化空间复杂度，同时只保存待计算行与待计算行的上一行*/
        vector<int> pre, cur;
        for (int i = 0; i <= rowIndex; ++i) {
            cur.resize(i + 1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; ++j) {
                cur[j] = pre[j - 1] + pre[j];
            }
            pre = cur;
        }
        return pre;
    }

    
    vector<int> getRow3(int rowIndex) {
        /*优化2：只保存一行，每次遍历倒序向前，加前项的值*/
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};


int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    unordered_map<int, int> hashtable;
    cout << nums.size() << endl;
}
