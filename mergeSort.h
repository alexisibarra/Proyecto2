/*
 * =====================================================================================
 *
 *       Filename:  mergeSort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/10/14 15:22:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *           Note: Taken from
 * http://www.programmingsimplified.com/c/source-code/c-program-merge-two-arrays
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
 
void merge(int a[], int m, int b[], int n, int sorted[]) {
  int i, j, k;
 
  j = k = 0;
 
  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  arrayLength
 *  Description:  
 * =====================================================================================
 */
  int
arrayLength ( int ** arr )
{
//  printf("%d\n", sizeof(&array));
//  int len=(sizeof(array)/sizeof(int));
//  printf("%d\n", len);
//  return len;
  int count = 0;
  while(arr[count]){
    printf("%d\n", arr[count]);
    count++;
  }
  return count;
}		/* -----  end of function arrayLength  ----- */
