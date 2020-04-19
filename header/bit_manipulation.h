/*
 * bubble_sort.h
 *
 *  Created on: 2018¦~10¤ë17¤é
 *      Author: Rich
 */

#ifndef HEADER_BIT_MAN_H_
#define HEADER_BIT_MAN_H_


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


class bit_man_solution{
public:
  void bit_reverse()
  {
    int a =  0x1FFFFFFF;
    int b = 0;

    for(int i=31; i>=0; i--)
    {
    //use iterative way
      b = b + (((a>>i)&0x1)<<(31-i));
      printf("%d\n", b);
    }

    printf("%x ", b);
  }

  void bit_reverse_eff()
  {
    int a =  0x1FFFFFFF;
    int b = 0;

    for(int i=0; i < 32; i++)
    {
      //use iterative way
      b = (b<<1) + ((a>>i)&0x1); //[Note], need to notice the precendence between << & +
    }

    printf("%x ", b);
  }


};

int main_bit_man()
{

  bit_man_solution Give_me_solution;
  Give_me_solution.bit_reverse_eff();

  return 0;

}



#endif /* HEADER_BIT_MAN_H_ */
