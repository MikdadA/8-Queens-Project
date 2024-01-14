/* Project - 8 Queens 1D array 
*/

#include <iostream>
using namespace std;

int main()
{
	
	int q[8], c = 0;  //each index is representing a column, in that index is the location of the queen and the row its in. 
	q[0] = 0; 	//place the queen in the top left part of the board which means queen is located in row 0 and column 0

	Nextcol:
		c++; //now we are incrementing the column count           
		if(c == 8) goto print; //if column is 8 it means we have found a solution
		q[c] = -1; //to check if there's is no queen 
		
	Nextrow:
		q[c]++; //we are incrementing the value in the index (i.e what row we are in)
		if(q[c] == 8) //a place to put the queen in the column and we have not found the solution 
			goto backtrack; //then we Backtrack
			
	//performing our row test and diagonal tests
	for(int i = 0 ; i < c; i ++) //when q[i] will keep incrementing until is equal to q[c] this is our row test however it will fail the diagonal test
	//abs value in this case is used to perform both up and down diagonal tests 
		if((q[i] ==  q[c]) || ((c-i) == abs(q[c]-q[i]))) //all 3 tests in one line  
			goto Nextrow; //if we happen to fail any of these tests when we go to the nextrow
			
	goto Nextcol; //but if we pass any of these tests that means we place the queen successfully and go to the next row 
//we don't  have to place the queen because we are incrementing the value in the index. 

	backtrack: //we perform backtrack and decrement from the column 
		c--; //we go in the column
	
	if(c == -1) //if the column is less than 0 that means all the possibilities have been checked then we return
		return 0;
		
	goto Nextrow; //otherwise go to the next row
	
	//printing the board
	print:
		static int Solutions = 0; //start the solutions from 1-92
        cout << "Solution #" << ++Solutions << ":\n" ; //increment the solution count when printing  
        
        // using a nested for loop to print 1d to 2d
		for(int i = 0 ; i < 8 ; i++) //to go through the entire 1d array
			{
				for(int j = 0 ; j < c ; j++)               
				{
					if(q[j] != i) //if the array not equal to i 
						cout << 0 << " " ; // then print 0, else 1 
					else
						cout << 1 << " " ;
				}
				cout << endl ;	
			}
		cout << endl ;
		
		goto backtrack ;
}
// end of the code.