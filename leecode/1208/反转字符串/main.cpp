#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();  //��ȡ���鳤��
        int low = 0;
        int high = n - 1;
        for (low, high; low < high; ++low, --high)
            swap(s[low], s[high]);  //swap()�����ڲ�����Ԫ��
    }
};

int main()
{

}