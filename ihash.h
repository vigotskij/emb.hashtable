#ifndef IHASH_H
#define IHASH_H

typedef unsigned long Pos ;
typedef unsigned long size ;
typedef float size_f ;

template <	class Key , class ItemType >
class IHash {
	public:
		// adding and extracting functions
		virtual void append( ItemType value ) = 0 ;
		virtual ItemType remove( ItemType value ) = 0 ;
		virtual ItemType remove( Key key , Pos position ) = 0 ;
		virtual ItemType removeFirst( Key key ) = 0 ;
		virtual ItemType removeLast( Key key ) = 0 ;
		// info and managing space functions
		virtual size sizeOf( Key key ) = 0 ;
		virtual size sizeOfTable( void ) = 0 ;
		virtual size keysCount( void ) = 0 ;
		virtual bool isEmpty( void ) = 0 ;
		virtual bool isEmpty( Key key ) = 0 ;
		virtual size_f density( void ) = 0 ;
		virtual bool contained( ItemType value ) = 0 ;
		virtual bool contained( Key key ) = 0 ;

		virtual void clear( void ) = 0 ;
};

#endif // IHASH_H
