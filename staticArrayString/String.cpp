#include "String.h"

int String::strlen( const char *s )
{
	int len = 0;
	while ( s[len] )
		++len;
	return len;
}

char * String::strcpy( char *dest, const char *src )
{
	int i;
	for ( i = 0; src[i]; i++ )
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

char * String::strcat( char *dest, const char *src)
{
	int destLength = strlen(dest);
	strcpy( & dest[destLength] , src );
}

int String::strcmp( const char *left, const char *right )
{
	while (true)
	{
		if ( *left == *right )
		{	if ( *left == '\0' && *right == '\0' )
				return 0;
			else
			{
				left++;
				right++;
			}
		}
		else
		{
			return *left - *right;
		}
	}
}

const char * String::strchr( const char *str, int c)
{
	while (str)
	{
		if (*str == c)
			return str;
		else
			str++;
	}
	const char * myPointer = NULL;
	return myPointer;
}

char * String::strchr ( char *str, int c)
{
	return const_cast<char *>( strchr( const_cast<const char *>(str),c ));
}

const char * String::strstr(const char *haystack, const char *needle)
{	
	int i;
	for ( i = 0; haystack[i]; i++)
	{
	//	cout << "iteration " << i << endl;
	//	cout << haystack[i] << endl;
	//	cout << needle  << endl;
		if (haystack[i] == needle[0])
		{
		//	cout << "found at index " << i << endl;
			int n;
			for (n = 1; needle[n]; n++)
			{
				if ( !  ( haystack[i + n] == needle[n]) )
				{
					break;	
				}
				if ( needle[n + 1] == '\0'  )
					return &haystack[i];
			} 
		}	
	}
	char * myPointer = NULL;
	return myPointer;
}

char * String::strstr( char * haystack, const char * needle)
{
	return const_cast<char *>( strstr( const_cast<const char*>(haystack), needle ) );
}

int String::strncmp ( const char *left, const char *right, int n )
{
	int index = 0;
	while (true)
	{	
		if (index > n)
			return 0;
		if (*left == *right)
		{
			if (*left == '\0' && *right == '\0')
				return 0;
			else
				left++;
				right++;
				index++;
		}
		else
			return *left - *right;
		
	}	
}

String::String( const char * s )
{
	strcpy( buf, s);

}

String::String( const String & s )
{
	strcpy( buf, s.c_str() );
	
}

String::~String()
{

}

void String::print( ostream & out)
{
	for (int i = 0; buf[i]; i++)
	{
		out << buf[i];
	}
}
void String::read (istream & in)
{
/*
	for (int i = 0; buf[i]; i++)
	{
		in >>  buf[i];
	}
	in.ignore();
*/
	in.getline(buf, MAXLEN);
}

int String::indexOf( const char c )
{
	int index = 0;
	while (strchr( buf, c) )
	{
		if (buf[index] == c)
		{
			return index;
		}
		else
		{
			index++;
		}
	}
	return -1;	
}

int String::indexOf( const String pattern)
{
//	cout << strstr(buf, pattern.buf ) << endl;	


	
	if(  *strstr( buf, pattern.buf) )
	{
		int i = 0;
		for (i = 0; buf[i]; i++)
		{
			if (buf[i] ==  strstr(buf, pattern.buf)[0]  ) 
			{
				return i;
			}
		}
		return i;
	}
	else
		return -1; 
}

String String::reverse()
{
	String a;
	int length = this->size();
	for (int i = 0; i < length; i++)
	{
		a[i] = buf[ (length - 1) + -i  ];
	}

	return a;
	
}

ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}
istream & operator >> ( istream & in, String & str)
{
	str.read(in);
	return in;
}

char & String::operator [] ( int index )
{
	return buf[index];	
}

String String::operator += ( const String s )
{
	return strcat ( buf, s.c_str() );
}

String String::operator + ( const String s)
{
	String a;
	char * test = a.buf;
	const char* leftString = s.c_str();
	strcpy (test, buf);
	strcat(test, leftString);	
	return test;
}	

int String::size()
{
	return strlen(buf);
}

bool String::operator == ( const String s )
{
	return strcmp( buf, s.c_str() ) == 0;
}

bool String:: operator != ( const String s )
{
	return strcmp( buf, s.c_str() ) != 0;
}

bool String::operator > ( const String s)
{
	return strcmp( buf, s.c_str() ) > 0;
}

bool String::operator < ( const String s)
{
	return strcmp( buf, s.c_str() ) < 0;
}

bool String::operator <= ( const String s)
{
	return strcmp( buf, s.c_str() ) <= 0;
}

bool String::operator >= ( const String s)
{
	return strcmp( buf, s.c_str() ) >= 0;
}

String String::operator = ( const String & s)
{
	strcpy ( buf, s.c_str() );
	return *this;
}

const char * String::c_str() const
{
	return (const char *) buf;	
}
