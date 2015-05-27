#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	int index1 = 0;
	int index2 = nums.size() - 1;
	vector<int> array(nums);
	quick_sort(array, 0, array.size() - 1);

	int sum = array[index1] + array[index2];
	while (sum != target) {
	    if (sum < target) {
		index1 += 1;
	    } else {
		index2 -= 1;
	    }
	    sum = array[index1] + array[index2];
	}

	vector<int> res;
	res.push_back(findIndex(nums, array[index1]));
	res.push_back(findIndex(nums, array[index2]));
	if (res[0] > res[1]) {
	    swap(res[0], res[1]);
	}
 	
	return res;
    }
private:
    int findIndex(vector<int>& nums, int t) {
	for (int i = 0; i < nums.size(); ++i) {
	    if (t == nums[i]) {
		return i + 1;
	    }
	}
	return -1;
    }

    void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
    }

    int partition(vector<int>& nums, int p, int r) {
	int x = nums[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
	    if (nums[j] <= x) {
		i += 1;
		swap(nums[i], nums[j]);
	    }
	}
	swap(nums[i + 1], nums[r]);
	return i + 1;
    }

    void quick_sort(vector<int>& nums, int p, int r) {
	if (p < r) {
	    int q = partition(nums, p, r);
	    quick_sort(nums, p, q - 1);
	    quick_sort(nums, q + 1, r);
	}
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
