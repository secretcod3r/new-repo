// @author: Alon Firestein

#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
using namespace std;


// Function to return the created mat for the factory :)
string mat(int col, int row, char symbol_a, char symbol_b) {
	// Initalizing indexes for use later in the loops
	int i, row_counter = 0, col_counter = 0;
	// Creating a copy of the row,col value for creating the final mat
	int row_copy = row, col_copy = col;
	// Initializing a 2D array to serve as the mat we are creating for the factory
	char mat[row][col];
	// The symbols are alternating, so we start we the first symbol to alternate them every "round"
	char current_symbol = symbol_a;
	while (row_counter < row && col_counter < col) {
		// Filling the top row each time
		for (i = col_counter; i < col; ++i) {
		    mat[row_counter][i] = current_symbol;
		}
		row_counter++;
	 
		// Filling the right-side col each time
		for (i = row_counter; i < row; ++i) {
		    mat[i][col-1] = current_symbol;
		}
		col--;
	 
		// Filling the bottom row each time
		if (row_counter < row) {
		    for (i = col-1; i >= col_counter; --i) {
		        mat[row-1][i] = current_symbol;
		    }
		    row--;
		}
	 
		// Filling the left-side col each time
		if (col_counter < col) {
		    for (i = row-1; i >= row_counter; --i) {
		        mat[i][col_counter] = current_symbol;
		    }
		    col_counter++;
		}
	 
		// Checking the current symbol, and flipping it for the next iteration of the mat creation.
		if (current_symbol == symbol_a) {
			current_symbol = symbol_b;
		} 
		else {
			current_symbol = symbol_a;
		}

    	}

	string result = "";
	// Print the filled matrix
   	for (i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
            		result += (' ' + mat[i][j]);
            	}
        	result += "\n";
        }
	return result;

}


//Checking and approving the input
int input_check(int col, int row, char symbol_a, char symbol_b) {
    if (col < 0 || row < 0) {
    	return 0;
    }
    if (!isalnum(symbol_a) || !isalnum(symbol_b)) {
    	return 0;
    }

    return 1; // Input is OKAY!
}


namespace ariel {
	string mat(int col, int row, char symbol_a, char symbol_b) {
        //if (input_check(col, row, symbol_a, symbol_b) != 0) {
        	return mat(col, row, symbol_a, symbol_b);
        //}
        //throw std::invalid_argument("ERROR: Invalid input to print mat!");
        
    }
}

