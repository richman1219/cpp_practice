/*
 * peakIndexInMountainArray.h
 *
 *  Created on: 2018¦~10¤ë17¤é
 *      Author: Rich
 */

#ifndef HEADER_PEAKINDEXINMOUNTAINARRAY_H_
#define HEADER_PEAKINDEXINMOUNTAINARRAY_H_

#include <iostream>  // Basic input and output library
#include <stdio.h>
#include <string.h>

using namespace std;

/*complexity
 * computation complexity with O(n) solution
 * memory efficiency with O(n) solution
 */

/*Think flow
 *sequential search for each pair of characters, and compare the other part
 *remove corner case
 *lower the complexity: binary search
 *UT for the function
*/

/*Note
 * difference between string array and int array in sizeof!!
 */



class peakIndexInMountainArray{
public:
  int find(int arr[], int size)
  {
    int left=0, right=size-1;
    int middle = 0;

    while(left < right)
    {



    }

    return middle;
  }

};

void main_peakIndexInMountainArray()
{
  int arr[] = {1, 3, 6, 6, 7, 9, 10};
  int size = sizeof(arr)/sizeof(int);

  peakIndexInMountainArray solution;
  solution.find(arr, size);

}


#endif /* HEADER_PEAKINDEXINMOUNTAINARRAY_H_ */
