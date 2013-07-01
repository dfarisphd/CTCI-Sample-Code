#include<cstdlib>
#include<cassert>

#include<iostream>
using std::cout;
using std::endl;

//==============================================================================

extern "C" {
   unsigned int COUNT_NumberOfBitsSet( unsigned long long fubar ) {
      unsigned int count = 0;
      while( fubar ) {
         count += fubar & 1ULL;
         fubar >>= 1;
      }
      return count;
   }
}

//==============================================================================

extern "C" {
   unsigned int COUNT_NumberOfBitsSet_KR( unsigned long long fubar ) {
      unsigned int count = 0;
      while( fubar ) {
        fubar &= (fubar - 1ULL);
        ++count;
      }
      return count;
   }
}

//==============================================================================

static const unsigned int BitsSet_TABLE_256[ 256 ] =
{
#define B2(n) n, n+1, n+1, n+2
#define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
B6(0), B6(1), B6(1), B6(2)
};

extern "C" {

   unsigned int COUNT_NumberOfBitsSet_TABLE( unsigned int fubar ) {
      unsigned int count = BitsSet_TABLE_256[ fubar & 0xFF ] +
                           BitsSet_TABLE_256[ (fubar >>  8) & 0xFF ] +
                           BitsSet_TABLE_256[ (fubar >> 16) & 0xFF ] +
                           BitsSet_TABLE_256[ (fubar >> 24) & 0xFF ];
      return count;
   }

}

//==============================================================================

int main( const int argc , const char** const argv ) {

  cout << endl;
  cout << "<<< PROGRAM [ \"" << argv[0] << "\" ] -- *BEGIN*" << endl;

  for( size_t idx = 0 ; idx < (size_t)argc ; ++idx ) {
    cout << "    --> argv[" << idx << "]: [\"" << argv[idx] << "\"]" << endl;
  }

  // unsigned long long numInt = 0ULL;
  // unsigned int numBits = COUNT_NumberOfBitsSet( numInt );
  unsigned int numBits = 0ULL;
  unsigned char char_numBits = 0;
  for( unsigned int num = 0u ; num <= 9u ; ++num ) {
    // numBits = COUNT_NumberOfBitsSet( num );
    numBits = COUNT_NumberOfBitsSet_KR( num );
    char_numBits = COUNT_NumberOfBitsSet_TABLE( num );
    cout << "    --> num[" << num << "]: number of bits set = [ \"" << numBits << "\" , \"" << char_numBits << "\" ]" << endl;
  }

  cout << "<<< PROGRAM [ \"" << argv[0] << "\" ] -- *END*" << endl;
  cout << endl;
  return EXIT_SUCCESS;

}
