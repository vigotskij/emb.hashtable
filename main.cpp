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
	hash->append( "gablgabl" ) ;
	//hash->append( "chau" ) ;
   //	hash->append( "gablgl" ) ;
   //	hash->append( "gablgab" ) ;

	uint *keys = hash->dumpKeys() ;

	for( unsigned int idx = 0 ; idx < hash->keysCount() ; idx++ ){
		std::cout << keys[idx] << std::endl ;
	}
	system("pause") ;

	std::cout << hash->extract( "hola" ) << std::endl ;
	hash->tempDumpKeys() ;

	system( "pause" ) ; // only line stdlib dependent ...

   //	delete keys ;

	return 17 ;
}
