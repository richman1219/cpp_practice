/*
 * buddy_string.h
 *
 *  Created on: 2018年10月16日
 *      Author: 其懋
 */

#ifndef HEADER_BINARY_SEARCH_H_
#define HEADER_BINARY_SEARCH_H_

#include <iostream>  // Basic input and output library
#include <stdio.h>
#include <string.h>

using namespace std;

/*try
 * computation complexity with O(n) solution
 * memory efficiency with O(n) solution
 */

/*Think flow
 *sequential search for each pair of characters, and compare the other part
 *remove corner case
 *UT for the function
*/

/*Note
 */


class solution_binary_search {
public:
  void search(char str_a[])
  {
    str_a[2] = 'c';
  }

};


int main_binary_search()
{
  char str_a[] = "bagggg";
  char str_b[] = "abggaa";

  solution_binary_search Give_me_solution;
  Give_me_solution.search(str_a);

  printf("result = %s\n", str_a);

  return 0;

}




#endif /* HEADER_BINARY_SEARCH_H_ */
