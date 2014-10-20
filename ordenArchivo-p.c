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
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

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
 *         Name:  getNumbersFromFile
 *  Description:  
 * =====================================================================================
 */
  int *
getNumbersFromFile ( char* path )
{
  int * numbers;
  FILE* fp = NULL;
  int i = 0;

  if ((fp = fopen(path, "r")) == 0){
    perror("El archivo no existe; fopen");

    exit(EX_USAGE);
  }

  fscanf (fp, "%d", &i);    
  while (!feof (fp))
    {  
      printf ("%d ", i);
      fscanf (fp, "%d", &i);      
    }
  fclose (fp); 

  return numbers;
}		/* -----  end of function getNumbersFromFile  ----- */

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
  int fileIN = atoi(argv[3]);
  int fileOUT= atoi(argv[4]);

  if ( numEnteros < 0 || numNiveles < 0) {
    printf ( "%d\n", numEnteros );
		puts("Los números introducidos deben ser mayores a cero");
    usage('p');
		exit(EX_USAGE);
  }
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

