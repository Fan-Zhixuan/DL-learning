#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;
vector<string> fizzBuzz(int n) {
	vector<string> res;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			if (i % 5 == 0) {
				res.emplace_back("FizzBuzz");
			}
			else {
				res.emplace_back("Fizz");
			}
		}
		else if (i % 5 == 0) {
			res.emplace_back("Buzz");
		}
		else {
			res.emplace_back(to_string(i));
		}
	}
}

int main() {


}