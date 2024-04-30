/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/ Information about the headers were got from:
/ cppreference: https://en.cppreference.com/w/c/header
/ IME-USP: https://www.ime.usp.br/~pf/algorithms/appendices/libraries.html
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// INCLUDING ALL STANDARD LIBRARY HEADERS

#include <assert.h> // macro that compares argument to zero
#include <complex.h> // complex numbers arithmetics
#include <ctype.h> // functions to determine the type contained in character data
#include <errno.h> // macros for error reporting
#include <fenv.h> // floating-point enviroment
#include <float.h> // limits of floating point
#include <inttypes.h> // format conversion for ints
#include <iso646.h> // alternative operator spellings
#include <limits.h> // ranges of integer types
#include <locale.h> // localization/language utilities
#include <math.h> // mathematical functions
#include <setjmp.h> // nonlocal jumps
#include <signal.h> // signal handling
#include <stdalign.h> // alignas and alignof macros
#include <stdarg.h> // variable arguments
#include <stdatomic.h> // atomic operations
#include <stdbool.h> // boolean macros
#include <stddef.h> // common macro definitions
#include <stdint.h> // fixed-width int types
#include <stdio.h> // input and output
#include <stdlib.h> // general utilities
#include <stdnoreturn.h> // noreturn convenience macro
#include <string.h> // string handling
#include <tgmath.h> // type-generic math
#include <threads.h> // threads library
#include <time.h> // time/data utilities
#include <uchar.h> // UTF-16 and UTF-32 character utilities
#include <wchar.h> // extended multibyte and wide character utilities
#include <wctype.h> // functions to determine the type contained in wide character data

// DECLARATION OF ALL THE TEST FUNCTIONS
// 1 function per header, the function prototypes are
// in the following format: 
// void test[HeaderName]H();

void testAssertH();
void testComplexH();
void testCtypeH();
void testErrnoH();
void testFenvH();
void testFloatH();
void testIntTypesH();
void testISO646H();
void testLimitsH();
void testLocaleH();
void testMathH();
void testSetjmpH();
void testSignalH();
void testStdAlignH();
void testStdArgH();
void testStdAtomicH();
void testStdBoolH();
void testStdDefH();
void testStdIntH();
void testStdIOH();
void testStdLibH();
void testStdNoReturnH();
void testStringH();
void testTgMathH();
void testThreadsH();
void testTimeH();
void testUcharH();
void testWcharH();
void testWCtypeH();

// Now, to understand and test each header, just read
// its respective function and call it in main
// (and ofc, modify the functions as you please, experiment!)
int main(int argc, char const *argv[]) {
	testSetjmpH();
	return 0;
}



// This header has basically only 1 function (the other one is deprecated)
void testAssertH() {
	int x = 10;
	int y = 20;

	printf("doing assert 1\n");
	assert(x < y); // true
	printf("doing assert 2\n");
	assert(x != y); // true

	// see what happens when assert() is given a false statement
	printf("doing assert 3\n");
	// uncomment the next line to see what happens
	// assert(x == y); // false
	printf("after assert 3 :^)\n");
}



void testComplexH() {
	// pure imaginary numbers
	// there is an "imaginary" type but its not aways supported
	float complex floatImag = 2.0 * I;
	double complex doubleImag = 7.77 * I;
	long double complex ldoubleImag = -2.5555555555 * I;

	// pure real numbers
	float floatReal = 111.1;
	double doubleReal = 9.99;
	long double ldoubleReal = 3.14159;

	// complex numbers
	float complex floatComplex = floatReal + floatImag;
	double complex doubleComplex = doubleReal + doubleImag;
	long double complex ldoubleComplex = ldoubleReal + ldoubleImag;

	// the "crealf", "creal" and "creall" functions return the real part of a complex num
	// the "cimag", "cimag" and "cimagl" functions return the imaginary part of a complex num
	printf("\n\nfloat complex = %.1f + %.1fi\n", crealf(floatComplex), cimagf(floatComplex));
	printf("double complex = %.2lf + %.2lfi\n", creal(doubleComplex), cimag(doubleComplex));
	printf("long double complex = %.5Lf + %.5Lfi\n", creall(ldoubleComplex), cimagl(ldoubleComplex));

	// some functions that manipulate complex numbers
	printf("\nabsolute (modulus) value of a complex: %lf\n", cabs(doubleComplex));
	printf("phase angle of a complex: %lf\n", carg(doubleComplex));
	printf("conjulgate of a complex: %lf + %lfi\n", creal(conj(doubleComplex)), cimag(conj(doubleComplex)));
	printf("projection of a complex on Riemann sphere: %lf + %lfi\n", creal(cproj(doubleComplex)), cimag(cproj(doubleComplex)));

	// complex versions of the pow() and sqrt() functions
	printf("\na complex to the power of 2: %lf + %lfi\n", creal(cpow(doubleComplex, 2)), cimag(cpow(doubleComplex, 2)));
	printf("the square root of a complex: %lf + %lfi\n", creal(csqrt(doubleComplex)), cimag(csqrt(doubleComplex)));

	// there are many other functions in the complex library, but I think you got the point,
	// and I'm not math-pilled enough to know what exactly the other ones do. But if you want to know
	// more, access https://en.cppreference.com/w/c/numeric/complex
}



void testCtypeH() {
	char A = 'A';
	char num1 = '1';
	char dot = '.';
	char space = ' ';

	// isalnum() checks if the char is alpha-numeric
	printf("\n\n%c is %salphanumeric\n", dot, isalnum(dot) ? "" : "not ");
	// isalpha() checks if the char is in the alphabet
	printf("%c is %sin the alphabet\n", A, isalpha(A) ? "" : "not ");
	// islower() checks if the char is lowercase
	printf("%c is %slowercase\n", A, islower(A) ? "" : "not ");
	// isupper() checks if the char is uppercase
	printf("%c is %suppercase\n", A, isupper(A) ? "" : "not ");
	// isdigit() checks if the char is a digit
	printf("%c is %sa digit\n", num1, isdigit(num1) ? "" : "not ");
	// isxdigit() checks if the char is a hex digit
	printf("%c is %sa hex digit\n", A, isxdigit(A) ? "" : "not ");
	// iscntrl() checks if the char is a control character
	printf("space is %sa control character\n", iscntrl(space) ? "" : "not ");
	// isgraph() checks if the char has a graphical representation
	printf("%c has %sa graphical representation\n", num1, isgraph(num1) ? "" : "not ");
	// isspace() checks if the char is the space char
	printf("%c is %sthe space character\n", dot, isspace(dot) ? "" : "not ");
	// isblank() checks if the char is the space or tab char
	printf("space is %sa blank character\n", isblank(space) ? "" : "not ");
	// isprint() checks if the char is printable
	printf("%c is %sprintable\n", A, isprint(A) ? "" : "not ");
	// ispunct() checks if the char is a punctuation
	printf("%c is %sa punctuation\n", dot, ispunct(dot) ? "" : "not ");

	char lowercaseD = 'd';
	char uppercaseD = 'D';

	// you can change a lowercase char to uppercase and vice-versa
	printf("\nto lowercase: %c\n", tolower(uppercaseD));
	printf("to uppercase: %c\n", toupper(lowercaseD));
}



void testErrnoH() {
	// this header defines 3 error code macros, each begining with the letter E
	int i = EDOM; // domain error
	int j = EILSEQ; // illegal byte sequence error
	int k = ERANGE; // range error

	printf("\n\nEDOM == %d\n", i);
	printf("EILSEQ == %d\n", j);
	printf("ERANGE == %d\n", k);

	// and also defines a thread-local preprocessor macro that
	// becomes a modifiable variable
	errno = 0;

	// lets create a function that simulates what could happen if you
	// tried to do some math that should give an error
	void doSomeIllegalMath(int x) {
		if(x != 0) {
			printf("your result is %d\n", 727 / x);
		} else {
			errno = EDOM;
			printf("pls dont divide by 0\n");
		}
	}
	
	doSomeIllegalMath(0);

	// this function belongs to the stdio header, but its output
	// depends on the value of errno
	perror("current error");
}

void testFenvH() {
	// this header has a lot that begin with FE_
	// and a lot of functions that begin with fe

	// these macros are flags that indicate whether or not
	// their exceptions have occured.
	// each one is a different power of 2 (except FE_ALL_EXCEPT)
	printf("FE_INVALID = \n\n%d\n", FE_INVALID);
	printf("FE_DIVBYZERO = %d\n", FE_DIVBYZERO);
	printf("FE_OVERFLOW = %d\n", FE_OVERFLOW);
	printf("FE_UNDERFLOW = %d\n", FE_UNDERFLOW);
	printf("FE_INEXACT = %d\n", FE_INEXACT);
	printf("FE_ALL_EXCEPT = %d\n", FE_ALL_EXCEPT);

	// lets clear our flags before we start experimenting
	feclearexcept(FE_ALL_EXCEPT);

	// and now lets check if our exceptions are cleared with fetestexcept()
	printf("\n%s\n", fetestexcept(FE_ALL_EXCEPT) ? "NOT CLEARED\n" : "CLEARED\n");

	// now do a lot of illegal math to activate some exception flags
	printf("doing bad math\n");
	double i = 1.0 / 0.0; // raising the FE_DIVBYZERO flag
	double k = DBL_MAX * 10.0; // raising the FE_OVERFLOW flag
	double j = 0.1 / 100000.0; // raising the FE_INEXACT flag

	// and check again for each exception:
	printf("%s", fetestexcept(FE_INVALID) ? "\nINVALID flag is up\n" : "");
	printf("%s", fetestexcept(FE_DIVBYZERO) ? "DIVBYZERO flag is up\n" : "");
	printf("%s", fetestexcept(FE_OVERFLOW) ? "OVERFLOW flag is up\n" : "");
	printf("%s", fetestexcept(FE_UNDERFLOW) ? "UNDERFLOW flag is up\n" : "");
	printf("%s", fetestexcept(FE_INEXACT) ? "INEXACT flag is up\n" : "");

	/* you can also choose the rounding method your program
	/  will use to one of these four:
	/  - FE_TONEAREST
	/  - FE_TOWARDZERO
	/  - FE_UPWARD
	/  - FE_DOWNWARD
	/  lets see how each one acts                        */

	float roundingNightmare = 1.5;
	fesetround(FE_TONEAREST);
	printf("\n1.5 to nearest: %.1f\n", rint(roundingNightmare));
	fesetround(FE_TOWARDZERO);
	printf("1.5 towards zero: %.1f\n", rint(roundingNightmare));
	fesetround(FE_UPWARD);
	printf("1.5 upwards: %.1f\n", rint(roundingNightmare));
	fesetround(FE_DOWNWARD);
	printf("1.5 downwards: %.1f\n", rint(roundingNightmare));

	// there's more to see in this header, but its too niche for my taste
}

void testFloatH() {
	// this header only has a bunch of macros representing float limits
	printf("\n\nFLT_DECIMAL_DIG = %d\n", FLT_DECIMAL_DIG); // precision of a float in decimal digits
	printf("FLT_RADIX = %d\n", FLT_RADIX); // the numerical base used to represent all float types
	printf("FLT_MIN = %e\n", FLT_MIN); // the smallest number a float can represent
	printf("FLT_TRUE_MIN = %e\n", FLT_TRUE_MIN); // the true smallest number a float can represent
	printf("FLT_MAX = %e\n", FLT_MAX); // the largest number a float can represent
	printf("FLT_EPSILON = %.15f\n", FLT_EPSILON); // the difference between 1.0 and the next representable float
	printf("FLT_DIG = %d\n", FLT_DIG); // amount of decimal digits preserved when converting to text and back
	printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG); // number of digits in the mantissa that maintain precision
}



void testIntTypesH() {
	// this header contains macros for the printf and scanf family functions formating
	// for example the %d, %i and etc.
	int integer = 1000;
	int octal = 0777;
	int hexadecimal = 0xFFF;
	printf("decimal formatting: \n\n%"PRId8"\n", integer); // PRId32 -> d
	printf("octal formatting: %"PRIo32"\n", octal); // PRIo32 -> o
	printf("hexadecimal formatting: %"PRIx32"\n", hexadecimal); // PRIx32 -> x

	scanf("%"SCNd32, &integer); // SCNd32 -> d
	scanf("%"SCNo32, &octal); // SCNo32 -> o
	scanf("%"SCNx32, &hexadecimal); // SCNx32 -> x

	// there are many more macros, for every formating involving integers
	// and for every integer size, but you got the point.
	// I don't really know if there is any situation in which using these macros
	// is better than writing %d or %o and so on.
}

void testISO646H() {
	// this header has macros that offer alternative representations
	// to operators that aren't in the ISO646:1983 character set
	int zero = 0;
	int one = 1;
	int anyNum = 15;

	// not -> !
	// and -> &&
	if((not zero) and one) {
		printf("\n\n!0 && 1\n");
	}
	// or -> ||
	if(zero or one) {
		printf("0 || 1\n");
	}

	printf("0 | 1 = %d\n", zero bitor one); // bitor -> |
	printf("0 & 1 = %d\n", zero bitand one); // bitand -> &
	printf("%d ^ 1 = %d\n", anyNum, anyNum xor one); // xor -> ^
	printf("~%d = %d\n", anyNum, compl anyNum); // compl -> ~
	// other operator macros:
	// and_eq -> &= 
	// or_eq -> |=
	// xor_eq -> ^=
	// not_eq -> !=

	// there are also macros that replace }, {, [, ] and #
	int array<:2:> = {3, 2}; // <: becomes [ and :> becomes ]
	%:define message "HELLO THERE!\n" // %: becomes #
	if(array<:0:> == 3) <% // <% becomes {
		printf(message);
	%> // %> becomes }
}

void testLimitsH() {
	// a bunch of macros containing the bit size of some types
	// and the max and min limits of integer types (such as short int and long int)
	printf("\n\nCHAR_BIT = %d\n", CHAR_BIT); // how big is a char in bits
	printf("MB_LEN_MAX = %d\n\n", MB_LEN_MAX); // how many bytes can a multibyte char have
	
	printf("CHAR_MIN = %+d\n", CHAR_MIN); // minimum value of a char
	printf("CHAR_MAX = %+d\n", CHAR_MAX); // maximum value of a char
	printf("SCHAR_MIN = %+d\n", SCHAR_MIN); // minimun value of a signed char
	printf("SCHAR_MAX = %+d\n", SCHAR_MAX); //  maximum value of a signed char
	printf("UCHAR_MAX = %u\n\n", UCHAR_MAX); // maximun value of an unsigned char
	
	printf("SHRT_MIN = %+d\n", SHRT_MIN); // minimum value of a short int
	printf("SHRT_MAX = %+d\n", SHRT_MAX); // maximun value of a short int
	printf("USHRT_MAX = %u\n\n", USHRT_MAX); // maximun value of an unsigned short int
	
	printf("INT_MIN = %+d\n", INT_MIN); // minimum value of an int
	printf("INT_MAX = %+d\n", INT_MAX); // maximun value of an int
	printf("UINT_MAX = %u\n\n", UINT_MAX); // maximun value of an unsigned int
	
	printf("LONG_MIN = %+ld\n", LONG_MIN); // minimum value of a long int
	printf("LONG_MAX = %+ld\n", LONG_MAX); // maximun value of a long int
	printf("ULONG_MAX = %lu\n\n", ULONG_MAX); // maximun value of an unsigned long int
	
	printf("LLONG_MIN = %+lld\n", LLONG_MIN); // minimum value of a long long int
	printf("LLONG_MAX = %+lld\n", LLONG_MAX); // maximun value of a long long int
	printf("ULLONG_MAX = %llu\n\n", ULLONG_MAX); // maximun value of an unsigned long long int
}

void testLocaleH() {
	// Basically this header lets you change the locale of your program,
	// including the character set, the decimal separating symbol and the currency.

	// In most cases you will simply do the following to set the locale to the OS one
	setlocale(LC_ALL, "");
	printf("current locale: %s\n", setlocale(LC_ALL, NULL));
}

void testMathH() {
	// As the name sugests, this header contains a lot of usefull math functions

	int a = 3;
	int b = -5;
	double c = 1.25;
	double d = 4.999999;
	double e = 10.0;
	float f = 2.5;
	float g = 8.0;

	// absolute value
	printf("\n\nabsolute value of %d: %d\n", b, abs(b));
	// division: returns the quotient and the remainder
	printf("%d/%d is equal to %d and the remainder is %d\n", b, a, div(b, a).quot, div(b, a).rem);
	// calculates the remainder of a floating point division
	printf("the remainder of %.1f/%.1f is %.1f\n", g, f, remainder(g, f));
	// calculates (a * b) + c
	printf("%lf * %lf + %lf = %lf\n", c, d, e, fma(c, d, e));
	// get the bigger float
	printf("the bigger foat is: %f\n", fmax(f, g));
	// get the smaller float
	printf("the smaller float is: %f\n", fmin(f, g));
	// get the difference between two floats (or 0 if the first is smaller than the second)
	printf("the difference between %f and %f is %f\n", g, f, fdim(g, f));
	// get NaN (not a number)
	printf("%f\n", nan("2"));
	// exponential (in base e and 2)
	printf("e^%d = %f\n", a, exp(a));
	printf("2^%d = %f\n", b, exp2(b));
	// logarithms (in base e, 2 and 10)
	printf("ln(%d) = %f\n", a, log(a));
	printf("log2(%d) = %f\n", a, log2(a));
	printf("log10(%d) = %f\n", a, log10(a));
	// power function (x^y)
	printf("%d^%d = %f\n", b, a, pow(b, a));
	// square root and cubic root
	printf("square root of %d = %f\n", a, sqrt(a));
	printf("cubic root of %d = %f\n", a, cbrt(a));
	// trigonometric functions
	printf("sine of %d = %f\n", a, sin(a));
	printf("cosine of %d = %f\n", a, cos(a));
	printf("tangent of %d = %f\n", a, tan(a));
	// floor and ceil functions
	printf("the floor of %.2f is %.1f\n", c, floor(c));
	printf("the ceiling of %.2f is %.1f\n", c, ceil(c));
	// INFINITY macro
	printf("infinity = %f\n", INFINITY);
	printf("%.1lf < %f = %s\n", pow(2, 64), INFINITY, pow(2, 64) < INFINITY ? "true" : "false");

}

void testSetjmpH() {
	// this header allows you to save stack in a certain moment
	// with setjpm() and then jump to that state with longjmp()
	jmp_buf presentBuffer;

	void travelToThePast(int i) {
		printf("we are in the past %d\n", i);
		// go back to the future
		puts("going back to the future...");
		longjmp(presentBuffer, i + 1);
	}

	int i = setjmp(presentBuffer);
	printf("we are in the present %d\n", i);
	if(i < 6) {
		puts("traveling back to the past!!!");
		travelToThePast(i);
	}
}