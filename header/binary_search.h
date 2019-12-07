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
#include <assert.h>

using namespace std;

/*try
 * computation complexity with O(log(n)) solution
 * memory efficiency with O(n) solution
 */

/*Think flow
 *sequential search for middle index
 *remove corner case
 *UT for the function
 *Add assertion for infinite loop condition
*/

/*Note
 */


class solution_binary_search {
public:
  int search(int target, int t_arr[], int len)
  {
    //int len = sizeof(t_arr)/sizeof(int); //[Note], can't use sizeof here, just a pointer of array here, not a whole array, can't be used
    int left_idx = 0;
    int right_idx = len - 1;
    int middle_idx = 0;
    int itr_cnt = 0;

    do{
        if((t_arr[left_idx]==target))
        {
          printf("rslt_idx = %d\n", left_idx);
          return left_idx;
        }
        else if((t_arr[right_idx]==target)) //[Note], need to notice the condition for right_idx
        {
          printf("rslt_idx = %d\n", right_idx);
          return right_idx;
        }

        middle_idx = (left_idx + right_idx)/2;
        printf("middle_idx = %d\n", middle_idx);
        // case 0~2=>1=>(1,2), 0~3=>1=>(1,3)

        if(target >= t_arr[middle_idx])
        {
          left_idx = middle_idx;
        }
        else //target < t_arr[middle_idx]
        {
          right_idx = middle_idx;
        }

        itr_cnt++;
        assert(itr_cnt <= len); //[Note], use assert for infinite loop stopping!!

    }while(1);

  }
};


int main_binary_search()
{
  int t_arr_0[] = {1, 2, 3, 3, 4, 5, 5, 6, 7, 9, 10};
  //int t_arr_1[] = {1, 2, 3, 3, 4, 5, 5, 6, 7, 9, 10};
  int rslt_idx;

  int len = sizeof(t_arr_0)/ sizeof(int);
  solution_binary_search Give_me_solution;
  Give_me_solution.search(9, t_arr_0, len);

  return 0;

}

#endif /* HEADER_BINARY_SEARCH_H_ */
