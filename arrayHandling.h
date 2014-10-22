/*
 * =====================================================================================
 *
 *       Filename:  arrayHandling.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/10/14 12:08:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <time.h>


  void  printArray(int* array, int arrayLength)
{
  int i;

  for(i=0; i < arrayLength; i++)
    printf("%d\n",  array[i]);
}

  void
genRandNumbersArray ( int numEnteros, int* numbersArray )
{
    int i, value;
    srand(time(NULL));
    for (i = 0; i < numEnteros; i++)
    {
        value = rand() % 10000 + 1;
        numbersArray[i] = value;
    }
}		/* -----  end of function genRandNumbersArray  ----- */
