#pragma once
#include <vector>
#include <stack>
#include <algorithm> 

using namespace std;


// Time:  O(n)
// Space: O(1)

class MinStack {
public:
	void push(int number) {
		if (elements_.empty()) {
			elements_.emplace(0);
			stack_min_ = number;
		}
		else {
			elements_.emplace(static_cast<int64_t>(number) - stack_min_);
			if (number < stack_min_) {
				stack_min_ = number; // Update min.
			}
		}
	}

	void pop() {
		auto diff = elements_.top();
		elements_.pop();
		if (diff < 0) {
			stack_min_ -= diff; // Restore previous min.
		}
	}

	int top() {
		if (elements_.top() > 0) {
			return stack_min_ + elements_.top();
		}
		else {
			return stack_min_;
		}
	}

	int getMin() {
		return stack_min_;
	}

private:
	stack<int64_t> elements_;
	int stack_min_;
};



void main_MinStack()
{
	cout << "test start\n" << endl;
	//...............tree 1..............

	vector<int> nums = { 6, 2, 5, 1, 2, 1 };

	//................solution...........
	MinStack solution;

	for (int i = 0; i < nums.size(); i++)
	{
		solution.push(nums[i]);
	}

	cout << endl;
	//*
	for (int i = 0; i<nums.size(); i++)
	{	
		cout << solution.getMin() << endl;
		solution.pop();

		cout << endl;
	}
	//*/
	cout << "\n\ntest done" << endl;
	system("pause");


}