//File name:	A3P1.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work;
//				and I am willing to accept whatever penalty given to me and also to all
//				the related parties involved
#include "A3P1.h"

Matrix::Matrix ()
{
	// Do nothing
}

// Creates a matrix with number of rows and columns
Matrix::Matrix (int row, int col)
{
	this -> row = row;
	this -> col = col;
	
	initMatrix ();
	generateMatrix ();
}

// Destructor
Matrix::~Matrix ()
{
	static int count = 0; // To count the number of matrices released by the destructor
	count++;
	
	cout<<"Garbage collection - Matrix "<<count<<endl;
	
	for (int i = 0; i < row; i++) // Counts the row of the matrix deleted
	{
		delete [] m [i];
		cout<<"Row "<<i<<" deleted"<<endl;
	}
	
	cout<<"Whole matrix deleted"<<endl;
}

// Copy constructor
Matrix::Matrix (const Matrix& mtx)
{
	row = mtx.row;
	col = mtx.col;
	
	initMatrix ();
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			*map (i, j) = *mtx.map (i, j);
	}
}
			










// Special matrices

// Extract from "this" matrix and display
void Matrix::lowerTriangleM ()
{
	cout<<right;
	
	for (int i = 0; i < row; i++)
	{	 
		for (int j = 0; j < col; j++)
		{
			if (j > i)
				cout<<setw (5)<<'0';
			else
				cout<<setw (5)<<*map (i, j);
		}

		cout<<endl;
	}
}

// Extract from "this" matrix and display
void Matrix::upperTriangleM ()
{
	cout<<right;
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j < i)
				cout<<setw (5)<<'0';
			else
				cout<<setw (5)<<*map (i, j);
		}
			
		cout<<endl;
	}
}

// Extract from "this" matrix and display
void Matrix::diagonalM ()
{
	cout<<right;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout<<setw (5);
			
			if (i != j)
				cout<<'0';
			else
				cout<<*map (i, j);
		}
		cout<<endl;
	}
}






// Changes "this" matrix to its transpose
void Matrix::transposeM ()
{	 
	for (int i = 0; i < row; i++)
	{
		for (int j = i + 1; j < col; j++)
			swap (*map (i, j), *map (j, i));
	}
}


// Operations

// "this" matrix updated
void Matrix::addMatrix (const Matrix& mtx)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			*map (i, j) = *map (i, j) + *mtx.map (i, j);
	}
}

// "this" matrix updated
void Matrix::minusMatrix (const Matrix& mtx)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			*map (i, j) =  *map (i, j) - *mtx.map (i, j);
	}	   
}

// Matrix product returned
Matrix Matrix::multiplyMatrix (const Matrix& mtx)
{	 
	Matrix newMtx (row, mtx.col);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < mtx.col; j++)
		{
			*newMtx.map (i, j) = 0;
			
			for (int k = 0; k < col; k++)
				*newMtx.map (i, j) = *newMtx.map (i, j) + (*map (i, k)) * (*mtx.map (k, j));
		}
	}
	
	return newMtx;
}

// Multiply "this" matrix by a scalar
void Matrix::scalarMultiplyMatrix (int n)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			*map (i, j) = *map (i, j) * n;
	}
}



// Returns true of "this" matrix and matrix mtx are equal, false otherwise
bool Matrix::equality (const Matrix& mtx) const
{	 	 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (*map (i, j) != *mtx.map (i, j))
				return false;
		}
	}
	
	return true;
}

// Prints the matrix
void Matrix::printMatrix ()
{
	for (int i = 0; i < row; i++)
	{
		cout<<"\t[";
		
		for (int j = 0; j < col; j++)
		{
			if (j > 1)
				cout<<right;
			else
				cout<<left;
				
			cout<<setw (5)<<*map (i, j);
		}
		
		cout<<']'<<endl;
	}
}

// Creates a two dimensional array m with number of rows and columns
void Matrix::initMatrix ()
{
	m = new int* [row];
	
	for (int i = 0; i < row; i++)
		m [i] = new int [col];
}

// Fills the matrix with random one digit numbers
void Matrix::generateMatrix ()
{	 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			*map (i, j) = rand() % 10;
	}
}

// Swaps the two integers a and b
void Matrix::swap (int& a, int& b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

// Takes in the position of the integer in the matrix and returns a pointer of the integer
int* Matrix::map (int row, int col) const
{
	int *p = &m [row][0];

	for (int i = 0; i < col; i++)
	{
		p++;
	}

	return p;
}

