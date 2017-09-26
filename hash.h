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

template <class Key , class ItemType >
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

		IList<KeyNode> *keyList ;
		IList<ItemType> *itemsList[ DEFAULT_CAPACITY ] ;

	public:
		Hash( void ) ;
		~Hash( void ) ;

		virtual void release( void ) ;
};

template <class Key , class ItemType>
IHash< Key , ItemType >* factoryHash( void ) {
    return new Hash< Key , ItemType > ;
}
#endif // HASH_H
