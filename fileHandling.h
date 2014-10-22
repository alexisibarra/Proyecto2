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
writeToBinFile ( char* filename, int* array, int numElems )
{
  FILE *fp;

  if ((fp = fopen(filename, "w")) == NULL)
    perror("fopen:");

  if (fwrite(array, sizeof(int), numElems, fp) == 0) {
    perror("fwrite:");
    exit(0);
  }
  fclose(fp);
}		/* -----  end of function writeToBinFile  ----- */

  void
readFromBinFile ( char* fileName, int* array, int numElems )
{
  FILE *fp;

  if ((fp = fopen(fileName, "rb")) == NULL){
    perror("**fopen:");
    exit(0);
  }

  if (fread(&array, sizeof(int), numElems, fp) == 0) {
    perror("fread:");
    exit(0);
  }
  fclose(fp);
}		/* -----  end of function readFromBinFile  ----- */

  void
readChunkFromBinFile  
  ( char* fileName, int numElemsFile, int* array, int initPos, int numElems )
{
  FILE *fp;
  printf ( "\n" );
  if ( ( initPos + numElems ) > numElemsFile ){
    fprintf(stderr, "Imposible obtener la cantidad de elementos\n");
    exit(-1);
  }

  if ((fp = fopen(fileName, "r")) == NULL) {
    perror("fopen:");
    exit(0);
  }

  if(fseek(fp, sizeof(int)*initPos,SEEK_SET)!=0)
  {
    perror("fseek");
    exit(0);
  }

  if (fread(array, sizeof(int), numElems, fp) == 0) {
    perror("fwe");
    exit(-1);
  }

  fclose(fp);

}		/* -----  end of function readChunkFromBinFile  ----- */
