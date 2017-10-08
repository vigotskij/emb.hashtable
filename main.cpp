#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
#include <iostream>
#include <stdlib>  //  for 'system( "pause" )' only ...

typedef unsigned int uint ;

int main( int argv , char* argc[] ) {
	IHash<>* hash = factoryHash<>() ;
	delete hash ;

	hash->append( "hola" ) ;
	hash->append( "chau" ) ;
	hash->append( "gablgabl" ) ;
	std::cout << hash->extract( "hola" ) << std::endl ;
	// hash->tempDumpKeys() ;

	system( "pause" ) ; // only line stdlib dependent ...
	return 17 ;
}
