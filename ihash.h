#ifndef IHASH_H
#define IHASH_H

typedef unsigned long Pos ;
typedef unsigned long size ;
typedef float size_f ;

template <class Key , class ItemType>
class IHash {
	public:
		// adding and extracting functions
		virtual void append( ItemType value ) = 0 ;
		virtual ItemType extract( ItemType value ) = 0 ;
		virtual ItemType extract( Key key , Pos position ) = 0 ;
		virtual ItemType extractFirst( Key key ) = 0 ;
		virtual ItemType extractLast( Key key ) = 0 ;
		// info and managing space functions
		virtual size sizeOf( Key key ) = 0 ;
   		virtual size sizeOfTable( void ) = 0 ;
		virtual size keysCount( void ) = 0 ;
		virtual bool isEmpty( void ) = 0 ;
		virtual bool isEmpty( Key key ) = 0 ;
		virtual bool isFull( void ) = 0 ;
		virtual size_f density( void ) = 0 ;
		virtual bool contained( ItemType value ) = 0 ;
		virtual bool contained( Key key ) = 0 ;
		virtual Key* dumpKeys( void ) = 0 ;
        // virtual void tempDumpKeys( void ) = 0 ; // only for tests. will die soon enough.

		virtual void clear( void ) = 0 ;
};

#endif // IHASH_H
