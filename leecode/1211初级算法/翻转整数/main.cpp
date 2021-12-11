#include <iostream>
#include <vector>

using namespace std;
int reverse(int x) {
	int y = 0;
	//int i = 1;
	while (x != 0) {
		if (y < INT_MIN / 10 || y > INT_MAX / 10) {//判断反转后的数是否越界
			return 0;
		}
		y *= 10;
		y += x % 10;
		x = x / 10;
	}
	return y;
}
int main() {
	int a = -123;
	int b = reverse(a);
	cout << b << endl;
}