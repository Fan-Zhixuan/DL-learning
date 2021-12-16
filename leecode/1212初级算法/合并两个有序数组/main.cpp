#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int p1 = m-1, p2 = n-1;
	int len = nums1.size()-1;
	while (p1 >= 0 || p2 >= 0) {
		if (p1 == -1) {
			nums1[len] = nums2[p2];
			p2--;
		}
		else if(p2 == -1) {
			nums1[len] = nums1[p1];
			p1--;
		}
		else if (nums1[p1] > nums2[p2]) {
			nums1[len] = nums1[p1];
			p1--;
		}
		else {
			nums1[len] = nums2[p2];
			p2--;
		}
		len--;
	}
}



int main()
{
	return 0;
}