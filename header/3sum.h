#pragma once

#include <vector>
#include <stack>
#include <algorithm> 

using namespace std;


// Time:  O(n^2)
// Space: O(1)
class solution_3sum {
public:
	/**
	* @param numbers : Give an array numbers of n integer
	* @return : Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> ans;
		const int target = 0;

		// Make nums in increasing order. Time: O(nlogn)
		sort(nums.begin(), nums.end());

		for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
			if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
				for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
					if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
						++j;
					}
					else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
						--k;
					}
					else {
						const auto sum = nums[i] + nums[j] + nums[k];
						if (sum > target) {  // Should decrease sum.
							--k;
						}
						else if (sum < target) {  // Should increase sum.
							++j;
						}
						else {
							ans.push_back({ nums[i], nums[j], nums[k] });
							++j, --k;
						}
					}
				}
			}
		}

		return ans;
	}
};



void main_3sum()
{
	cout << "test start\n" << endl;
	//...............tree 1..............

	vector<int> nums;
	nums = { 1, -1, 3, 2, -2, 0 };

	//................solution...........
	vector<vector<int>> result;
	solution_3sum solution;
	result = solution.threeSum(nums);

	cout << endl;
	//*
	for (int i = 0; i<result.size(); i++)
	{
		cout << result[i][0];
		cout << result[i][1];
		cout << result[i][2];
		cout << endl;
	}
	//*/
	cout << "\n\ntest done" << endl;
	system("pause");

}
