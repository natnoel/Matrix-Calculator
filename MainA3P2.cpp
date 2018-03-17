//File name:	MainA3P2.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work;
//				and I am willing to accept whatever penalty given to me and also to all
//				the related parties involved
#include "A3P2.h"

void line ();	// Prints a line

int main ()
{
	int row, col;
	char choice;
	
	srand (time (NULL));
	
	do
	{
		cout<<"Here are some of the matrix operations"<<endl<<endl
			<<"1. Addition"<<endl
			<<"2. Equality"<<endl
			<<"9. Quit"<<endl<<endl
			<<"Your choice: ";
			
		cin>>choice;
		
		cout<<endl;
		line ();
		
		switch (choice)
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
			
			default:	cout<<"Invalid choice!"<<endl;
											
		}
		
		line ();
		
	}while (choice != '9');
	
	return 0;
}

// Prints a line
void line ()
{
	cout<<"-----------------------------------------------"<<endl;
}

