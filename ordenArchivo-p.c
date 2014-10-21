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


void usage( char tipo ){
  printf ("\nSINOPSIS:\n\t ordenArchivo-%c NumEnteros NumNiveles " 
      "ArchivoEnterosDesordenado ArchivoEnterosOrdenado\n", 
      tipo
  ); 
  printf ("DESCRIPCION:\n"
      "\tNumEnteros:\n\t\t cantidad total de enteros a ordenar\n" 
      "\tNumNiveles:\n\t\t profundidad del árbol de procesos/hilos\n"
      "\tArchivoEnterosDesordenado:\n\t\t nombre del archivo que almacena los "
        "enteros en forma desordenada.\n"  
      "\tArchivoEnterosOrdenado:\n\t\t nombre del archivo donde se almacenarán "
        "los enteros ordenados.\n"
  );
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  setNumbersInFile
 *  Description:  
 * =====================================================================================
 */
  int
setNumbersInFile ( char* path, int* numbers, int cantNum )
{
  FILE* fp = NULL;

  if ((fp = fopen(path, "w")) == 0){
    perror("El archivo no se puede abrir; fopen");
    exit(EX_USAGE);
  }

  int n;
  for ( n = 0; n < cantNum; n += 1 ) {
    fprintf ( fp, "%d\n", numbers[n] );
  }

  return 0;
}		/* -----  end of function setNumbersInFile  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getNumbersFromFile
 *  Description:  
 * =====================================================================================
 */
 int
getNumbersFromFile ( char* path, int* numbers, int cantNum )
{
  FILE* fp = NULL;
  int numRead = 0;
  int counter = 0;

  if ((fp = fopen(path, "r")) == 0){
    perror("El archivo no se puede abrir; fopen");
    exit(EX_USAGE);
  }

  while (!feof (fp)) {  
    if ( fscanf (fp, "%d", &numRead) > 0 ) {
      numbers[counter] = numRead;
      counter++;
    } 
  }

  fclose (fp); 

  if (counter != cantNum){
    fprintf(stderr, "Error en cantidad de números en línea de comandos y/o"
        " archivo de entrada\n");
    exit(EX_DATAERR);
  } 

  return 0;
}		/* -----  end of function getNumbersFromFile  ----- */

///* 
// * ===  FUNCTION  ======================================================================
// *         Name:  main
// *  Description:  
// * =====================================================================================
// */
//  int
//main ( int argc, char *argv[] )
//{
//	if (argc != 5) {
//		puts("Se debe pasar exactamente cuatro (4) argumentos.");
//    usage('p');
//		exit(EX_USAGE);
//	}
//  
//  int numEnteros = atoi(argv[1]);
//  int numNiveles = atoi(argv[2]);
//  char* fileIN = argv[3];
//  char* fileOUT = argv[4];
//
//  int numbers[numEnteros];
//
//  if ( numEnteros < 0 || numNiveles < 0) {
//    fprintf(stderr, "Los números introducidos deben ser mayores a cero\n");
//    usage('p');
//		exit(EX_USAGE);
//  }
//
//  getNumbersFromFile(fileIN, numbers, numEnteros);
//  setNumbersInFile(fileOUT, numbers, numEnteros);
//
////  int n;
////
////  for ( n = 0; n < numEnteros; n += 1 ) {
////    printf ( "%d\n", numbers[n] );
////  }
//
//}				/* ----------  end of function main  ---------- */

int main(int argc, char* argv[]) {
    if (argc < 2)
        return 1; /* TODO: better error handling */

    FILE* f = fopen(argv[1], "rb");

    /* TODO: check f is not NULL */

    /* Read one byte */    
    int first = fgetc(f);

    if (first != EOF)
        printf("first byte = %x\n", (unsigned)first);

    /* TODO else read failed, empty file?? */

    fclose(f);

    return 0;
}
