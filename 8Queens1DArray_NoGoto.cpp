/** 
 * Project - 8 queens 1D No Goto
 * */

#include <iostream>
using namespace std;

	bool okay(int q[], int col){ //check the queen in column to ensure there is no conflict then return true if the queen in column is okay.
		for(int i=0;i<col;i++){ //for each i from 0 to c-1
			if((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i))) { // if there's a conflict or if it fails any of the test between the queens in columns i and c 
				return false; //then you should return false!
			 }
		 }
			return true; // if it passes all the test, then return true and end the loop
	}

void print(int q[])   //using the print function to print out the board.
{
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n" ;  // print the solution count
   // Print the array
   // I used nested for loops to print 1D to 2D array
   for( int i = 0 ; i < 8 ; i++ ) //for going through whole 1D array
			{
				for( int j = 0 ; j < 8 ; j++ )               
				{
					if( q[j] != i )  // if the array is not equal to i 
						cout << 0 << " " ; // then print 0 
					else     //  // else print 1
						cout << 1 << " " ;
				}
				cout << endl ;	
			}
		cout << endl ;
} // Print function ends here


int main() 
{
   int q[8] = {0} , col = 0 ;  // set the array to 0.
   q[col] = 0 ;  // Start in the 1st row and 1st column
   col++ ; // increment to the next column
   
   // if you backtrack beyond the first column then we have found all solutions 
   while (col > -1) 
   { // if you have moved beyond the last column then we have found all solutions 
      if( col == 8 ) // If you are in the last column or have passed the last column
	  {           
      	 print(q) ;  // then call the print function
      	 col-- ; // and backtrack
	  }
      else
	  	  q[col] = -1 ; // Otherwise, move to one before the first row
      while ( col >= 0 && col < 8 ) 
	  {
         q[col]++ ; // Move to the next row
         if( q[col] == 8 )// If you have passed the end of the column
         		 col-- ; // and then backtrack
         else
         { // check if the queens place is okay 
         	if( okay( q , col ) == true ) // Otherwise, call the okay function.  If it returns true, go back to the beginning of the outer loop.
         		{
				 col++ ; // move to the next column
				 break ;
         		}		
         }
      }
   }
   return 0;
}