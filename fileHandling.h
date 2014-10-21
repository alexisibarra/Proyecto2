/*
 * =====================================================================================
 *
 *       Filename:  fileHandling.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/10/14 12:06:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


  void
writeToPlainFile ( char* fileName, int* array, int numElems )
{
  int index;
  FILE *fp;

  if ((fp = fopen(fileName, "w")) == NULL)
    perror("fopen:");
  
  for ( index = 0; index < numElems; index += 1 ) {
    fprintf( fp, "%d\n", array[index]);
  }

  fclose(fp);
}		/* -----  end of function writeToBinFile  ----- */

  void
writeToBinFile ( char* fileName, int* array, int numElems )
{
  FILE *fp;

  if ((fp = fopen(fileName, "w")) == NULL)
    perror("fopen:");

  if (fwrite(&array, sizeof(int), numElems, fp) == 0) {
    perror("fwrite:");
    exit(0);
  }
  fclose(fp);
}		/* -----  end of function writeToBinFile  ----- */

  void
readFromBinFile ( char* fileName, int* array, int numElems )
{
  FILE *fp;

  if ((fp = fopen(fileName, "r")) == NULL)
    perror("fopen:");

  if (fread(&array, sizeof(int), numElems, fp) == 0) {
    perror("fread:");
    exit(0);
  }
  fclose(fp);
}		/* -----  end of function readFromBinFile  ----- */

