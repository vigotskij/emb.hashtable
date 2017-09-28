#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
typedef unsigned int uint ;

int main( int argv , char* argc[] ) {
	IHash< uint, std::string >* hash = factoryHash< uint, std::string >() ;
	delete hash ;

	IHash< uint, std::string>* hash2 = new Hash<uint,std::string>();
	delete hash2 ;
	return 17 ;
}
