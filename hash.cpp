#ifndef HASH_H
	#include "hash.h"
#endif
typedef unsigned int uint ;

template <class Key, class ItemType >
Hash<Key, ItemType>::Hash( void ){
}

template< class Key , class ItemType >
Hash<Key, ItemType>::~Hash( void ){
	;
}

template< class Key , class ItemType >
void Hash< Key , ItemType >::append( const ItemType value ) {
	;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extract( const ItemType value ) {
	;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extract( const Key key , Pos position ) {
	;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extractFirst( const Key key ) {
	;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::extractLast( const Key key ) {
	;
}

//
template< class Key , class ItemType >
size Hash< Key , ItemType >::sizeOf( const Key key ) {
	;
}
template< class Key , class ItemType >
size Hash< Key , ItemType >::sizeOfTable( void ) {
	;
}
template< class Key , class ItemType >
size Hash< Key , ItemType >::Keys( void ) {
	;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isEmpty( void ) {
	;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isEmpty( const Key key ) {
	;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isFull( void ) {
	;
}
template< class Key , class ItemType >
size Hash< Key , ItemType >::density( void ) {
	;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::contained( ItemType value ) {
	;
}

//
template< class Key , class ItemType >
void Hash< Key , ItemType >::clear( void ) {
	;
}


template class Hash< uint , std::string > ;
