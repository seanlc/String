#include "String.h"

int String::ListNode::length(ListNode * L)
{
	ListNode * trav = L;
	int nodeCount = 0;
	while( trav != nullptr ) 
	{
		trav=trav->next;
		nodeCount++;
	}
	return nodeCount;
}

String::ListNode * String::ListNode::copy ( ListNode * L )
{
	if ( L == nullptr )
		return nullptr;

	ListNode * first = new ListNode( L->info, nullptr );
	ListNode * temp = first;
	ListNode * trav;
		
	for( trav = L->next; trav != nullptr; temp = temp->next )
	{	
		temp->next = new ListNode( trav->info, nullptr );
		trav = trav->next;
				
	}	
	return first;	
}
String::ListNode * String::ListNode::stringToList( const char *s )
{
	ListNode * first = nullptr;
	if ( *s == 0 )
	{
	//	cout << "exit" << endl;
		return first;
	}

	first = new ListNode( s[0], NULL);
	ListNode * trav = first;

	for (int i = 1; s[i] ; i++ )
	{
		ListNode * newNode = new ListNode( s[i], NULL );
		trav->next = newNode;
		trav = newNode;
//		cout << trav->info << endl;
	}	
	return first;
}
void String::ListNode::deleteList(ListNode * L)
{
	ListNode * cur = L;
	ListNode * next;

	while ( cur != nullptr )
	{
		next = cur->next;
		delete cur;
		cur = next;
	}	
	L = nullptr;
}
bool String::ListNode::equal( ListNode * L1, ListNode * L2 )
{
	int lenL1 = length( L1 );
	int lenL2 = length( L2 );
	if ( lenL1 != lenL2 )
		return false;
	ListNode * trav1 = L1;
	ListNode * trav2 = L2;
	while( trav1 != nullptr )
	{
		if ( trav1->info != trav2->info )
			return false;
		trav1 = trav1->next;
		trav2 = trav2->next;
	}
	return true;
}
int String::ListNode::compare( ListNode * L1, ListNode * L2)
{
	int lenL1 = length( L1 );
	int lenL2 = length( L2 );
	if ( lenL1 != lenL2 )
	{
		return lenL1 - lenL2;
	}
	ListNode * trav1 = L1;
	ListNode * trav2 = L2;
	while ( trav1 != nullptr )
	{
		if ( trav1->info == 0 && trav2->info == 0 )
			return 0;
		if ( trav1->info != trav2->info )
			return trav1->info - trav2->info;
		trav1 = trav1->next;
		trav2 = trav2->next;
	}
	return 0;
}
String::ListNode * String::ListNode::concat( ListNode * L1, ListNode * L2 )
{	
	if ( L1 == nullptr )
		return  copy(L2);
	if ( L2 == nullptr )
		return copy(L2);
	
	ListNode * trav = copy(L1);
	ListNode * headReturn = trav;
	
	while (trav->next != nullptr )
		trav = trav->next;
	
	trav->next = copy(L2);
	
	return headReturn;
}
String::String( const char * s)
{
	head = ListNode:: stringToList(s);
}
String::String( const String & s)
{
	head = ListNode::copy(s.head);
}
String::~String()
{
	ListNode::deleteList(head);
}
void String::print( ostream & out )
{
	if ( head == nullptr )
	//	cout << "empty " << endl;
		out.clear();
	for ( ListNode * p = head; p != nullptr; p = p->next )
	{
	//	cout << p->info << endl;
		out << p->info;
	}
}
void String::read( istream & in )
{
	char * input = new char[128];
	in.get(input , 128);
	ListNode::deleteList( head );	
	head = ListNode::stringToList( input );
	delete [] input;
}
ostream & operator << ( ostream & out, String str)
{
	str.print ( out );
	return out;
}
istream & operator >> ( istream & in , String & str )
{
	str.read( in );
	return in;
}
char & String::operator [] ( const int index )
{
	ListNode * trav = nullptr;
	int count = 0;
	for ( trav = head; trav != nullptr; trav = trav->next)
	{
		//cout << count << endl;
		if ( index == count )
		{
			return trav->info;
		}
		//cout << trav->info << endl;
		count++;
	}
	return head->info;
}
bool String::operator == ( const String & s ) const
{
	return ListNode::equal( this->head, s.head );
}
String String::operator = ( const String & s )
{
	ListNode::deleteList(head);
	head = ListNode::copy(s.head);
	return *this;
}
String String::operator += ( const String & s )
{
	String placeHolder;
	placeHolder.head = ListNode::concat(head, s.head) ;
	ListNode::deleteList(head);
	head = ListNode::copy(placeHolder.head);
	return *this;
}
String String::operator + ( const String & s ) const
{
	String result;
	ListNode::deleteList(result.head);
	result.head = ListNode::concat(this->head, s.head);
	return result;
}
bool String::operator < ( const String & s ) const
{
	return ListNode::compare( head, s.head ) < 0;
}
int String::size() const
{
	return ListNode::length(head);
}
String String::reverse()
{
	if (size() == 0)
		return *this;
	int stringLength = size();
	char * charArray = new char [ stringLength + 1 ];
	charArray[stringLength] = '\0';
	ListNode * trav = head;
	int i = stringLength - 1;
	while ( trav != nullptr )
	{
		charArray[i] = trav->info;
		i--;
		trav = trav->next;
	}
	String reversedString;
	ListNode::deleteList( reversedString.head );
	reversedString.head =  ListNode::stringToList( charArray );
	delete [] charArray;
	return reversedString;
}
int String::indexOf( char c ) const
{
	int i = 0;
	for ( ListNode * p = head; p != nullptr; p = p->next )
	{
		if ( p->info == c )
			return i;
		i++;
	}
	return 0;
}
