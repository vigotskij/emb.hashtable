#ifndef IHASH_H
#define IHASH_H

typedef unsigned long Pos ;
typedef unsigned long size ;

template <class Key , class ItemType>
class IHash {
	public:
		// adding and extracting functions
		virtual void append( const ItemType value ) = 0 ;
		virtual ItemType extract( const ItemType value ) = 0 ;
		virtual ItemType extract( const Key key , const Pos position ) = 0 ;
		virtual ItemType extractFirst( const Key key ) = 0 ;
		virtual ItemType extractLast( const Key key ) = 0 ;
		// info and managing space functions
		virtual size sizeOf( const Key key ) = 0 ;
   		virtual size sizeOfTable( void ) = 0 ;
		virtual size Keys( void ) = 0 ;
		virtual bool isEmpty( void ) = 0 ;
		virtual bool isEmpty( const Key key ) = 0 ;
		virtual bool isFull( void ) = 0 ;
		virtual size density( void ) = 0 ;
		virtual bool contained( ItemType value ) = 0 ;

		virtual void clear( void ) = 0 ;
};

#endif // IHASH_H
