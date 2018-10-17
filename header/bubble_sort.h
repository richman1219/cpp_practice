/*
 * bubble_sort.h
 *
 *  Created on: 2018¦~10¤ë17¤é
 *      Author: Rich
 */

#ifndef HEADER_BUBBLE_SORT_H_
#define HEADER_BUBBLE_SORT_H_


#include <iostream>  // Basic input and output library
#include <stdio.h>
#include <string.h>

using namespace std;

/*complexity
 * computation complexity with O(n^2) solution
 * memory efficiency with O(n^2) solution
 */

/*Think flow
 *sequential search for each pair of characters, and compare the other part
 *remove corner case
 *lower the complexity
 *UT for the function
*/

/*Note
 * difference between string array and int array in sizeof!!
 */


class bubble_sort_solution{
public:
  void sorting(int input_arr[], int size)
  {
    int temp = 0;
    //int num_ele = sizeof(input_arr)/ sizeof(int);

    int num_ele = size;

    for(int j = num_ele - 1; j > 0; j--)
    {
      for(int i = 0; i < j; i++)
      {
        if(input_arr[i] > input_arr[i+1])
         {
           temp = input_arr[i];
           input_arr[i] = input_arr[i+1];
           input_arr[i+1] = temp;
         }
      }
    }
  }
};

int main_bubble_sort()
{
  int input_arr[5] = {3, 1, 2, 4, 7};
  int num_ele = sizeof(input_arr)/ sizeof(int);

  bubble_sort_solution Give_me_solution;
  Give_me_solution.sorting(input_arr, num_ele);

  for(int i=0; i<num_ele; i++)
  {
    printf("%d ", input_arr[i]);
  }

  return 0;

}



#endif /* HEADER_BUBBLE_SORT_H_ */
