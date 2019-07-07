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
    if((len_a != len_b) || (len_a < 2))
    {
      same_flag = false;
      return same_flag;
    }

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
  /* test sequence
  char str_a[] = "aaaacad";
  char str_b[] = "acaacda";
  */

  char str_a[] = "bagggg";
  char str_b[] = "abggaa";

  bool result;

  solution_buddy_string Give_me_solution;
  result = Give_me_solution.compare(str_a, str_b);

  printf("result = %d\n", result);

  return 0;

}



#endif /* HEADER_LEET_LONGEST_SUBSTRING_NO_REPEAT_CHAR_H_ */
