#ifndef HASH_H
	#include "hash.h"
#endif
typedef unsigned int uint ;

// PRIVATE
template <class Key, class ItemType >
size Hash< Key, ItemType >::findKey( Key key ){
	size tr = 0 ;
	for( ; tr < DEFAULT_CAPACITY && table[ tr ].keyValue != key ; tr++ ) ;
	return tr ;
}
template <class Key, class ItemType >
bool Hash< Key, ItemType >::addKey( Key key ) {
	bool tr = false ;
	if( !isFull() ) {
		table[ keyCount ].keyValue = key ;
		table[ keyCount ].keyptr = factoryList<ItemType>() ;
		tr = true ;
	}
	return tr ;
}
template <class Key, class ItemType >
bool Hash< Key, ItemType >::addValueToKey( ItemType value, Key key ){
	bool tr = false ;
	if ( contained( key ) ) {
		size idx = findKey( key ) ;
		table[ idx ].keyptr->insert( value ) ;
		tr = true ;
	}
	return tr ;
}

// PUBLIC
template <class Key, class ItemType >
Hash<Key, ItemType>::Hash( void ){
	keyCount = 0 ;
	itemCount = 0 ;
}

template< class Key , class ItemType >
Hash<Key, ItemType>::~Hash( void ){
	clear() ;
}

template< class Key , class ItemType >
void Hash< Key , ItemType >::append( const ItemType value ) {
	Key key = HashFunction( value ) ;
	if ( !contained( key ) ) {
		addKey( key ) ;
		addValueToKey( value, key ) ;
	} else {
		addValueToKey( value, key ) ;
	}
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extract( const ItemType value ) {
	ItemType tr = NULL ;
	Key key = HashFunction( value ) ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractByValue( value ) ;
	}
	return tr ;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extract( const Key key , Pos position ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractByIndex( position ) ;
	}
	return tr ;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extractFirst( const Key key ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractFirst() ;
	}
	return tr ;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extractLast( const Key key ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractLast() ;
	}
	return tr ;
}

//
template< class Key , class ItemType >
size Hash< Key , ItemType >::sizeOf( const Key key ) {
	size tr = 0 ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->listSize() ;
	}
	return tr ;

}
template< class Key , class ItemType >
size Hash< Key , ItemType >::sizeOfTable( void ) {
	return itemCount ;
}
template< class Key , class ItemType >
size Hash< Key , ItemType >::Keys( void ) {
	return keyCount ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isEmpty( void ) {
	return keyCount == 0 ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isEmpty( const Key key ) {
	bool tr = false ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->isEmpty() ;
	}
	return tr ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isFull( void ) {
	return keyCount == DEFAULT_CAPACITY ;
}
template< class Key , class ItemType >
size_f Hash< Key , ItemType >::density( void ) {
	size_f tr = 0 ;
	if( itemCount != 0 && keyCount != 0 ) tr = itemCount / keyCount ;
	return tr ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::contained( const ItemType value ) {
	bool tr = false ;
	Key key = HashFunction( value ) ;
	if( contained( key ) ){
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->contained( value ) ;
	}
	return tr ;
}
template <class Key , class ItemType >
bool Hash<Key , ItemType >::contained( const Key key ) {
	size idx = 0 ;
	for (; idx < DEFAULT_CAPACITY && table[ idx ].keyValue != key ; idx++ );
	return ( table[ idx ].keyValue == key ) ;
}

//
template< class Key , class ItemType >
void Hash< Key , ItemType >::clear( void ) {
	size temp = keyCount ;
	for( size idx = 0 ; idx < temp ; idx ++ ) {
		keyCount-- ;
		table[ idx ].keyValue = NULL ;
		table[ idx ].keyptr->emptyList() ;
		delete table[idx].keyptr ;
	}
}


template class Hash< uint , char* > ;
