#include <iostream>  // Basic input and output library
#include <cstdlib>   // system("pause")
#include <vector>
#include <unordered_map>

using namespace std;

class solution_leet_two_sum {
public:
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);      
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}

	return result;
}
};


int main_twoSum()
{
	//two sum case 
	int target = 6;
	vector<int> nums(4);
	vector<int> result;
	nums = { 3, 2 ,4 };

	//initializae an object  

	solution_leet_two_sum Give_me_solution;
	result = Give_me_solution.twoSum(nums, target);

	cout << result[0] << ' ';
	cout << result[1] << ' ';

	system("pause");
	return 0;
}

