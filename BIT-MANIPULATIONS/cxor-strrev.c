/*==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8
 *
 *   COMPILE:
 *   /opt/local/bin/gcc-mp-4.7 \
 *      -Wall -Wextra -Wno-unused-parameter \
 *      -O3 -o cxor-strrev cxor-strrev.c
 *
 *   [ STEP 03 ] TEST:
 *   /cxor-strrev fubar baz 'bears eat honey'
 *
 *   <<< PROGRAM ["./cxor-strrev"] --- BEGIN
 *   --- >>> ["bears eat honey"] reversed in-place becomes: ["yenoh tae sraeb"]
 *   --- >>> ["baz"] reversed in-place becomes: ["zab"]
 *   --- >>> ["fubar"] reversed in-place becomes: ["rabuf"]
 *   --- >>> ["./cxor-strrev"] reversed in-place becomes: ["verrts-roxc/."]
 *   <<< PROGRAM ["verrts-roxc/."] --- DONE
 *
 *==+====1====+====2====+====3====+====4====+====5====+====6====+====7====+====8
*/

/*----------------------------------------------------------------------------*/
/* INCLUDES, DEFINES, STATIC VARIABLES, ETC                                   */
/*----------------------------------------------------------------------------*/

#include<stdio.h>

void usage( char *prog , char *err ) {
  printf( "*** ERROR[ %s ]: %s\n\n" , prog , err );
}

/*----------------------------------------------------------------------------*/

/* STRREV METHOD :: OLD SCHOOL POINTERS AND HORRIBLE XOR - WORKS THO !!! */

void strrev_ptr_xor( char *str ) {
  char *end = str;
  /* find the end of the char* string */
  while( end && *end ) ++end;
  for( --end ; str < end ; ++str , --end ) {
    *str = *str ^ *end;
    *end = *str ^ *end;
    *str = *str ^ *end;
  }
}

/*----------------------------------------------------------------------------*/

int main( int argc , char **argv ) {

  printf( "\n<<< PROGRAM [\"%s\"] --- BEGIN\n" , argv[0] );
  if( argc <= 1 ) {
    usage( argv[0] , "argc must be GT 1" );
    return 1;
  }

  /* LOOP THROUGH ALL ARGC-ARGV COMBINATIONS */
  /* LOOP WHILE: argc > 0 ??? */
  do {
        printf( "--- >>> [\"%s\"] reversed in-place becomes: " , argv[ argc-1 ] );
           strrev_ptr_xor( argv[argc-1] );
           printf( "[\"%s\"]\n" , argv[argc-1] );
  } while( --argc );

  /* ALL DONE */
  printf( "<<< PROGRAM [\"%s\"] --- DONE\n\n" , argv[0] );
  return 0;

}

/*----------------------------------------------------------------------------*/
