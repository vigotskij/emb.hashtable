#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
#include <iostream>
#include <stdlib>  //  for 'system( "pause" )' only ...

typedef unsigned int uint ;

int main( int argv , char* argc[] ) {
<<<<<<< HEAD
	IHash<uint,char*>* hash = factoryHash<uint,char*>() ;
=======
	IHash<uint,char*,RSHashCh>* hash = factoryHash<uint,char*,RSHashCh>() ;
<<<<<<< HEAD
=======
	delete hash ;
>>>>>>> ae237e9c4d47da4d8bb49285757bc418163a13bd
>>>>>>> a71add0764c50ccae292fadb15a953dc7937c051

	hash->append( "hola" ) ;
	hash->append( "chau" ) ;
	hash->append( "gablgabl" ) ;
	std::cout << hash->extract( "hola" ) << std::endl ;
	// hash->tempDumpKeys() ;

	system( "pause" ) ; // only line stdlib dependent ...

	delete hash ;
<<<<<<< HEAD

=======
>>>>>>> a71add0764c50ccae292fadb15a953dc7937c051
	return 17 ;
}
