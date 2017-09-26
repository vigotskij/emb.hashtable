#ifndef IHASH_H
#define IHASH_H

typedef unsigned long Pos ;
typedef unsigned long size_t ;

template <class Key , class ItemType >
class IHash {
	public:
		// adding and extracting functions
		virtual void append( const ItemType value ) = 0 ;
		virtual ItemType extract( const ItemType value ) = 0 ;
		virtual ItemType extract( const Key key , const Pos position ) = 0 ;
		virtual ItemType extractFirst( const Key key ) = 0 ;
		virtual ItemType extractLast( const Key key ) = 0 ;
		// info and managing space functions
		virtual size_t sizeOfList( const Key key ) = 0 ;
		virtual size_t sizeOfList( void ) = 0 ;
		virtual size_t sizeOfTable( void ) = 0 ;

		virtual void clear( void ) = 0 ;
};

#endif // IHASH_H

/*
procedure ChangeTableSize(); virtual;
Change the table size of the hash table.
  procedure Clear; virtual;
Clear the hash table.
  procedure Delete(); virtual;
Delete a key from the hash list.
  function Find();
Search for an item with a certain key value.
  function IsEmpty;
Check if the hash table is empty.
  property HashFunction: THashFunction; [rw]
Hash function currently in use
  property Count: LongWord; [r]
Number of items in the hash table.
  property HashTableSize: LongWord; [rw]
Size of the hash table
  property HashTable: TFPObjectList; [r]
Hash table instance
  property VoidSlots: LongWord; [r]
Number of empty slots in the hash table.
  property LoadFactor: Double; [r]
Fraction of count versus size
  property AVGChainLen: Double; [r]
Average chain length
  property MaxChainLength: LongWord; [r]
Maximum chain length
  property NumberOfCollisions: LongWord; [r]
Number of extra items
  property Density: LongWord; [r]
Number of filled slots
*/
