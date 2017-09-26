#ifndef IHASH_H
	#include "hash.h"
#endif

int main( int argv , char* argc[] ) {
	IHash< int , char* > *hash = factoryHash< int , char* >() ;

	delete hash ;

	return 17 ;
}
