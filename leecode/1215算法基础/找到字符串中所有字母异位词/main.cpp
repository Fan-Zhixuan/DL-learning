#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

vector<int> findAnagrams(string s, string p) {
	int lp = p.size();
	int ls = s.size();
	int i = 0;
	vector<int> countp(26);
	vector<int> counts(26);
	vector<int> ans;
	if (lp > ls) {
		return ans;
	}
	for (i = 0; i < lp; i++) {
		countp[p[i] - 'a']++;
		counts[s[i] - 'a']++;
	}
	if (countp == counts) {
		ans.push_back(0);
	}
	for (i = 0; i < ls - lp; i++) {
		counts[s[i] - 'a']--;
		counts[s[i + lp] - 'a']++;
		if (countp == counts) {
			ans.push_back(i + 1);
		}
	}
	return ans;
	
}