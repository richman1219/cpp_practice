/*
 * buddy_string.h
 *
 *  Created on: 2018年10月16日
 *      Author: 其懋
 */

#ifndef HEADER_FAB_H_
#define HEADER_FAB_H_

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
*F0 = 0, F1=1,  F2 = F0 + F1 = 1, F3=F2+F1=2
*Corner case handling
*[Note] recursive may cause "maximum recursion depth exceeded problem"
  *time complexity= O(2^N), space complexity= O(2^N)
*[Note] use iterative way to optimize
*/

/*Note
 */


class solution_fibonacci{
public:
  int fab(int idx)
  {
    //use recursive method, bottom up, with function stack
      //if idx == 0, return 0
      //if idx == 1, return 1
      //else, return fab(idx-1) + fab(idx-2)

    if(idx == 0)
    {
      return 0;
    }
    else if(idx == 1)
    {
      return 1;
    }
    else
    {
      return fab(idx-1) + fab(idx-2);
    }
  }

  void print_fab(int num_seq)
  {
    for(int i=0; i<num_seq; i++)
    printf("%d ", fab(i));
  }

  void fab_iter(int idx)
  {
      //use iterative way, save calculated value into array
    int f[idx];
    f[0]=0, f[1]=1;


    for(int i=0; i<idx; i++)
    {
      if(i == 0)
      {
        printf("0 ");
      }
      else if(i == 1)
      {
        printf("1 ");
      }
      else
      {
        f[i] = f[i-1] + f[i-2];
        printf("%d ", f[i]);
      }
    }

    return;
  }




};


int main_fibonacci()
{
  solution_fibonacci Give_me_solution;
  //Give_me_solution.print_fab(10);
  Give_me_solution.fab_iter(10);

  return 0;
}

#endif /* HEADER_FAB_H_ */
