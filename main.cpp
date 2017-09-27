#ifndef IHASH_H
	#include "hash.h"
#endif
#include <string>
typedef unsigned int uint ;

int main( int argv , char* argc[] ) {
	IHash< uint, std::string, RSHash>* hash = factoryHash< uint, std::string, RSHash>() ;
	delete hash ;

	IHash< uint, std::string, RSHash>* hash2 = new Hash<uint,std::string,RSHash>();
	delete hash2 ;
	return 17 ;
}
