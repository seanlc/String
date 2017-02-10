#include "String.h"

using namespace std;

void test_constructor_and_print()
{
	String s("Hello World");
	String b;

	cout << s << endl;
	cout << "empty string: " << b << endl;
}

void test_bracketOp()
{
	String s("Hello");
	for (int i = 0; s[i] ; i++ )
	{
		cout << s[i] << " " << endl;
	}
}

void test_plusEqualOp()
{
	String a("apple");
	String b("banana");
	a += b;
	cout << a << endl;
}

void test_plusOp()
{
	String a("pomegranate");
	String b("orange");
	if (a + b == "pomegranateorange")
		cout << "test 1 for + operator works" << endl;
	else
		cout << a + b << endl;
	if (b + a == "orangepomegranate")
		cout << "test 2 works for + operator" << endl;
	else
		cout << b + a << endl;
}
void equalityTest()
{
	String a("hello");
	String b("hello");
	String c("hellop");

	if ( a == b )
		cout << "equal works" << endl;
	else
		cout << "didnt work" << endl;

	if ( a == c  )
		cout << "returns equal on not equal" << endl;
	else
		cout << "equal fails correctly on not equal" << endl; 
}

void testNotEqualOp()
{
	String a("bunny");
	String b("peter");
	String c("bunny");
	if ( a != b )
		cout << "not equal works on not equal terms" << endl;
	else
		cout << "not equal does not work on not equal terms" << endl;

	if ( a != c )
		cout << "not equal fails on equal terms" << endl;
	else
		cout << "not equal works on equal terms" << endl;
}

void testGreaterThanOp()
{
	String a("aba");
	String b("ab");
	String c("abac");
	if (a > b)
		cout << "Test 1 works" << endl;
	if (c > a)
		cout << "Test 2 works" << endl;
	if ( !  ( a > a) )
		cout << "Test 3 works" << endl;
	
}

void testLessThanOp()
{
	String a("aba");
	String b("ab");
	String c("abac");
	if ( b < a )
		cout << "test 1 works" << endl;
	if ( a < c )
		cout << "test 2 works" << endl;
	if (b < c)
		cout << "test 3 works"  << endl;
}

void testLessThanOrEqualOp()
{
	String a("aba");
	String b("aba");
	String c("abac");
	String d("a");
	
	if (a <= b)
		cout << "test 1 works" << endl;
	if (d <= a)
		cout << "test 2 works" << endl;
	if (! ( c <= d)   )
		cout << "test 3 works" << endl;
}

void testGreaterThanOrEqualOp()
{
	String a("aba");
	String b("aba");
	String c("abac");
	String d("aa");

	if ( a >= b)
		cout << "test 1 works" << endl;
	if ( c >= a )
		cout << "test 2 works" << endl;
	if (! (d >= a))
		cout << "test 3 works" << endl;
}

void testSize()
{
	String a("aba");
	String b("abacdef");
	
	if (a.size() == 3)
		cout << "test 1 works" << endl;
	if (b.size() == 7)
		cout << "test 2 works" << endl;
}

void testAssignment()
{
	String a("aba");
	String b("");
	a = "back";
	b = "timeless";
	if ( a == "back")
		cout << "test 1 works" << endl;
	else
		cout << "test 1 failed: " << a << endl;
	if (b == "timeless")
		cout << "test 2 works" << endl;
	else 
		cout << "test 2 failed: " << b << endl;
	
}

void testInsertOperator()
{
	String a("abcd");
	cout << "enter a string: " << endl;
	cin >> a;
	cout << "new value: " << a << endl;
//	cin.ignore();
	cout << "enter a string" << endl;
	String b("");
	cin >> b;
	cout << "new value: " << b  << endl;
}

void testIndexOfChar()
{
	String a("abc");
	String b("bet");
	if ( a.indexOf('a') == 0 )
		cout << "IndexOf(char) works" << endl;
	if ( b.indexOf('t') == 2)
		cout << "IndexOf(char) works" << endl;
}

void testIndexOfStr()
{
	String a("xxxabxxxx");
	String b("xxxxxxoiuxxxxxx");
	cout << a.indexOf("ab") << " index should be 3" << endl;
	/*
	if ( a.indexOf("ab") == 3 )
		cout << "test 1 works" << endl;
	else
		cout << "test 1 failed: " << a.indexOf("ab") << endl;
	if (b.indexOf("oiu") == 6)
		cout << "test 2 works" << endl;
	else
		cout << "test 2 failed: " << b.indexOf("oiu") << endl;
	*/
}

void testReverse()
{
	String a("hello");
	String b("there");
	if (a.reverse() == "olleh")
		cout << "Test 1 for Reverse() works " << endl;
	else
		cout << "test 1 for Reverse() failed" << endl;
	cout << a.reverse() << endl;
	if (b.reverse() == "ereht")
		cout << "test 2 for Reverse() works " << endl;
	else
		cout << "test 2 for Reverse() failed " << endl;
	cout << b.reverse() << endl;
}

int main()
{

//	test_constructor_and_print();
//	test_bracketOp();
//	test_plusEqualOp();
//	test_plusOp();
//	equalityTest();
//	testNotEqualOp();
//	testGreaterThanOp();
//	testLessThanOp();
//	testLessThanOrEqualOp();
//	testGreaterThanOrEqualOp();
//	testSize();
//	testAssignment();
//	testInsertOperator();
//	testIndexOfChar();
	testIndexOfStr();
//	testReverse();
	return 0;
}
