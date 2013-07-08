/*----------------------------------------------------------------------------*/

#include<stdlib.h>

#include<stdio.h>

/*----------------------------------------------------------------------------*/

unsigned int NumberOfBitsSet_NAIVE( unsigned int foo ) {
   unsigned int count = 0u;
   while( foo ) {
      count += foo & 1u;
      foo >>= 1;
   }
   return count;
}

/*----------------------------------------------------------------------------*/

unsigned int NumberOfBitsSet_KR( unsigned int foo ) {
   unsigned int count = 0u;
   while( foo ) {
     foo &= (foo - 1u);
     ++count;
   }
   return count;
}

/*----------------------------------------------------------------------------*/

static const unsigned int BitsSet_TABLE_256[ 256 ] =
{
#define B2(n) (n) , (n)+1 , (n)+1 , (n)+2
#define B4(n) B2((n)), B2((n)+1), B2((n)+1), B2((n)+2)
#define B6(n) B4((n)), B4((n)+1), B4((n)+1), B4((n)+2)
B6(0u), B6(1u), B6(1u), B6(2u)
};

unsigned int NumberOfBitsSet_TABLE_256( unsigned int foo ) {
   unsigned int count = BitsSet_TABLE_256[ foo & 0xFF ] +
                        BitsSet_TABLE_256[ (foo >>  8) & 0xFF ] +
                        BitsSet_TABLE_256[ (foo >> 16) & 0xFF ] +
                        BitsSet_TABLE_256[ (foo >> 24) & 0xFF ];
   return count;
}

/*----------------------------------------------------------------------------*/

void print_usage( const char* const progName ) {
  if( DEBUG ) {
    printf("\n");
    printf("<<< PROGRAM: [ \"%s\" ]  ---  *BEGIN*\n" , progName );
    printf("---   COUNT THE NUMBER OF BITS SET in integral data types\n" );
    printf("---   (1)  NumberOfBitsSet_NAIVE( uint ): iterate all LSB & 1u, shifted\n" );
    printf("---   (2)  NumberOfBitsSet_KR( uint ): iterate while: X = X & (X-1)\n" );
    printf("---   (3)  FIRST OF THE PATTERNED LOOKUP TABLES: N, N+1, N+1, N+2\n" );
  }
}

void print_trailer( const char* const progName ) {
  if( DEBUG ) {
    printf("<<< PROGRAM: [ \"%s\" ]  ---  *END*\n" , progName );
    printf("\n");
  }
}

/*----------------------------------------------------------------------------*/

int main( const int argc , const char** const argv ) {

  const char* const progName = argv[0];
  print_usage( progName );

  // for( size_t idx = 0 ; idx < (size_t)argc ; ++idx ) {
    // cout << "    --> argv[" << idx << "]: [\"" << argv[idx] << "\"]" << endl;
  // }

  // unsigned long long numInt = 0ULL;
  // unsigned int numBits = COUNT_NumberOfBitsSet( numInt );
  // unsigned int numBits = 0ULL;
  // unsigned char char_numBits = 0;
  // for( unsigned int num = 0u ; num <= 9u ; ++num ) {
    // numBits = COUNT_NumberOfBitsSet( num );
    // numBits = COUNT_NumberOfBitsSet_KR( num );
    // char_numBits = COUNT_NumberOfBitsSet_TABLE( num );
    // cout << "    --> num[" << num << "]: number of bits set = [ \"" << numBits << "\" , \"" << char_numBits << "\" ]" << endl;
  // }

  print_trailer( progName );
  return EXIT_SUCCESS;

}
