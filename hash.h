#ifndef HASH_H
#define HASH_H

#ifndef IHASH_H
	#include "ihash.h"
#endif
#ifndef ILIST_H
	#include "./deps/dolist.h"
#endif
#ifndef GHF_H
	#include "GeneralHashFunctions.h"
#endif

template <class Key, class ItemType, typename Key HashFunction( ItemType ) = RSHash >
class Hash: public IHash< Key, ItemType, HashFunction > {
	private:
		enum{ DEFAULT_CAPACITY = 100 };

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

		Key keys[ DEFAULT_CAPACITY ] ;
		IList<ItemType> *itemsList[ DEFAULT_CAPACITY ] ;

	public:
		Hash( void ) ;
		~Hash( void ) ;

		// adding and extracting functions
		virtual void append( const ItemType value ) ;
		virtual ItemType extract( const ItemType value ) ;
		virtual ItemType extract( const Key key , const Pos position ) ;
		virtual ItemType extractFirst( const Key key ) ;
		virtual ItemType extractLast( const Key key ) ;
		// info and managing space functions
		virtual size sizeOfList( const Key key ) ;
		virtual size sizeOfTable( void ) ;
		virtual size Keys( void ) ;
		virtual bool isEmpty( void ) ;
		virtual bool isEmpty( const Key key ) ;
		virtual bool isFull( void ) ;
		virtual size density( void ) ;
		virtual bool contained( ItemType value ) ;

		virtual void clear( void ) ;
};

template <class Key , class ItemType , typename Key HashFunction( ItemType )>
IHash< Key , ItemType , HashFunction >* factoryHash( void ) {
	return new Hash< Key , ItemType , HashFunction > ;
}
#endif // HASH_H
