#include "String.h"

int String::allocations = 0;
int String::strlen (const char *src)
{
	int i = 0;
	while (src[i])
		++i;
	return i;
}

char * String::strcpy ( char * dest, const char * src )
{
	int i;
	for (i = 0; src[i]; i++)
	{
		*dest = src[i];
		dest++;
	}
	dest[i] = '\0';
	return dest;
}
char * String::strdup( const char *src )
{
	int srcLength = strlen(src);
	char * newArray = new_char_array( srcLength + 1 );
	strcpy( newArray, src );
	return newArray;
}
int String::strcmp( const char *left, const char *right)
{
	while (true)
	{
		if ( *left == *right )
		{
			if ( *left == '\0'&& *right == '\0' )
				return 0;
			else
			{
				left++;
				right++;
			}
		}
		else
			return *left - *right;
	}
}
const char * String::strchr( const char *str, int c )
{
	while ( str )
	{
		if (*str == c)
			return str;
		else
			str++;
	}
	const char * myPointer = NULL;
	return myPointer;
}
char * String::strchr( char *str, int c )
{
	return const_cast<char *>( strchr( const_cast<const char *>(str),c ));
}
const char * String::strstr( const char *haystack, const char *needle )
{
	int i;
//	int haystackLen = a.size();
	int haystackLen = strlen(haystack);	
	for ( i = 0; i < haystackLen ; i++ )
	{
		if ( haystack[i] == needle[0] )
		{
			int n;
			for (n = 1; needle[n]; n++)
			{
				if ( ! ( haystack[i + n] == needle[n]) )
					break;
				if ( needle[n + 1] == '\0')
					return &haystack[i];
			}
		} 
	} 
	char * myPointer = NULL;
	return myPointer; 
}
char * String::strstr( char *haystack, const char *needle)
{
	return const_cast<char *>( strstr( const_cast<const char *>(haystack), needle ) );
}

String String::strcat( String dest, const String src )
{

	char * oldBuf = dest.buf;
	String a(src);
	int destLen = dest.size();
	int srcLen = a.size();
	dest.buf = new_char_array( destLen + srcLen + 1 );
	strcpy( dest.buf , oldBuf  );
	strcpy( &dest.buf[destLen] , src.buf );
	delete_char_array(oldBuf);
	return dest.buf;
		
} 
String::String( const char * s )
: buf ( strdup( s ) )
{
//	buf = strdup(s);
}

String::String( const String & s )
: buf ( strdup( s.buf ) )
{
//	buf = strdup(s.buf);
}

String::String( int n )
: buf(new_char_array(n) )
{
	buf[0] = '\0';
}  
String::~String()
{
	delete_char_array(buf);
}
char & String::operator [] (int index)
{
	if ( !inBounds( index ) ) 
		error("Out of bounds");
	return buf[index];
}
bool String::operator > ( const String s )
{
	return strcmp( buf, s.buf  ) > 0;
}
bool String::operator >= ( const String s)
{
	return strcmp( buf, s.buf ) >= 0;
}
bool String::operator < ( const String s)
{
	return strcmp(buf, s.buf ) < 0;
}
bool String::operator <= ( const String s)
{
	return strcmp( buf, s.buf ) <= 0;
}
bool String::operator == ( const String s )
{
	return strcmp( buf, s.buf ) == 0;
}
bool String::operator != ( const String s)
{
	return strcmp( buf, s.buf ) != 0;
}

String String::operator + ( const String s )
{
//	cout << "value in a " << buf << endl;
	String result("");
	result += this->buf;
//	cout << "result value after first +="  << result << endl;
	result += s;
	return result;
}

String String::operator = ( const String & s )
{
	String a(s);
	char * oldbuf = buf;
	buf = new_char_array( a.size() );
	strcpy( buf, s.buf);
	delete_char_array(oldbuf); 	
	return *this;
}
String String::operator += (const String s)
{
//	strcat(buf,s.buf);
	
	String a(s);
	char * result = new_char_array(size() + a.size() + 1);
	strcpy( result, buf);
	strcpy( &result[size()], a.buf );
	delete_char_array(buf);
	buf = result; 
	return *this;
}
void String::print ( ostream & out )
{
	for (int i = 0; buf[i]; i++)
	{
		out << buf[i];
	}
}
int String::size()
{
	return strlen( buf );
}
String String::reverse()
{
	String a  = buf;
	int length = this->size();
	for ( int i = 0; i < length; i++ )
	{
		a[i] = buf[ (length - 1) + -i ];
	}
	return a;
}
int String::indexOf( const char c)
{
	int index = 0;

	while ( strchr( buf, c) )
	{
		if (buf[index] == c)
			return index;
		else
			index++;
	} 
	return -1;
}
int String::indexOf ( const String pattern )
{
	String patt(pattern);
	if (patt.size() == 0)
		return -1;
	if ( strlen(pattern.buf) > size() )
		return -1;
	if ( *strstr( buf, pattern.buf) ) 
	{
		
		int i;
		for ( i = 0; buf[i]; i++ )
		{
			if ( buf[i] == strstr(buf, pattern.buf)[0] )
				cout << "condition met" << endl;
				return i;
		}
		return -1; 
			
	}
	else  
		return -1;
}
void String::read( istream & in )
{
	in >> buf;
}
ostream & operator << ( ostream & out, String str)
{
	str.print(out);
	return out;
}
istream & operator >> ( istream & in, String & str)
{
	str.read(in);
	return in;
}
