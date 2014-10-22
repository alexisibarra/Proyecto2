/*
 * =====================================================================================
 *
 *       Filename:  testFilesGenerator.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/10/14 21:49:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "../arrayHandling.h"
#include "../fileHandling.h"
#include "../quickSort.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
  int
main ( int argc, char *argv[] )
{
  int elems[6] = {15, 25, 255, 550, 1000};
  int n;

  for ( n = 0; n < 5; n += 1 ) {
    int ranElems[elems[n]];
    char filenameIN[80] ;
    char filenameOUT[80] ;

    genRandNumbersArray(elems[n], ranElems);

    sprintf(filenameIN, "in%d.bin", elems[n]);
    sprintf(filenameOUT, "out%d.bin", elems[n]);

    writeToBinFile(filenameIN, ranElems, elems[n]);

    quickSort(ranElems, 0, elems[n]);

    writeToPlainFile(filenameOUT, ranElems, elems[n]);
  }
  return 0;
}				/* ----------  end of function main  ---------- */

