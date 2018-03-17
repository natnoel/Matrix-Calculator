//File name:	A3P2.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work;
//				and I am willing to accept whatever penalty given to me and also to all
//				the related parties involved
#include <iostream>
#include <new>
#include <iomanip>
#include <cstdlib>
using namespace std;

typedef void* VoidPtr;

class Matrix
{
	public:
			Matrix ();							// Do nothing
			Matrix (int, int);					// Number of rows and columns
			Matrix (const Matrix&);				// Copy constructor
			~Matrix ();							// Destructor
			
			// Operations
			void addMatrix (const Matrix&);		// "this" matrix updated
			bool equality (const Matrix&) const;// Checks if both matrices are equal
			void printMatrix ();				// Prints the matrix
			
	private:
			// Number of rows of the matrix
			int row;
			
			// Number of columns of the matrix
			int col;
			
			// a two dimensional array of void* type
			VoidPtr **m;
			
			// Creates a two dimensional array m with number of rows and columns
			void initMatrix ();
			
			// Fills the matrix with random one digit numbers
			void generateMatrix ();
			
			// Compares two items of void* type
			// Returns 1 if the 1st item > the 2nd item
			// Returns 0 if they are equal
			// Else returns -1
			int compare (VoidPtr, VoidPtr) const;
};

