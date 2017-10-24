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

template < class Key, class ItemType >
class Hash: public IHash< Key, ItemType > {
	private:
		enum{ DEFAULT_CAPACITY = 256 };

		struct KeyNode {
			Key keyValue ;
			IList<ItemType> *keyptr ;

			KeyNode( void ) {
				keyValue = DEFAULT_CAPACITY ;
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
		bool addKey( Key key ) ;
		bool addValueToKey( ItemType value , Key key ) ;

	public:
		Hash( void ) ;
		~Hash( void ) ;

		// adding and extracting functions
		virtual void append( ItemType value ) ;
		virtual ItemType remove( ItemType value ) ;
		virtual ItemType remove( Key key , Pos position ) ;
		virtual ItemType removeFirst( Key key ) ;
		virtual ItemType removeLast( Key key ) ;
		// info and managing space functions
		virtual size sizeOf( Key key ) ;
		virtual size sizeOfTable( void ) ;
		virtual size keysCount( void ) ;
		virtual bool isEmpty( void ) ;
		virtual bool isEmpty( Key key ) ;
		virtual size_f density( void ) ;
		virtual bool contained( ItemType value ) ;
		virtual bool contained( Key key ) ;

		virtual void clear( void ) ;
};

//
// FUNCTIONS DEFINITION
//

//
// PRIVATE
//
template<class Key, class ItemType >
bool Hash< Key, ItemType >::addKey( Key key ) {
	table[ key ].keyValue = key ;
	table[ key ].keyptr = factoryList<ItemType>() ;
    return true ;
}
template <class Key, class ItemType >
bool Hash< Key, ItemType >::addValueToKey( ItemType value, Key key ){
	bool tr = false ;
	if ( contained( key ) ) {
		table[ key ].keyptr->insert( value ) ;
		tr = true ;
	}
	return tr ;
}

//
// PUBLIC
//
template <class Key, class ItemType >
Hash<Key, ItemType >::Hash( void ){
	keyCount = 0 ;
	itemCount = 0 ;
}

template< class Key , class ItemType >
Hash<Key, ItemType >::~Hash( void ){
	clear() ;
}

template< class Key , class ItemType >
void Hash< Key , ItemType >::append( ItemType value ) {
	Key key = (HashFunction( value ))% DEFAULT_CAPACITY ;
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
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::remove( ItemType value ) {
	ItemType tr = NULL ;
	Key key = ( HashFunction( value ) ) % DEFAULT_CAPACITY ;
	if( contained( key ) ) {
		tr = table[ key ].keyptr->remove( value ) ;
	}
	return tr ;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::remove( Key key , Pos position ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		tr = table[ key ].keyptr->remove( position ) ;
	}
	return tr ;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::removeFirst( Key key ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		tr = table[ key ].keyptr->removeFirst() ;
	}
	return tr ;
}
template< class Key , class ItemType >
ItemType Hash< Key , ItemType >::removeLast( Key key ) {
	ItemType tr = NULL ;
	if( contained( key ) ) {
		tr = table[ key ].keyptr->removeLast() ;
	}
	return tr ;
}

//
template< class Key , class ItemType >
size Hash< Key , ItemType >::sizeOf( Key key ) {
	size tr = 0 ;
	if( contained( key ) ) {
		tr = table[ key ].keyptr->listSize() ;
	}
	return tr ;

}
template< class Key , class ItemType >
size Hash< Key , ItemType >::sizeOfTable( void ) {
	return itemCount ;
}
template< class Key , class ItemType >
size Hash< Key , ItemType >::keysCount( void ) {
	return keyCount ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isEmpty( void ) {
	return keyCount == 0 ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::isEmpty( Key key ) {
	bool tr = false ;
	if( contained( key ) ) {
		tr = table[ key ].keyptr->isEmpty() ;
	}
	return tr ;
}
template< class Key , class ItemType >
size_f Hash< Key , ItemType >::density( void ) {
	size_f tr = 0 ;
	if( itemCount != 0 && keyCount != 0 ) tr = itemCount / keyCount ;
	return tr ;
}
template< class Key , class ItemType >
bool Hash< Key , ItemType >::contained( ItemType value ) {
	bool tr = false ;
	Key key = ( HashFunction( value ) ) % DEFAULT_CAPACITY ;
	if( contained( key ) ){
		tr = table[ key ].keyptr->contained( value ) ;
	}
	return tr ;
}
template <class Key , class ItemType >
bool Hash<Key , ItemType >::contained( Key key ) {
	return table[ key ].keyValue == key ;
}
//
//
//
template< class Key , class ItemType >
void Hash< Key , ItemType >::clear( void ) {
	size temp = keyCount ;
	for( size idx = 0 ; idx < temp ; idx ++ ) {
		keyCount-- ;
		table[ idx ].keyValue = DEFAULT_CAPACITY ;
		table[ idx ].keyptr->emptyList() ;
		delete table[idx].keyptr ;
	}
}
//
// FACTORY
//
template <class Key , class ItemType >
IHash< Key , ItemType >* factoryHash( void ) {
	return new Hash< Key , ItemType > ;
}


#endif // HASH_H
