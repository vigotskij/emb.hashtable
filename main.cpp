#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
#include <iostream>
#include <stdlib>

typedef unsigned int uint ;

int main( int argv , char* argc[] ) {
	IHash< uint, char* >* hash = factoryHash< uint, char* >() ;
	delete hash ;

	hash->append( "hola" ) ;
    hash->append( "chau" ) ;
	std::cout << hash->extract( "hola" ) << std::endl ;

	system( "pause" ) ;
	return 17 ;
}
