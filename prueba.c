#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>
#include <time.h>
#include "fileHandling.h"
#include "arrayHandling.h"

  int
main ( int argc, char *argv[] )
{
  int numElems = atoi(argv[1]);
  int numbersArray[numElems];
  genRandNumbersArray( atoi(argv[1]), numbersArray);
  
  printf ( "Antes de escribirlo en el binario:\n" );
  printArray(numbersArray, numElems);
  writeToBinFile("borrame", numbersArray, numElems);

  int readArray[numElems];
  readFromBinFile("borrame", readArray, numElems);
  printf ( "Despues de escribirlo en el binario:\n" );
  printArray(readArray, numElems);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
