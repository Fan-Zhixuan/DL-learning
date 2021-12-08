#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        int low,high = 0;
        int i = 0;
        while (i < length )
        {
            low = i;
            while (i < length && s[i] != ' ')//ÿ��Ѱ�ҿո�Ҫ�޶�Ѱ�ҵķ�Χ
            {
                i++;
            }
            high = i-1;
            for (low, high; low < high; ++low, --high)
                swap(s[low], s[high]);  //swap()�����ڲ�����Ԫ��
            while (i < length && s[i] == ' ')
            {
                i++;
            }
        }
        return s;
    }
};
int main()
{
    string s = "Let's take LeetCode contest";
    Solution solution1 = Solution();
    solution1.reverseWords(s);
    cout << s << endl;
	return 0;
}