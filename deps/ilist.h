 #ifndef ILIST_H
#define ILIST_H
typedef unsigned long Pos ;
typedef unsigned long size ;

template <class ItemType>
class IList{
	public:
		// adding, deleting and replacing functions
		virtual void insert( ItemType value ) = 0 ;
		virtual ItemType remove( ItemType value ) = 0 ;
		virtual ItemType remove( Pos position ) = 0 ;
		virtual ItemType removeFirst( void ) = 0 ;
		virtual ItemType removeLast( void ) = 0 ;
		virtual bool replace( ItemType valueOut, ItemType valueIn ) = 0 ;
		// capacity and info functions
		virtual bool isEmpty( void ) = 0 ;
		virtual size listSize( void ) = 0 ;
		virtual Pos indexOf( ItemType value ) = 0 ;
		virtual bool contained( ItemType value ) = 0 ;
		// manage functions
		virtual void emptyList( void ) = 0 ;
};

#endif
