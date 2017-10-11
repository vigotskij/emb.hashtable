#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
#include <iostream>
#include <stdlib>  //  for 'system( "pause" )' only ...

typedef unsigned int uint ;

int main( int argv , char* argc[] ) {

	IHash<uint,char*> *hash = factoryHash<uint,char*>() ;

	hash->append( "hola" ) ;
	hash->append( "chau" ) ;
	hash->append( "gablgabl" ) ;
	uint *keys = hash->dumpKeys() ;

	for( unsigned int idx = 0 ; keys[ idx ] != nullptr ; idx++ ){
		std::cout << keys[idx] << std::endl ;
	}
	system("pause") ;

	std::cout << hash->extract( "hola" ) << std::endl ;
	hash->tempDumpKeys() ;

	system( "pause" ) ; // only line stdlib dependent ...

    delete keys ;
	delete hash ;

	return 17 ;
}
