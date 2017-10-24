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

	std::cout << hash->remove( "hola" ) << std::endl ;

	system( "pause" ) ; // only line stdlib dependent ...

	return 17 ;
}
