/*
 * =====================================================================================
 *
 *       Filename:  ordenArchivo-p.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/10/14 16:57:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>

#include "tools.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
  int
main ( int argc, char *argv[] )
{
  if (argc != 5) {
    puts("Se debe pasar exactamente cuatro (4) argumentos.");
    usage('p');
    exit(EX_USAGE);
  }
  
  int numEnteros = atoi(argv[1]);
  int numNiveles = atoi(argv[2]);
  char* fileIN = argv[3];
  char* fileOUT = argv[4];

  int numbers[numEnteros];

  if ( numEnteros < 0 || numNiveles < 0) {
    fprintf(stderr, "Los números introducidos deben ser mayores a cero\n");
    usage('p');
    exit(EX_USAGE);
  }
}				/* ----------  end of function main  ---------- */

