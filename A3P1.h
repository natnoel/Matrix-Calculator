//File name:	A3P1.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work;
//				and I am willing to accept whatever penalty given to me and also to all
//				the related parties involved
#include <iostream>
#include <new>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Matrix
{
	public:
			Matrix ();								// Do nothing
			Matrix (int, int);						// number of rows and columns
			~Matrix ();								// destructor
			Matrix (const Matrix&);					// copy constructor
			
			// Special matrices
			void lowerTriangleM ();					// extract from "this" matrix and display
			void upperTriangleM ();					// extract from "this" matrix and display
			void diagonalM ();						// extract from "this" matrix and display
			void transposeM ();						// changes "this" matrix to its transpose
			
			// Operations
			void addMatrix (const Matrix&);			// "this" matrix updated
			void minusMatrix (const Matrix&);		// "this" matrix updated
			Matrix multiplyMatrix (const Matrix&);	// matrix product returned
			void scalarMultiplyMatrix (int);		// multiply "this" matrix by a scalar
			bool equality (const Matrix&) const;
			void printMatrix ();
			
	private:
			int row;
			int col;
			
			// a two dimensional array
			int **m;
			
			// Creates a two dimensional array m with number of rows and columns
			void initMatrix ();
			
			// Fills the matrix with random one digit numbers	
			void generateMatrix ();
			
			// Swaps the two integers
			void swap (int&, int&);
			
			// Takes in the position of the integer in the matrix
			// and returns a pointer of the integer	 
			int * map (int, int) const;
};

