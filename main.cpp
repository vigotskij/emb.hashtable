#ifndef IHASH_H
	#include "hash.h"
#endif

int main( int argv , char* argc[] ) {
	IHash< int , char* , RSHash > *hash = factoryHash< int , char* , RSHash >() ;

	delete hash ;

	return 17 ;
}
