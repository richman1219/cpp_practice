/*
 * buddy_string.h
 *
 *  Created on: 2018年10月16日
 *      Author: 其懋
 */

#ifndef HEADER_BUDDY_STRING_H_
#define HEADER_BUDDY_STRING_H_

#include <iostream>  // Basic input and output library
#include <stdio.h>
#include <string.h>

using namespace std;

/*try
 * computation complexity with O(1) solution
 * memory efficiency with O(1) solution
 */

/*Think flow
 *sequential search for each pair of characters, and compare the other part
 *remove corner case
 *UT for the function
*/

/*Note
 */


class solution_buddy_string {
public:
  bool compare(char str_a[], char str_b[])
  {
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);

    bool same_flag = true;

    //corner case handling

    //normal case handling
    for(int i=0;i<len_a;i++)
    {

      if(str_a[i] == str_b[i])
      {
        continue;
      }
      else
      {
        if((str_a[i] == str_b[i+1]) && (str_a[i+1] == str_b[i]))
        {
          //continue compare the other part in the string
          if(i + 1 < len_a)
          {
            i = i + 1;
            continue;
          }
        }
        else
        {
          same_flag = false;
        }
      }

    }
  return same_flag;
  }

};


int main_buddy_string()
{
  char str_a[] = "aaabcddd";
  char str_b[] = "aaacbsdd";

  bool result;

  solution_buddy_string Give_me_solution;
  result = Give_me_solution.compare(str_a, str_b);

  printf("result = %d\n", result);

  return 0;

}




#endif /* HEADER_BUDDY_STRING_H_ */
