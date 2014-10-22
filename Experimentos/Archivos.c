
/*El siguiente ejemplo ilustra el uso de las funciones fseek, fread y fwrite,
a fin de que puedan utilizarlas correctamente en el proyecto. Se quiere que
los inodos sean escritos a las particiones utilizando estas funciones.
*/

/* Autor: Mariela Curiel
  Contenido: Programa que ilustra el uso de las funciones fwrite, fread
  y fseek para escribir y leer datos de un arreglo en la memoria
  en un archivo.
*/


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>
//#include "buffer.h"

void  imprimir(int* array, int cuantos)
{
  int i;

  for(i=0; i < cuantos; i++)
    printf("%d\n",  array[i]);

}

  void
writeFile (char* filename, int* array, int numElems)
{
  FILE *fp;

  if ((fp = fopen(filename, "w")) == NULL)
    perror("fopen:");

  if (fwrite(array, sizeof(int), numElems, fp) == 0) {
    perror("fwrite:");
    exit(0);
  }
  fclose(fp);
}		/* -----  end of function writeFile  ----- */

  void
readFile (char* filename, int* array, int numElems )
{
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    perror("**fopen:");
    exit(0);
  }
  if (fread(array, sizeof(int), numElems, fp) == 0) {
    perror("fread:");
    exit(0);
  }
  printf("\nDespues de escribir el archivo\n");
  imprimir(array,15);
  fclose(fp);
}		/* -----  end of function readFile  ----- */

  void
readChunk (char* filename, int* array, int numElems )
{
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL)
    perror("fopen:");
  printf("\nDespues de las Modificaciones\n");

  if(fseek(fp, sizeof(int)*11,SEEK_SET)!=0)
  {
    perror("fseek");
    exit(0);
  }

  if (fread(array, sizeof(int),4, fp) == 0) {
    perror("fread:");
    exit(0);
  }
  fclose(fp);
  imprimir(array, 4);
}		/* -----  end of function readChunk  ----- */

  int
main(int argc, char* argv[]) {

  int numbersArray[15] = { 25 ,40 ,22 ,30 ,35 ,40 ,18 ,38 ,26 ,27 ,24 ,29 ,31 ,33 ,34 };

  char* fileIN = argv[1];

  writeFile(fileIN, numbersArray, 15);
  readFile(fileIN, numbersArray, 15);
  readChunk(fileIN,numbersArray, 15);

  return 0;
}

