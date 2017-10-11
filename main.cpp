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
	delete hash ;
>>>>>>> ae237e9c4d47da4d8bb49285757bc418163a13bd

	hash->append( "hola" ) ;
	hash->append( "chau" ) ;
	hash->append( "gablgabl" ) ;
	std::cout << hash->extract( "hola" ) << std::endl ;
	// hash->tempDumpKeys() ;

	system( "pause" ) ; // only line stdlib dependent ...

	delete hash ;
	return 17 ;
}
