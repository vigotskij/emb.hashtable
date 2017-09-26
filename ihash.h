#ifndef IHASH_H
#define IHASH_H

template <class Key , class ItemType >
class IHash {
	public:
		virtual void release( void ) = 0 ;
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
