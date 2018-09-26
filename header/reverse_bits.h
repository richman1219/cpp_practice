/*
 * bit_manipulation.h
 *
 *  Created on: 2018¦~9¤ë26¤é
 *      Author: Rich
 */

#ifndef HEADER_REVERSE_BITS_H_
#define HEADER_REVERSE_BITS_H_

#include <iostream>  // Basic input and output library

using namespace std;

class reverse_bits {
public:

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





#endif /* HEADER_REVERSE_BITS_H_ */
