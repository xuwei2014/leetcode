#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	unordered_map<int, int> hash;
	int diff;
	for (int i = 0; i < nums.size(); ++i) {
	    diff = target - nums[i];
	    if (hash.count(diff)) {
		res.push_back(hash[diff]);
		res.push_back(i + 1);
		break;
	    } else {
		hash[nums[i]] = i + 1;
	    }
	}

	return res;
    }
};


int main()
{
    int a[] = {150,24,79,50,88,345,3};
    vector<int> nums(a, a + 7);

    Solution s;

    vector<int> v = s.twoSum(nums, 200);
    for (int i = 0; i < v.size(); ++i) {
	cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
