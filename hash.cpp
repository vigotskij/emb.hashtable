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
	return false ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isFull( void ) {
	return false ;
}
template< class Key , class ItemType >
size_f Hash< Key , ItemType >::density( void ) {
	size_f tr = 0 ;
	if( itemCount != 0 && keyCount != 0 ) tr = itemCount / keyCount ;
	return tr ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::contained( ItemType value ) {
	;
}
template <class Key , class ItemType >
bool Hash<Key , ItemType >::contained( Key key ) {
	;
}

//
template< class Key , class ItemType >
void Hash< Key , ItemType >::clear( void ) {
	;
}


template class Hash< uint , std::string > ;
