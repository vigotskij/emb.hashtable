#ifndef HASH_H
	#include "hash.h"
#endif

template< class Key , class ItemType >
Hash<Key, ItemType>::Hash( void ){
	keyList = factoryList<Key>() ;
   	for(int idx = 0 ; idx < DEFAULT_CAPACITY ; idx++ ) {
		itemsList[ idx ] = factoryList<ItemType>() ;
	}
}
template< class Key , class ItemType >
Hash<Key, ItemType>::~Hash( void ){
}

template< class Key , class ItemType >
void Hash< Key , ItemType >::release( void ) {
	;
}

template class Hash< int , char* > ;
