/*
 * leet_longest_substring_no_repeat_char.h
 *
 *  Created on: 2019年7月7日
 *      Author: 其懋
 */

#ifndef HEADER_LEET_LONGEST_SUBSTRING_NO_REPEAT_CHAR_H_
#define HEADER_LEET_LONGEST_SUBSTRING_NO_REPEAT_CHAR_H_


#include <iostream>  // Basic input and output library
#include <stdio.h>
#include <string.h>

using namespace std;

/*try
 * computation complexity with O(n) solution
 * memory efficiency with O(n) solution
 */

/*Think flow
 *sequential search from start char and
 *we need search function
 *remove corner case
 *UT for the function
*/

/*Note
 */


class solution_find_longest_substring {
public:
  int search(char input_str[])
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


int main_longest_substring()
{

  char str_a[] = "abcade";
  char str_b[] = "abgaacde";

  bool result;

  solution_find_longest_substring Give_me_solution;
  result = Give_me_solution.search(str_a);

  printf("result = %s\n", result);

  return 0;

}



#endif /* HEADER_LEET_LONGEST_SUBSTRING_NO_REPEAT_CHAR_H_ */
