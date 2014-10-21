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

  if ((fp = fopen(fileName, "wb")) == NULL)
    perror("fopen:");

  if (fwrite(&array, sizeof(int), numElems+2, fp) == 0) {
    perror("fwrite:");
    exit(0);
  }
  fclose(fp);
}		/* -----  end of function writeToBinFile  ----- */

  void
readFromBinFile ( char* fileName, int* array, int numElems )
{
  FILE *fp;

  if ((fp = fopen(fileName, "rb")) == NULL)
    perror("fopen:");

  if (fread(&array, sizeof(int), numElems+2, fp) == 0) {
    perror("fread:");
    exit(0);
  }
  fprintf(fp, "%c", '\0');
  fclose(fp);
}		/* -----  end of function readFromBinFile  ----- */

  void
readChunkFromBinFile  
  ( char* fileName, int numElemsFile, int* array, int initPos, int numElems )
{
  FILE *fp;
  printf ( "\n" );
  if ( ( initPos + numElems ) >= numElemsFile ){
    fprintf(stderr, "Imposible obtener la cantidad de elementos\n");
    exit(-1);
  }

  if ((fp = fopen(fileName, "rb")) == NULL) {
    perror("fopen:");
    exit(0);
  }

  if(fseek(fp, sizeof(int)*(initPos+4),SEEK_SET)!=0)
  {
    perror("fseek");
    exit(0);
  }

  if (fread(array, sizeof(int), numElems, fp) == 0) {
    perror("fwe");
    exit(-1);
  }

  printf ( "array[0] %d\n", array[0] );
  printf ( "array[1] %d\n", array[1] );
  printf ( "array[2] %d\n", array[2] );
  printf ( "array[3] %d\n", array[3] );

  fclose(fp);

}		/* -----  end of function readChunkFromBinFile  ----- */
