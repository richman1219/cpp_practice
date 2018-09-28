/*
 * reverse_digits.h
 *
 *  Created on: 2018¦~9¤ë26¤é
 *      Author: Rich
 */

#ifndef HEADER_REVERSE_EVEN_DIGITS_H_
#define HEADER_REVERSE_EVEN_DIGITS_H_

#include <iostream>  // Basic input and output library

using namespace std;

/*try
 * computation complexity with O(1) solution
 * memory efficiency with O(1) solution
 */

/*Think flow
 *Try not to use so much data structure, as less as possible, unless...
*/

/*need to take care
 * sizeof usage
 * printf usage
 * for loop index j--, need to use test pattern to test
 */


class solution_reverse_even_digits {
public:
  void reverse(char str_input[])
  {
    int num_digits = sizeof(str_input)/sizeof(char);
    int i= 0, j = num_digits-1;
    char temp;

    //find even digits
    for (;i<num_digits;i++)
    {
      if((str_input[i]&0x1) == 0x0)
      {
        for (;j >= 0; j--)
        {
          if(i != j)
          {
            if((str_input[j]&0x1) == 0x0)
            {
              //swap
              temp = str_input[i];
              str_input[i] = str_input[j];
              str_input[j] = temp;
              j--;
              break;
            }
          }
          else{ return;} //i==j
         }
       }
     }
    }
};


int main_reverse_string()
{
  char str_input[] = "2633834";

  solution_reverse_even_digits Give_me_solution;
  Give_me_solution.reverse(str_input);

  printf("test");

  //printf("reverse string: %s\n", (char)(str_input[1]));

  return 0;

}


#endif /* HEADER_REVERSE_EVEN_DIGITS_H_ */
