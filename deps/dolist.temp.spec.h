//
// TEMPLATE SPECIALIZATIONS
//

#include <string>  // for std::string operators ...

//
// TEMPLATE FOR CHAR *
//
template<>
class DOList<char*>: public IList<char*> {
	private:
		struct Node{
			char *value ;

			Node *next ;
			Node *prev ;

			Node( void ){
				value, next, prev = nullptr ;

			}
			~Node( void ) { } ;

			private:
				Node( const Node &otherNode ) ;
				Node& operator= ( const Node &otherNode ) ;
		} ;

		Node *first , *last ;

		size itemCount ;

		// helpers
		Pos _indexOf_( const char *value ) {
			Pos tr = -1 ;
			if( !isEmpty() ){
				Node *current = first ;
				Pos position = 0 ;
				for( ;
					current != nullptr && *current->value != *value ;
					current = current->next ) {
						position++ ;
				}
			if( current != nullptr && *current->value == *value ) tr = position ;
			}
			return  tr ;
		}
		Node* _findNode_( const char* value ) {
			Node *found = nullptr ;
			if( !isEmpty() ){
				Node *current = first ;
				for( ;
					 current != nullptr && *current->value != *value ;
					 current = current->next ) ;
						found = current ;
			}
			return found ;
		}
		Node* _findNodeByIndex_ ( const Pos position ){
			Pos count = 0 ;
			Node *current = first ;
			Node *found = nullptr ;
			for (;
				current != nullptr ;
				current = current->next ){
				if( position == count ) found = current ;
				count++ ;
			}
			return found ;
		}

		Node* _sortItem_( char *value ) {
			Node *current = nullptr ;
			if( !isEmpty()){
				current = first ;
				for( ;
					 current != nullptr && *current->value < *value ;
					 current = current->next ) ;
			}
			return current ;
		}
		// copy constructor ;
		DOList(const DOList &otherList ) ;
		// operator=
		DOList& operator=( const DOList& otherList ) ;


 public:
	//constr&dest
	DOList( void ){
		first, last = nullptr ;
		itemCount = 0 ;
	}
	~DOList( void ){
		emptyList() ;
		if ( first ) delete first ;
		if ( last ) delete last ;
	}

	// adding, deleting and replacing functions
	void insert( char *value ){
		if( !contained( value ) ) {
			Node *newNode = new Node ;
			newNode->value = value ;

			Node *nextNode = _sortItem_( value ) ;

			if( nextNode != nullptr ) {
				newNode->prev = nextNode->prev ;
				newNode->next = nextNode ;

				nextNode->prev = newNode ;
			} else {
				if( first == nullptr ) {
					first = newNode ;
					last = newNode ;
				} else if ( first == last && first != nullptr ) {
					newNode->prev = first ;
					newNode->next = nullptr ;
					first->next = newNode ;

					last = newNode ;
				} else if ( first != last ) {
					newNode->prev = last ;
					newNode->next = nullptr ;

					last = newNode ;
				}
			}
			itemCount++ ;
		}
	}
	char* remove( char *value ) {
		char *tr = nullptr ;
		if( !isEmpty() ){
			Node *toExtract = _findNode_( value ) ;
			if( toExtract != nullptr ) {
				tr = toExtract->value ;
				if( toExtract != first && toExtract != last ){
					Node *prev = toExtract->prev ;
					Node *next = toExtract->next ;

					prev->next = next ;
					next->prev = prev ;
				} else if( toExtract == first ){
					first = toExtract->next ;
					Node *next = toExtract->next ;
					if( next != nullptr ) next->prev = nullptr ;
					if( next == nullptr ) last = first ;
				} else if( toExtract == last ) {
					last = toExtract->prev ;
					Node *prev = toExtract->prev ;
					if( prev != nullptr ) prev->next = nullptr ;
					if( prev == nullptr ) first = last ;
				}

				delete toExtract ;

				itemCount-- ;
			}
		}
		return tr ;
	}
	char* remove( Pos position ) {
		char *tr = nullptr ;
		if( !isEmpty() ){
			Node *toExtract = _findNodeByIndex_( position ) ;
			if( toExtract != nullptr ){
				tr = toExtract->value ;
				if( toExtract != first && toExtract != last ){
					Node *prev = toExtract->prev ;
					Node *next = toExtract->next ;

					prev->next = next ;
					next->prev = prev ;
				} else if( toExtract == first ){
					first = toExtract->next ;
					Node *next = toExtract->next ;
					if( next != nullptr ) next->prev = nullptr ;
					if( next == nullptr ) last = first ;
				} else if( toExtract == last ) {
					last = toExtract->prev ;
					Node *prev = toExtract->prev ;
					if( prev != nullptr ) prev->next = nullptr ;
					if( prev == nullptr ) first = last ;
				}

				delete toExtract ;

				itemCount-- ;
			}

		}
		return tr ;
	}
	char* removeFirst( void ) {
		char *tr = nullptr ;
		if( !isEmpty() ) {
			Node *temp = first ;

			if( temp != nullptr ) {
				first->prev = nullptr ;
				first = first->next ;
				tr = temp->value ;
			} else {
				;
			}

			delete temp ;
			itemCount-- ;
		}

		return tr ;
	}
	char* removeLast( void ) {
		char *tr = nullptr ;
		if (!isEmpty() ) {
			Node *temp = last ;
			last = last->prev ;
			last->next = nullptr ;

			tr = temp->value ;

			delete temp ;
			itemCount-- ;
		}
		return tr ;
	}
	bool replace( char *valueOut, char *valueIn ) {
		bool tr = false ;
		if( contained( valueOut ) ) {
			remove( valueOut ) ;
			insert( valueIn ) ;
			tr = true ;
		}
		return tr ;
	}

	// capacity and info functions
	bool isEmpty( void ) {
		return itemCount == 0 ;
	}
	size listSize( void ) {
		return itemCount ;
	}
	Pos indexOf( char *value ) {
		return _indexOf_( value ) ;
	}
	bool contained( char *value ) {
		bool toReturn = false ;
		Node *current = first ;
		for( ;
			current != nullptr && *current->value != *value ;
			current = current->next ) ;
		char *toCompare ;
		if( current == nullptr ) toReturn = false ;
		if ( current != nullptr ) toReturn = ( *toCompare == *current->value ) ;
		return toReturn ;
	}
	// manage functions
	void emptyList( void ) {
		while( !isEmpty() ) {
			removeLast() ;
		}
	}
} ;

//
// TEMPLATE FOR STD::STRING
//
template<>
class DOList<std::string>: public IList<std::string> {
	private:
		struct Node{
			std::string value ;

			Node *next ;
			Node *prev ;

			Node( void ){
				value = "" ;
				next, prev = nullptr ;

			}
			~Node( void ) { } ;

			private:
				Node( const Node &otherNode ) ;
				Node& operator= ( const Node &otherNode ) ;
		} ;

		Node *first , *last ;

		size itemCount ;

		// helpers
		Pos _indexOf_( const std::string value ) {
			Pos tr = -1 ;
			if( !isEmpty() ){
				Node *current = first ;
				Pos position = 0 ;
				for( ;
					current != nullptr && current->value !=  value ;
					current = current->next ) {
						position++ ;
				}
			if( current != nullptr && current->value == value ) tr = position ;
			}
			return  tr ;
		}
		Node* _findNode_( const std::string value ) {
			Node *found = nullptr ;
			if( !isEmpty() ){
				Node *current = first ;
				for( ;
					 current != nullptr && current->value != value ;
					 current = current->next ) ;
						found = current ;
			}
			return found ;
		}
		Node* _findNodeByIndex_ ( const Pos position ){
			Pos count = 0 ;
			Node *current = first ;
			Node *found = nullptr ;
			for (;
				current != nullptr ;
				current = current->next ){
				if( position == count ) found = current ;
				count++ ;
			}
			return found ;
		}

		Node* _sortItem_( std::string value ) {
			Node *current = nullptr ;
			if( !isEmpty()){
				current = first ;
				for( ;
					 current != nullptr && current->value == value ;
					 current = current->next ) ;
			}
			return current ;
		}
		// copy constructor ;
		DOList(const DOList &otherList ) ;
		// operator=
		DOList& operator=( const DOList& otherList ) ;


 public:
	//constr&dest
	DOList( void ){
		first, last = nullptr ;
		itemCount = 0 ;
	}
	~DOList( void ){
		emptyList() ;
		if ( first ) delete first ;
		if ( last ) delete last ;
	}

	// adding, deleting and replacing functions
	void insert( std::string value ){
		if( !contained( value ) ) {
			Node *newNode = new Node ;
			newNode->value = value ;

			Node *nextNode = _sortItem_( value ) ;

			if( nextNode != nullptr ) {
				newNode->prev = nextNode->prev ;
				newNode->next = nextNode ;

				nextNode->prev = newNode ;
			} else {
				if( first == nullptr ) {
					first = newNode ;
					last = newNode ;
				} else if ( first == last && first != nullptr ) {
					newNode->prev = first ;
					newNode->next = nullptr ;
					first->next = newNode ;

					last = newNode ;
				} else if ( first != last ) {
					newNode->prev = last ;
					newNode->next = nullptr ;

					last = newNode ;
				}
			}
			itemCount++ ;
		}
	}
	std::string remove( std::string value ) {
		std::string tr = "" ;
		if( !isEmpty() ){
			Node *toExtract = _findNode_( value ) ;
			if( toExtract != nullptr ) {
				tr = toExtract->value ;
				if( toExtract != first && toExtract != last ){
					Node *prev = toExtract->prev ;
					Node *next = toExtract->next ;

					prev->next = next ;
					next->prev = prev ;
				} else if( toExtract == first ){
					first = toExtract->next ;
					Node *next = toExtract->next ;
					if( next != nullptr ) next->prev = nullptr ;
					if( next == nullptr ) last = first ;
				} else if( toExtract == last ) {
					last = toExtract->prev ;
					Node *prev = toExtract->prev ;
					if( prev != nullptr ) prev->next = nullptr ;
					if( prev == nullptr ) first = last ;
				}

				delete toExtract ;

				itemCount-- ;
			}
		}
		return tr ;
	}
	std::string remove( Pos position ) {
		std::string tr = "" ;
		if( !isEmpty() ){
			Node *toExtract = _findNodeByIndex_( position ) ;
			if( toExtract != nullptr ){
				tr = toExtract->value ;
				if( toExtract != first && toExtract != last ){
					Node *prev = toExtract->prev ;
					Node *next = toExtract->next ;

					prev->next = next ;
					next->prev = prev ;
				} else if( toExtract == first ){
					first = toExtract->next ;
					Node *next = toExtract->next ;
					if( next != nullptr ) next->prev = nullptr ;
					if( next == nullptr ) last = first ;
				} else if( toExtract == last ) {
					last = toExtract->prev ;
					Node *prev = toExtract->prev ;
					if( prev != nullptr ) prev->next = nullptr ;
					if( prev == nullptr ) first = last ;
				}

				delete toExtract ;
				itemCount-- ;
			}

		}
		return tr ;
	}
	std::string removeFirst( void ) {
		std::string tr = "" ;
		if( !isEmpty() ) {
			Node *temp = first ;

			if( temp != nullptr ) {
				first->prev = nullptr ;
				first = first->next ;
				tr = temp->value ;
			} else {
				;
			}

			delete temp ;
			itemCount-- ;
		}

		return tr ;
	}
	std::string removeLast( void ) {
		std::string tr = "" ;
		if (!isEmpty() ) {
			Node *temp = last ;
			last = last->prev ;
			last->next = nullptr ;

			tr = temp->value ;

			delete temp ;
			itemCount-- ;
		}
		return tr ;
	}
	bool replace( std::string valueOut, std::string valueIn ) {
		bool tr = false ;
		if( contained( valueOut ) ) {
			remove( valueOut ) ;
			insert( valueIn ) ;
			tr = true ;
		}
		return tr ;
	}

	// capacity and info functions
	bool isEmpty( void ) {
		return itemCount == 0 ;
	}
	size listSize( void ) {
		return itemCount ;
	}
	Pos indexOf( std::string value ) {
		return _indexOf_( value ) ;
	}
	bool contained( std::string value ) {
		bool toReturn = false ;
		Node *current = first ;
		for( ;
			current != nullptr && current->value != value ;
			current = current->next ) ;
		std::string toCompare ;
		if( current == nullptr ) toReturn = false ;
		if ( current != nullptr ) toReturn = ( toCompare == current->value ) ;
		return toReturn ;
	}
	// manage functions
	void emptyList( void ) {
		while( !isEmpty() ) {
			removeLast() ;
		}
	}
} ;
