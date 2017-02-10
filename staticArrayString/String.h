#include <iostream>
#define MAXLEN 128

using namespace std;

class String
{
public:
  /// Both constructors should
  /// construct this String from the parameter s
  String ( const char * s = "" );
  String( const String & s );
  String operator = ( const String & s );
  char & operator [] ( int index ) ;
  int size();
  String reverse(); // does not modify the string
  int indexOf ( const char c );
  int indexOf ( const String pattern );
  bool operator == ( const String s);
  bool operator != ( const String s );
  bool operator > ( const String s);
  bool operator < ( const String s);
  bool operator <= ( const String s);
  bool operator >= ( const String s);
  /// concatenates this and s to return result
  String operator + ( const String s);
  /// concatenates s onto end of this
  String operator += ( const String s);
  void print ( ostream & out);
  void read ( istream & in );
  ~String();
  const char * c_str() const;
private:
  bool inBounds ( int i )
  {
    return i >= 0 && i < strlen(buf);
  } /// Hint: some C string primitives you should define and use
  static int strlen( const char *s);
  static char * strcpy ( char *dest, const char *src );
  static char * strcat ( char *dest, const char *src);
  static int strcmp ( const char *left, const char *right );
  static int strncmp ( const char *left, const char *right, int n );
  static const char * strchr ( const char *str, int c );
  static char * strchr ( char *str, int c);
  static const char * strstr ( const char *haystack, const char *needle );
  static char * strstr( char *haystack,  const char *needle );
  char buf[MAXLEN]; // array for the characters in this string
  // do not store the logical length of this string
  // use the null '\0' terminator to mark the end
};
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );
