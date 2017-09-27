#ifndef HASH_H
	#include "hash.h"
#endif

template <class Key, class ItemType, typename Key HashFunction( ItemType )>
Hash<Key, ItemType, HashFunction>::Hash( void ){
}

template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
Hash<Key, ItemType, HashFunction >::~Hash( void ){
	;
}

template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
void Hash< Key , ItemType , HashFunction >::append( ItemType value ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
ItemType Hash< Key , ItemType , HashFunction >::extract( const ItemType value ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
ItemType Hash< Key , ItemType , HashFunction >::extract( const Key key , Pos position ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
ItemType Hash< Key , ItemType , HashFunction >::extractFirst( const Key key ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
ItemType Hash< Key , ItemType , HashFunction >::extractLast( const Key key ) {
	;
}

//
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
size Hash< Key , ItemType , HashFunction >::sizeOfList( const Key key ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
size Hash< Key , ItemType , HashFunction >::sizeOfTable( void ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
size Hash< Key , ItemType , HashFunction >::Keys( void ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
bool Hash< Key , ItemType , HashFunction >::isEmpty( void ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
bool Hash< Key , ItemType , HashFunction >::isEmpty( const Key key ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
bool Hash< Key , ItemType , HashFunction >::isFull( void ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
size Hash< Key , ItemType , HashFunction >::density( void ) {
	;
}
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
bool Hash< Key , ItemType , HashFunction >::contained( ItemType value ) {
	;
}

//
template< class Key , class ItemType , typename Key HashFunction( ItemType ) >
void Hash< Key , ItemType , HashFunction >::clear( void ) {
	;
}


template class Hash< int , char* , RSHash > ;
