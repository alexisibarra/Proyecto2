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
  
  genRandNumbersArray( numElems, numbersArray);

  printArray(numbersArray, numElems);

  writeToBinFile("borrame", numbersArray, numElems);

  int readInit = atoi(argv[2]); 
  int readSize = atoi(argv[3]);
  int readArray[readSize];

  printf ( "Despues de escribirlo en el binario:\n" );
  /*readFromBinFile("borrame", readArray, numElems);*/
  readChunkFromBinFile("borrame.bin", numElems, readArray, readInit, readSize);
  printArray(readArray, readSize);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
