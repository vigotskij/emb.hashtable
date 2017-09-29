#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
typedef unsigned int uint ;

int main( int argv , char* argc[] ) {
	IHash< uint, char* >* hash = factoryHash< uint, char* >() ;
	delete hash ;

	IHash< uint, char* >* hash2 = new Hash<uint, char* >();
	delete hash2 ;
	return 17 ;
}
