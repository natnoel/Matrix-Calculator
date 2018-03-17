//File name:	A3P2.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work;
//				and I am willing to accept whatever penalty given to me and also to all
//				the related parties involved
#include "A3P2.h"

Matrix::Matrix ()
{
	// Do nothing
}

// Created a matrix with number of rows and columns
Matrix::Matrix (int row, int col)
{
	this -> row = row;
	this -> col = col;
	
	initMatrix ();
	generateMatrix ();
}

// Copy constructor
Matrix::Matrix (const Matrix& mtx)
{
	int *item;
	
	row = mtx.row;
	col = mtx.col;
	
	initMatrix ();
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			item = new int;
			*item = *(static_cast <int*> (mtx.m [i][j]));
			m [i][j] = item;
		}
	}
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





// Operations

// "this" matrix updated
void Matrix::addMatrix (const Matrix& mtx)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			*(static_cast <int *> (m [i][j])) = *(static_cast <int *> (m [i][j]))
												+ *(static_cast <int *> (mtx.m [i][j]));
	}
}

// Returns true if matrices are equal false otherwise
bool Matrix::equality (const Matrix& mtx) const
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (compare (m [i][j], mtx.m [i][j]))
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
				
			cout<<setw (5)<<*(static_cast <int *> (m[i][j]));
		}
		
		cout<<']'<<endl;
	}
}

// Creates the matrix with number of rows and columns
void Matrix::initMatrix ()
{
	m = new VoidPtr* [row];
	
	for (int i = 0; i < row; i++)
		m [i] = new VoidPtr [col];
}






// Generates random one digit numbers into the matrix
void Matrix::generateMatrix ()
{
	int *item;
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			item = new int;
			*item = rand() % 10;
			m[i][j] = item;
		}
	}
}

// Compare two items of void* type
// Returns 1 if the 1st item > the 2nd item
// Returns 0 if they are equal
// Else returns -1
int Matrix::compare (VoidPtr vp1, VoidPtr vp2) const
{
	int a = *(static_cast <int *> (vp1));
	int b = *(static_cast <int *> (vp2));
	
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}

