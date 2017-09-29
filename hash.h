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

template <class Key, class ItemType>
class Hash: public IHash< Key, ItemType > {
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
		virtual void append( const ItemType value ) ;
		virtual ItemType extract( const ItemType value ) ;
		virtual ItemType extract( const Key key , const Pos position ) ;
		virtual ItemType extractFirst( const Key key ) ;
		virtual ItemType extractLast( const Key key ) ;
		// info and managing space functions
		virtual size sizeOf( const Key key ) ;
		virtual size sizeOfTable( void ) ;
		virtual size Keys( void ) ;
		virtual bool isEmpty( void ) ;
		virtual bool isEmpty( const Key key ) ;
		virtual bool isFull( void ) ;
		virtual size_f density( void ) ;
		virtual bool contained( const ItemType value ) ;
        virtual bool contained( const Key key ) ;

		virtual void clear( void ) ;
};

template <class Key , class ItemType >
IHash< Key , ItemType >* factoryHash( void ) {
	return new Hash< Key , ItemType > ;
}
#endif // HASH_H
