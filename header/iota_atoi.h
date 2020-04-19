/*
 * iota_atoi.h
 *
 *  Created on: 2018年10月16日
 *      Author: 其懋
 */

#ifndef HEADER_IOTA_ATOI_H_
#define HEADER_IOTA_ATOI_H_

#include <iostream>  // Basic input and output library
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;

/*try
 * computation complexity with O(n) solution
 * memory efficiency with O(1) solution
 */

/*Think flow
 *char operation for C
 *remove corner case
*/

/*Note
 */


class solution_atoi_itoa {
public:
  int atoi(char s[])
  {
    int i=0,n=0,sign=0;

    sign=(s[0]=='-')?-1:1; //[Note] use this for short if else statement
    if(sign==-1)
    {
      i++;
    }

    while(s[i]!='\0')
    {
      if(s[i]<'0'||s[i]>'9')
      {
        break; //[Note] use this to break when not between 0~9
      }

      n = n*10 +( s[i] - '0');
      i++;
    }

    return n*sign;
  }

  void itoa(int s, char a[])
  {
    int i=0, c=0, sign=1;

    if(s<0)
    {
      s=-s;
      sign=-1;
    }

    do
    {
      a[i++] = s%10 +'0'; //[Note],  char add some offset is char already
      printf("%d ", s);
    }while((s/=10)>0); //[Note], use  /= fast operation for calculation more efficiently

    if(sign==-1)
    {
      a[i++]='-';
    }

    for(int j=i-1; j>=0; j--) //[Note], because i++, need to take care the start point
    {
      printf("%c",a[j]);
    }


  }
};


int main_atoi()
{
  char a[] ="2469a33";

  //int len = sizeof(t_arr_0)/ sizeof(char);
  solution_atoi_itoa Give_me_solution;
  int rslt = Give_me_solution.atoi(a);

  printf("rslt = %d", rslt);

  return 0;

}

int main_itoa()
{
  int s = 256934;
  char a[20];

  //int len = sizeof(t_arr_0)/ sizeof(char);
  solution_atoi_itoa Give_me_solution;
  Give_me_solution.itoa(s, a);

  return 0;
}

#endif /* HEADER_IOTA_ATOI_H_ */
