// Author: Alon Firestein

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


// Checking tests that pass for input that I know in advance is valid and legal.
TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n\
													 @-------@\n\
													 @-@@@@@-@\n\
													 @-@---@-@\n\
													 @-@@@@@-@\n\
													 @-------@\n\
													 @@@@@@@@@"));
													 
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n\
													  @-----------@\n\
													  @-@@@@@@@@@-@\n\
													  @-----------@\n\
													  @@@@@@@@@@@@@"));

	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n\
													 $+$\n\
													 $+$\n\
													 $+$\n\
													 $$$"));
													 
	CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));
	
	CHECK(nospaces(mat(5, 5, '!', ',')) == nospaces("!!!!!\n\
													 !,,,!\n\
													 !,!,!\n\
													 !,,,!\n\
													 !!!!!"));

													 
 	CHECK(nospaces(mat(3, 3, '~', '*')) == nospaces("~~~\n\
 												   	 ~*~\n\
													 ~~~"));

}

// ****Test that fail because of bad input***

// Size of column must be even
TEST_CASE("Even column number input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); 
    CHECK_THROWS(mat(4, 5, '!', '$'));
    CHECK_THROWS(mat(12, 3, '&', '@'));
    CHECK_THROWS(mat(6, 6, '^', '$'));
    CHECK_THROWS(mat(2, 11, '@', '('));    
}

// Size of column must be even
TEST_CASE("Even row number input") {
    CHECK_THROWS(mat(13, 6, '$', '%')); 
    CHECK_THROWS(mat(4, 4, '!', '$'));
    CHECK_THROWS(mat(5, 32, '&', '@'));
    CHECK_THROWS(mat(13, 10, '^', '$'));
    CHECK_THROWS(mat(5, 8, '@', '('));    
}

// Size of column must be a positive integer [1, inf]
TEST_CASE("Column data type input test") {
    CHECK_THROWS(mat(-4, 6, '$', '%')); 
    CHECK_THROWS(mat(0, 32, '&', '@'));
    CHECK_THROWS(mat(-10, 10, '^', '$'));
    CHECK_THROWS(mat(0, 4, '!', '?'));
    CHECK_THROWS(mat(-1, 11, '(', '%'));


}

// Size of row must be a positive integer [1, inf]
TEST_CASE("Row data type input test") {
    CHECK_THROWS(mat(4, -6, '$', '%')); 
    CHECK_THROWS(mat(10, 0, '&', '@'));
    CHECK_THROWS(mat(10, -10, '^', '$'));
    CHECK_THROWS(mat(4, 0, '!', '?'));
    CHECK_THROWS(mat(11, -1, '(', '%'));
}

/*
Testing the size of the mat (amount of characters it took to build)
Given that the mat is a rectangle shape, and made out of two different symbols.
To find the number of symbols that make up the mat is similar to finding its area:
height * width = num_of_rows * num_of_columns
*/
TEST_CASE("Valid mat Size") {
    CHECK(nospaces(mat(9, 7, '@', '-')).length() == 9*7);
    CHECK(nospaces(mat(13, 5, '@', '-')).length() == 13*5);
    CHECK(nospaces(mat(3, 3, '~', '*')).length() == 3*3);	
    CHECK(nospaces(mat(1, 1, '#', ')')).length() == 1*1);
	CHECK(nospaces(mat(5, 5, '!', '?')).length() == 5*5);
}




