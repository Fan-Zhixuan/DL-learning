#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getRow1(int rowIndex) {
        /*ԭʼ����������һ����άvector��C����ʱΪһ�����������������*/
        vector<vector<int>> C(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {//��������
            C[i].resize(i + 1);
            C[i][0] = C[i][i] = 1;//��ͷ��β��Ϊ1
            for (int j = 1; j < i; ++j) {    //����λ��
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        return C[rowIndex];
    }

    vector<int> getRow2(int rowIndex) {
        /*�Ż�1��ʹ�ù������飬�Ż��ռ临�Ӷȣ�ͬʱֻ�������������������е���һ��*/
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
        /*�Ż�2��ֻ����һ�У�ÿ�α���������ǰ����ǰ���ֵ*/
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
