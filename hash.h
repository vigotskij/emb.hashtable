#ifndef HASH_H
#define HASH_H

#ifndef IHASH_H
	#include "ihash.h"
#endif
#ifndef ILIST_H
	#include "./deps/dolist.h"
	#include "./deps/dolist.temp.spec.h"
#endif
#ifndef GHF_H
	#include "GeneralHashFunctions.h"
#endif

typedef unsigned int uint ;

template <	class Key = uint ,
			class ItemType = char* ,
			class Key HashFunction( const ItemType ) = RSHashCh >
class Hash: public IHash< Key, ItemType, HashFunction > {
	private:
		enum{ DEFAULT_CAPACITY = 256 };

		struct KeyNode {
			Key keyValue ;
			IList<ItemType> *keyptr ;

			KeyNode( void ) {
				keyValue = NULL ;
				keyptr = nullptr ;
			}
			~KeyNode( void ) {
				if( keyptr ) delete keyptr ;
			}
			private:
				KeyNode ( const KeyNode &keyNode ) ;
				KeyNode& operator= (const KeyNode &keyNode ) ;
		};

		KeyNode table[ DEFAULT_CAPACITY ] ;

		size keyCount ;
		size itemCount ;

		//helpers
		size findKey( Key key ) ;
		bool addKey( Key key ) ;
		bool addValueToKey( ItemType value , Key key ) ;

	public:
		Hash( void ) ;
		~Hash( void ) ;

		// adding and extracting functions
		virtual void append( ItemType value ) ;
		virtual ItemType extract( ItemType value ) ;
		virtual ItemType extract( Key key , Pos position ) ;
		virtual ItemType extractFirst( Key key ) ;
		virtual ItemType extractLast( Key key ) ;
		// info and managing space functions
		virtual size sizeOf( Key key ) ;
		virtual size sizeOfTable( void ) ;
		virtual size keysCount( void ) ;
		virtual bool isEmpty( void ) ;
		virtual bool isEmpty( Key key ) ;
		virtual bool isFull( void ) ;
		virtual size_f density( void ) ;
		virtual bool contained( ItemType value ) ;
		virtual bool contained( Key key ) ;
		virtual Key* dumpKeys( void ) ;
		// virtual void tempDumpKeys( void ) ;

		virtual void clear( void ) ;
};

//
// FUNCTIONS DEFINITION
//

//
// PRIVATE
//
template <class Key, class ItemType, class Key HashFunction( const ItemType) >
size Hash< Key, ItemType , HashFunction >::findKey( Key key ){
	size tr = 0 ;
	for( ; tr < DEFAULT_CAPACITY && table[ tr ].keyValue != key ; tr++ ) ;
	return tr ;
}
template <class Key, class ItemType, class Key HashFunction( const ItemType) >
bool Hash< Key, ItemType , HashFunction >::addKey( Key key ) {
	bool tr = false ;
	if( !isFull() ) {
		table[ keyCount ].keyValue = key ;
		table[ keyCount ].keyptr = factoryList<ItemType>() ;
		tr = true ;
	}
	return tr ;
}
template <class Key, class ItemType, class Key HashFunction( const ItemType) >
bool Hash< Key, ItemType , HashFunction >::addValueToKey( ItemType value, Key key ){
	bool tr = false ;
	if ( contained( key ) ) {
		size idx = findKey( key ) ;
		table[ idx ].keyptr->insert( value ) ;
		tr = true ;
	}
	return tr ;
}

//
// PUBLIC
//
template <class Key, class ItemType, class Key HashFunction( const ItemType) >
Hash<Key, ItemType , HashFunction >::Hash( void ){
	keyCount = 0 ;
	itemCount = 0 ;
}

template< class Key , class ItemType, class Key HashFunction( const ItemType) >
Hash<Key, ItemType , HashFunction >::~Hash( void ){
	clear() ;
}

template< class Key , class ItemType, class Key HashFunction( const ItemType) >
void Hash< Key , ItemType , HashFunction >::append( ItemType value ) {
	Key key = HashFunction( value ) ;
	if ( !contained( key ) ) {
		addKey( key ) ;
		addValueToKey( value, key ) ;
		keyCount++ ;
		itemCount++ ;
	} else {
		addValueToKey( value, key ) ;
		itemCount++ ;
	}
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
ItemType Hash< Key , ItemType , HashFunction >::extract( ItemType value ) {
	ItemType tr = NULL ;
	Key key = HashFunction( value ) ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractByValue( value ) ;
	}
	return tr ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
ItemType Hash< Key , ItemType , HashFunction >::extract( Key key , Pos position ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractByIndex( position ) ;
	}
	return tr ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
ItemType Hash< Key , ItemType , HashFunction >::extractFirst( Key key ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractFirst() ;
	}
	return tr ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
ItemType Hash< Key , ItemType , HashFunction >::extractLast( Key key ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->extractLast() ;
	}
	return tr ;
}

//
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
size Hash< Key , ItemType , HashFunction >::sizeOf( Key key ) {
	size tr = 0 ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->listSize() ;
	}
	return tr ;

}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
size Hash< Key , ItemType , HashFunction >::sizeOfTable( void ) {
	return itemCount ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
size Hash< Key , ItemType , HashFunction >::keysCount( void ) {
	return keyCount ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
bool Hash< Key , ItemType , HashFunction >::isEmpty( void ) {
	return keyCount == 0 ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
bool Hash< Key , ItemType , HashFunction >::isEmpty( Key key ) {
	bool tr = false ;
	if( contained( key ) ) {
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->isEmpty() ;
	}
	return tr ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
bool Hash< Key , ItemType , HashFunction >::isFull( void ) {
	return keyCount == DEFAULT_CAPACITY ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
size_f Hash< Key , ItemType , HashFunction >::density( void ) {
	size_f tr = 0 ;
	if( itemCount != 0 && keyCount != 0 ) tr = itemCount / keyCount ;
	return tr ;
}
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
bool Hash< Key , ItemType , HashFunction >::contained( ItemType value ) {
	bool tr = false ;
	Key key = HashFunction( value ) ;
	if( contained( key ) ){
		size idx = findKey( key ) ;
		tr = table[ idx ].keyptr->contained( value ) ;
	}
	return tr ;
}
template <class Key , class ItemType, class Key HashFunction( const ItemType) >
bool Hash<Key , ItemType , HashFunction >::contained( Key key ) {
	size idx = 0 ;
	for (; idx < keyCount && table[ idx ].keyValue != key ; idx++ );
	return ( table[ idx ].keyValue == key ) ;
}
template <class Key, class ItemType, class Key HashFunction( const ItemType)>
Key* Hash<Key, ItemType , HashFunction >::dumpKeys( void ){
	Key *keys ;
	for( int idx = 0 ; table[ idx ].keyptr != nullptr ; idx++ ) {
		keys[ idx ] = table[ idx ].keyValue ;
	}
	return keys ;
}
template <class Key, class ItemType, class Key HashFunction( const ItemType)>
void Hash<Key, ItemType , HashFunction >::tempDumpKeys( void ){
	for( int idx = 0 ; idx < keyCount ; idx++ ) {
		std::cout << table[ idx ].keyValue << std::endl ;
	}
}

//
template< class Key , class ItemType, class Key HashFunction( const ItemType) >
void Hash< Key , ItemType , HashFunction >::clear( void ) {
	size temp = keyCount ;
	for( size idx = 0 ; idx < temp ; idx ++ ) {
		keyCount-- ;
		table[ idx ].keyValue = NULL ;
		table[ idx ].keyptr->emptyList() ;
		delete table[idx].keyptr ;
	}
}

//
// FACTORY
//
template <class Key , class ItemType, class Key HashFunction( const ItemType) >
IHash< Key , ItemType , HashFunction >* factoryHash( void ) {
	return new Hash< Key , ItemType , HashFunction > ;
}


#endif // HASH_H
