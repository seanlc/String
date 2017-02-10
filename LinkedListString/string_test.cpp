#include "String.h"

using namespace std;

void test_constructor_and_print()
{
	String s("Hello World");
	String b;
//	String c(8);

	cout << "String s: "  << s << endl;
	cout << "empty string: " << b << endl;
}

void test_bracketOp()
{
	String s("Hello");
	int size = s.size();	
	for (int i = 0; i < size; i++)
	{
		cout << s[i] << endl;
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
		cout << "test 1 for plus op failed" << endl;
//	cout << "value in a: "<< a << endl;
//	cout << "a+b value : " << a + b << endl;
//		cout << a + b << endl;
//	if (b + a == "orangepomegranate")
//		cout << "test 2 works for + operator" << endl;
//	else
//		cout << b + a << endl;
//
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
/*	cout << "enter a string" << endl;
	String b("");
	cin >> b;
	cout << "new value: " << b  << endl;
*/
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

	test_constructor_and_print();
	test_bracketOp();
	test_plusEqualOp();
	test_plusOp();
	equalityTest();
	testLessThanOp();
	testSize();
	testAssignment();
	testInsertOperator();
	testIndexOfChar(); 
	testReverse();
	return 0;
}
