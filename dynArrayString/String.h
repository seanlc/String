#include <iostream>

using namespace std;

class String
{
public:
  /// Both constructors should construct
  // this String from the parameter s
  String( const char * s = "" );
  String( const String & s );
  String( int n );
  String operator = ( const String & s );
  char & operator [] ( int index );
  int size();
  String reverse(); // does not modify the string
  int indexOf( const char c );
  int indexOf( const String pattern );
  bool operator == ( const String s );
  bool operator != ( const String s );
  bool operator > ( const String s );
  bool operator < ( const String s );
  bool operator <= ( const String s );
  bool operator >= ( const String s );
  /// concatenates this and s to return result
  String operator + ( const String  s );
  /// concatenates s onto end of this
  String operator += ( const String s );
  void print( ostream & out);
  void read( istream & in );
  ~String();
  static void final_report_on_allocations()
  {
	cout << "Number of new allocations minus number of delete deallocations is "
	     << allocations << endl;
  }
private:
  bool inBounds( int i )
  {
	return i >= 0 && i < strlen(buf );
  }
  void error( char*msg )
  {
  	cerr << "Error: " << msg << endl;
  }
  static int strlen( const char *src );
  static char *strdup( const char *src );
  static char * strcpy( char * dest, const char * src );
  static int strcmp ( const char *left, const char *right );
  static String strcat( String dest, const String c, String & helper );
  static String strcat( String dest, const String c);
  static const char * strchr( const char *str, int c );
  static char * strchr( char *str, int c );
  static const char * strstr( const char *haystack, const char *needle );
  static char * strstr( char *haystack, const char *needle );
  
  char * buf; // base of array for the characters in this string
  // DO NOT add a length data member!! use the null terminator
  static int allocations;
  static char * new_char_array( int n_bytes)
  {
	++allocations;
	return new char[n_bytes];
  }
  static void delete_char_array( char * p )
  {
	--allocations;
	if (allocations < 0)
		error("more delete[] than new[]");
	delete [] p;
  }
  static void error( const char * p )
  {
	cerr << "Error (class String): " << p << endl;
  }
};
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );
