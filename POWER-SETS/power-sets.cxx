#include <iostream>
using std::cout;
using std::endl;

#include <set>

//------------------------------------------------------------------------------

//  A simple ouput routine for sets.
template <class T>
void display( const std::set<T>& mySet )
{
	cout << "{";
	// for( auto e : mySet ) ???
	// for_each( set.begin() , set.end() , myFCN / myOBJ ) ???
	for( typename std::set<T>::iterator it = mySet.begin() ; it != mySet.end() ; ++it ) {
		cout << *it << " ";
	}
	cout << "}" << endl;
}

//------------------------------------------------------------------------------

/*
//  An output routine for sets of sets (to display power sets).
template <class T> void display (set <set<T> > s) {
   set <set <T> >::iterator it;
   cout << "{";
   for (it = s.begin ( ); it != s.end ( ); it++) {
      //  Indent each component
      cout << "    ";
      display (*it);
   }
   cout << "}";
   cout << "\n";
}
*/

/*
//  Standard set union: note that insert is a noop if the element is
//  already in the set.
template <class T> set <T> operator+(set <T> s1, set <T> s2) {
   set <T> result = s1;
   set <T>::iterator it;
   for (it = s2.begin ( ); it != s2.end (); it++) {
      result.insert (*it);
   }
   return result;
}
*/

//------------------------------------------------------------------------------

/*
//  the powerset function: building the set of subsets of a set.
//  The algorithm is recursive: let S be the set in question, and P the
//  power set of S.
//  if S is {}, P is {{}} : the set whose only element   is the empty set.

//  Otherwise for each element e in S, compute the power set of
//  of S - {e}. Let this be P1.
//  a)  Add all the elements of P1 to P.
//  b) Insert e  into each element of P1, and insert each resulting set
//  into P as well.

template <class T> set <set <T> > powerset (set <T> s) {
   set <set <T> > result;
   set <T> nullset; //  the default constructor builds a set with no elements

   if (s.size( ) == 0) {
      result.insert (nullset);
      return result;
   }

   else {
      set <T>::iterator it;
      for (it = s.begin(); it != s.end(); it++) {
         T elem = *it;

         //  copy the original set, and delete one element from it.
         set <T> s1 (s);
         s1.erase (elem);

         //  compute the power set of this smaller set.
         set <set <T> > p1 = powerset (s1);
         result = result + p1;

         //  add the deleted element to each member of this power set,
         //  and insert each new set into the desired result.
         set <set <T> >::iterator iter;
         for (iter = p1.begin(); iter != p1.end(); iter++) {
            set <T>  next = *iter;
            next.insert (elem);
            result.insert (next);
         };
      };
      return result;
   }
}
*/

int main( int argc , char *argv[] ) {

   std::set<int> s1;
   for (int J = 0; J < 10; J++) {
      s1.insert (J);
   }
   std::set<int> s3;
   for (int J = 0; J < 10; J++) {
      s3.insert (J*J*J);
   }
   display(s1);
   display(s3);
   //  test set union.
   // display (s1+s3);

   //  build a set cardinality 4. Its power set has 2^4 = 16 elements.
   // set <int> s4;
   // for (int J = 0; J < 4; J++) {
      // s4.insert (J);
   // }
   // cout << "original set  ";
   // display (s4);
   // cout << "power set\n";
   // display (powerset (s4));

}
