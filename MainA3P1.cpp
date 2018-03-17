//File name:	MainA3P1.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work;
//				and I am willing to accept whatever penalty given to me and also to all
//				the related parties involved
#include "A3P1.h"

void line ();	// Prints a line

int main ()
{
	int row, col, n;
	char option;
	
	srand(time (NULL));
	
	do
	{
		cout<<"Matrix Calculator"<<endl<<endl
			<<"Here are some of the options"<<endl
			<<"1. An example"<<endl
			<<"2. Properties of square matrix"<<endl
			<<"3. Matrices operations"<<endl
			<<"9. Quit"<<endl
			<<"Your option: ";
			
		cin>>option;
		cout<<endl;
		
		switch (option)
		{
			case '1':	do
						{	
							line ();
							cout<<"An example of matrix"<<endl<<endl;
							cout<<"Enter the number of rows: ";
							cin>>row;
							
							cout<<"Enter the number of columns: ";
							cin>>col;
							
							cout<<endl<<"Matrix is"<<endl<<endl;
							
							Matrix m (row, col);
							m.printMatrix ();
							
							cout<<endl<<"See more examples (Y/N)?: ";
							cin>>option;
							
							if (option != 'N' && option != 'n' &&
								option != 'Y' && option != 'y')
							{
								cout<<"Invalid option!"<<endl;
								option = 'n';
							}
								
							line ();
							
						}while (option != 'N' && option != 'n');
						
						break;
						
			case '2':	{
							line ();
							cout<<"Here are some of the properties of square matrix"<<endl
								<<endl<<"Enter the order of n of n x n matrix: ";
							cin>>row;
							
							Matrix m (row, row);
							
							cout<<endl<<"Here is the square matrix"<<endl<<endl;
							m.printMatrix ();
							cout<<endl;
							
							do
							{
								cout<<"Wish to see some special matrices"<<endl<<endl
									<<"1. Diagonal matrix"<<endl
									<<"2. Lower triangular matrix"<<endl
									<<"3. Upper triangylar matrix"<<endl
									<<"4. Transpose of a matrix"<<endl
									<<"9. Not interested"<<endl<<endl
									<<"Your choice: ";
								cin>>option;
								
								cout<<endl;
								
								switch (option)
								{
									case '1':	cout<<"diagonal matrix extracted"
													<<endl<<endl;
												m.diagonalM ();
												break;
												
									case '2':	cout<<"Here is the lower triangle "
													<<"matrix extracted"<<endl<<endl;
												m.lowerTriangleM ();
												break;
												
									case '3':	cout<<"Here is the upper triangle "
													<<"matrix extracted"<<endl<<endl;
												m.upperTriangleM ();
												break;
												
									case '4':	cout<<"Given matrix"<<endl<<endl;
												m.printMatrix ();
												
												cout<<endl
													<<"The transpose of the matrix is"
													<<endl<<endl;
													
												m.transposeM ();
												m.printMatrix ();
												break;
												
									case '9':	break;
									
									default:	cout<<"Invalid option!"<<endl;
								}
								
								line ();
								
							}while (option != '9');
							
							option = 1;	//	 Prevents premature exit from the main menu
							
						}
						
						break;
		
			case '3':	do
						{
							line ();
							cout<<"Here are some of the matrix operations"<<endl<<endl
								<<"1. Addition"<<endl
								<<"2. Subtraction"<<endl
								<<"3. Multiplication"<<endl
								<<"4. Scalar multiplication"<<endl
								<<"5. Equality"<<endl
								<<"9. Quit"<<endl<<endl
								<<"Your choice: ";
							cin>>option;
							
							cout<<endl;
							
							switch (option)
							{
								case '1':	{
												cout<<"For addition, two matrices must "
													<<"have the same size"<<endl
													<<"Enter the number of rows and columns: ";
												cin>>row>>col;
												
												Matrix mA (row, col);
												Matrix mB (row, col);
												
												cout<<"Given matrix A"<<endl<<endl;
												mA.printMatrix ();
												
												cout<<endl<<"and matrix B"<<endl<<endl;
												mB.printMatrix ();
												
												cout<<endl<<"A + B is"<<endl<<endl;
												
												mA.addMatrix (mB);
												mA.printMatrix ();
												
												line ();
											}
											break;
											
								case '2':	{
												cout<<"For subtraction, two matrices must "
													<<"have the same size"<<endl
													<<"Enter the number of rows and columns: ";
												cin>>row>>col;
												
												Matrix mA (row, col);
												Matrix mB (row, col);
												
												cout<<"Given matrix A"<<endl<<endl;
												mA.printMatrix ();
												
												cout<<endl<<"and matrix B"<<endl<<endl;
												mB.printMatrix ();
												
												cout<<endl<<"A - B is"<<endl<<endl;
												
												mA.minusMatrix (mB);
												mA.printMatrix ();
												
												line ();
											}
											break;
											
								case '3':	{
												cout<<"For multiplication, the number of rows "
													<<"of the 2nd matrix"<<endl
													<<"must be the same as the number of "
													<<"columns of the 1st matrix"
													<<endl<<endl
													<<"Enter the number of rows of the 1st "
													<<"matrix: ";
												cin>>row;
												
												cout<<"Enter the number of columns of the 1st "
													<<"matrix: ";
												cin>>col;
												
												Matrix mA (row, col);
												
												cout<<"Enter the number of columns of the 2nd "
													<<"matrix: ";
												row = col;
												cin>>col;
												
												Matrix mB(row, col);
												
												cout<<"Given matrix A"<<endl<<endl;
												mA.printMatrix ();
												
												cout<<endl<<"and matrix B"<<endl<<endl;
												mB.printMatrix ();
												
												cout<<endl<<"A * B is"<<endl<<endl;
												
												Matrix mC = mA.multiplyMatrix (mB);
												mC.printMatrix ();
												line ();
											}
											break;
											
								case '4':	{
												cout<<"Scalar multiplication"<<endl<<endl
													<<"Enter number of rows: ";
												cin>>row;
												
												cout<<"Enter number of columns: ";
												cin>>col;
												
												cout<<endl;
												
												Matrix m (row, col);
												
												cout<<"Given matrix"<<endl<<endl;
												m.printMatrix ();
												
												cout<<endl<<"Enter an integer: ";
												cin>>n;
												
												cout<<endl<<"matrix * "<<n<<" is"<<endl<<endl;
												
												m.scalarMultiplyMatrix (n);
												m.printMatrix ();
												
												line ();
											}
											break;
											
								case '5':	{
												cout<<"To check the equality, note that the "
													<<"two matrices must have the same sizes"
													<<endl<<endl
													<<"Enter the number of rows and column: ";
												cin>>row>>col;
												
												Matrix a (row, col);
												
												cout<<"Given matrix A"<<endl<<endl;
												a.printMatrix ();
												
												cout<<endl<<"and matrix B (duplicated from "
													<<"copy constructor)"<<endl<<endl;
													
												Matrix b (a);
												b.printMatrix ();
												
												cout<<endl;
												cout<<(a.equality (b) ? "They are the same" :
														"They are different")<<endl;
												line ();
											}
											break;
											
								case '9':	break;
								
								default:	cout<<"Invalid option!"<<endl;
							}
							
						}while (option != '9');
						
						option = 1;	//	  Prevents premature exit from the main menu
						
						break;
			
			case '9':	break;
			
			default: 	cout<<"Invalid option!"<<endl;
		}
		
		line ();
		
	}while (option != '9');
	
	return 0;
}

// Prints a line
void line ()
{
	cout<<"-----------------------------------------------"<<endl;
}

