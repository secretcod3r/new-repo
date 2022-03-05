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
													 
	
	CHECK(nospaces(mat(13, 5, '<', '>')) == nospaces("<<<<<<<<<<<<<\n\
													  <>>>>>>>>>>><\n\
													  <><<<<<<<<<><\n\
													  <>>>>>>>>>>><\n\
													  <<<<<<<<<<<<<"));
													  
  	
  	CHECK(nospaces(mat(5, 5, '(', '@')) == nospaces("(((((\n\
													 (@@@(\n\
													 (@(@(\n\
													 (@@@(\n\
													 ((((("));
													 
	
												
 	CHECK(nospaces(mat(3, 3, '*', '*')) == nospaces("***\n\
 												   	 ***\n\
													 ***"));
	
	
 	CHECK(nospaces(mat(1, 1, ':', '!')) == nospaces(":"));
 	

 	
 	
	CHECK(nospaces(mat(9, 7, '|', '-')) == nospaces("|||||||||\n\
													 |-------|\n\
													 |-|||||-|\n\
													 |-|---|-|\n\
													 |-|||||-|\n\
													 |-------|\n\
													 |||||||||"));												 


		
	
	
	
}



// Checking test cases where that mat is only one long line made of only columns and one row
TEST_CASE("Only Columns Test") {

	CHECK(nospaces(mat(5, 1, '?', '+')) == nospaces("?????"));	
	
	CHECK(nospaces(mat(3, 1, '>', '!')) == nospaces(">>>"));		
	
	CHECK(nospaces(mat(9, 1, '*', '.')) == nospaces("*********"));		
	
	CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));	
	
	CHECK(nospaces(mat(11, 1, '$', '@')) == nospaces("$$$$$$$$$$$"));	
	
	CHECK(nospaces(mat(15, 1, '?', '+')) == nospaces("???????????????"));	


}



// Checking test cases where that mat is only one long line made of only rows and one colums
TEST_CASE("Only Rows Test") {

	CHECK(nospaces(mat(1, 5, '?', '+')) == nospaces("?\n\
													 ?\n\
													 ?\n\
													 ?\n\
													 ?"));
	
	
	CHECK(nospaces(mat(1, 7, '!', '@')) == nospaces("!\n\
													 !\n\
													 !\n\
													 !\n\
 													 !\n\
													 !\n\
													 !"));												


	CHECK(nospaces(mat(1, 11, '$', '#')) == nospaces("$\n\
													  $\n\
													  $\n\
													  $\n\
													  $\n\
													  $\n\
													  $\n\
													  $\n\
													  $\n\
													  $\n\
													  $"));



	CHECK(nospaces(mat(1, 1, ')', '+')) == nospaces(")"));
													 
													 
	CHECK(nospaces(mat(1, 5, '&', '%')) == nospaces("&\n\
													 &\n\
													 &\n\
													 &\n\
													 &"));													 
}




// ****From here, We check tests that will fail because of bad input***



// Size of column must be even
TEST_CASE("Even column number input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); 
    CHECK_THROWS(mat(4, 5, '!', '$'));
    CHECK_THROWS(mat(12, 3, '&', '@'));
    CHECK_THROWS(mat(6, 6, '^', '$'));
    CHECK_THROWS(mat(2, 11, '@', '('));    
    CHECK_THROWS(mat(40, 5, '$', '%')); 
    CHECK_THROWS(mat(14, 5, '!', '$'));
    CHECK_THROWS(mat(2, 3, '&', '@'));
    CHECK_THROWS(mat(16, 6, '^', '$'));
    CHECK_THROWS(mat(24, 11, '@', '('));  
}



// Size of column must be even
TEST_CASE("Even row number input") {
    CHECK_THROWS(mat(13, 6, '$', '%')); 
    CHECK_THROWS(mat(4, 4, '!', '$'));
    CHECK_THROWS(mat(5, 32, '&', '@'));
    CHECK_THROWS(mat(13, 10, '^', '$'));
    CHECK_THROWS(mat(5, 8, '@', '('));    
    CHECK_THROWS(mat(13, 16, '$', '%')); 
    CHECK_THROWS(mat(4, 40, '!', '$'));
    CHECK_THROWS(mat(5, 2, '&', '@'));
    CHECK_THROWS(mat(13, 12, '^', '$'));
    CHECK_THROWS(mat(5, 18, '@', '('));  
}



// Size of column must be a positive integer [1, inf]
TEST_CASE("Column data type input test") {
    CHECK_THROWS(mat(-4, 7, '$', '%')); 
    CHECK_THROWS(mat(0, 1, '&', '@'));
    CHECK_THROWS(mat(-10, 9, '^', '$'));
    CHECK_THROWS(mat(0, 5, '!', '?'));
    CHECK_THROWS(mat(-1, 11, '(', '%'));
    CHECK_THROWS(mat(-14, 5, '$', '%')); 
    CHECK_THROWS(mat(0, 3, '&', '@'));
    CHECK_THROWS(mat(-4, 1, '^', '$'));
    CHECK_THROWS(mat(-5, 7, '!', '?'));
    CHECK_THROWS(mat(-1, 1, '(', '%'));

}



// Size of row must be a positive integer [1, inf]
TEST_CASE("Row data type input test") {
    CHECK_THROWS(mat(5, -7, '$', '%')); 
    CHECK_THROWS(mat(1, 0, '&', '@'));
    CHECK_THROWS(mat(9, -3, '^', '$'));
    CHECK_THROWS(mat(3, 0, '!', '?'));
    CHECK_THROWS(mat(11, -1, '(', '%'));
    CHECK_THROWS(mat(21, -3, '$', '%')); 
    CHECK_THROWS(mat(3, 0, '&', '@'));
    CHECK_THROWS(mat(1, -23, '^', '$'));
    CHECK_THROWS(mat(9, 0, '!', '?'));
    CHECK_THROWS(mat(31, -11, '(', '%'));
}


// Mat should be made out of symbols, not letters or numbers
TEST_CASE("Mat material test") {
    CHECK_THROWS(mat(5, 7, 'a', '%')); 
    CHECK_THROWS(mat(1, 11, '5', '@'));
    CHECK_THROWS(mat(9, 3, 'O', 'K'));
    CHECK_THROWS(mat(3, 5, '!', '2'));
    CHECK_THROWS(mat(5, 9, 'C', '%'));
    CHECK_THROWS(mat(21, 13, 'L', '%')); 
    CHECK_THROWS(mat(3, 5, '&', 'S'));
    CHECK_THROWS(mat(1, 3, '^', '5'));
    CHECK_THROWS(mat(9, 9, '1', '?'));
    CHECK_THROWS(mat(21, 11, '(', 'Z'));
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
    CHECK(nospaces(mat(19, 17, '@', '-')).length() == 19*17);
    CHECK(nospaces(mat(3, 15, '@', '-')).length() == 3*15);
    CHECK(nospaces(mat(13, 3, '~', '*')).length() == 13*3);	
    CHECK(nospaces(mat(5, 9, '#', ')')).length() == 5*9);
	CHECK(nospaces(mat(21, 5, '!', '?')).length() == 21*5);
}



// Checking using a for loop to check 1000 different cases, and creating random numbers to check if the random input is valid or not
TEST_CASE("Random numbers test") {

    for(int i=0 ; i<1000; i++) {
    	int random_col = rand() % 100 +1;
		int random_row = rand() % 100 +1;
		if (random_col%2==0 || random_row%2==0) {
		    CHECK_THROWS(mat(random_col, random_row, '+', '-'));
		}
		else {
			CHECK(nospaces(mat(random_col, random_row, '+', '-')).length() == random_col*random_row);
		}
	}
}




