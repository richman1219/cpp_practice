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

class solution_reverse_even_digits {
public:
  void reverse(char str_input[])
  {
    int num_digits = sizeof(str_input)/sizeof(char);
    int *stored_even_digit = new int [];
    int j = 0;

    //find even digits
    for (int i; i<num_digits;i++)
    {
      if((str_input[i]&0x1) == 0x0)
      {
        stored_even_digit[j] = &str[i];
        j++;
      }
    }

    //reverse stored even digit value
    num_digits = sizeof(stored_even_digit)/sizeof(int)/2;
    int temp;

    for (int i; i<num_digits;i++)
    {
      //swap even digits value
      temp = *(stored_even_digit[i]);
      *(stored_even_digit[i]) = *(stored_even_digit[num_digits-i]);
      *(stored_even_digit[num_digits-i]) = temp;
    }
  }
};


int main_reverse_string()
{
  char str_input[] = "2633834";

  solution_reverse_even_digits Give_me_solution;
  Give_me_solution.reverse(str_input);

  system("pause");
  return 0;
}





#endif /* HEADER_REVERSE_EVEN_DIGITS_H_ */
