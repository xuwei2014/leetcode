#include <iostream>
#include <set>

using namespace std;

/*
 * 也可以使用map
 * key存储字符，value存储下标
 * 则在重复出现时可以直接修改i的值到指定位置
 * 使得时间复杂度从O（2n）降为O（n）
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	if (s.empty()) {
	    return 0;
	}

	int i = 0;
	int longest = 1;
	set<char> chars;
	chars.insert(s[0]);

	for (int j = 1; j < s.size(); ++j) {
	    if (chars.count(s[j])) {
		while (s[i] != s[j]) {
		    chars.erase(s[i]);
		    ++i;
		}
		++i;
	    } else {
		chars.insert(s[j]);
		if (longest < (j - i + 1)) {
		    longest = j - i + 1;
		}
	    }
	}

	return longest;
    }
};

int main()
{
    string str = "afgbcaecbb";

    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    
    return 0;
}
