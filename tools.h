/*
 * =====================================================================================
 *
 *       Filename:  tools.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/10/14 21:40:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

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

