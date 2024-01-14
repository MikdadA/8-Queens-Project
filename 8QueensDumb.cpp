/** 
 * Project - 8 dumb queens 1D
 * */


#include <iostream>
using namespace std;
//pass the array 
bool okay(int q[8]){ //check all queens in 8 columns to make sure there is no conflict 
    for (int c=0; c<8; c++){  // nested for loop 
        for (int i=0; i<c; i++){ // we perform our row test and diagonal tests (up and down)
    //q[i] will keep incrementing until is equal to q[c] this is our row test however it will fail the diagonal test
    // abs value is used in this case to perform both up and down diagonal test
            if (c-i==abs(q[c]-q[i]) || q[c]==q[i]) //all 3 tests in one shot
                return false; // if it fail any of the tests
        }
   }
    return true; // if it passes all the tests and exit for loop 
}

void print(int q[], int solutions){
    cout << "\nSolution #: " << solutions << endl; // print the solution count 
    cout << "Configuration: "; //this prints the solution in 1d array 
    for (int i=0; i<8; i++) // the number of times it goes through every single iteration
        cout << q[i]; 
            cout << endl;
    int r=0;
    while (r<8){
        for (int i=0; i<8; i++){ // priting the board 
            if (r==q[i]) //the array will keep incrementing in the for loop until the row is equal to the array in the index.
                         cout << "1"; // it will print 1 if not then 0
                else     
                         cout << "0";
        }
        cout << endl;
        r++; // goes to the next row
    }
}

int main() {
	int q[8] = {0}; //set board
    int solutions= 0;
/**
 * Idea: 
 * we have series of nested for loops to traverse each column
 * there is a outermost loop, basically we will have a bunch of for loops from 0 to 7 
 * there's also going to be a value this is being incremented on for each of the for loops
 * for example, for loop 0 the value will assign to q[0] and soon. 
 * Every loop will be assigned a value of 0 and the very last for loop will be 0 then it will keep incrementing till it hits 7.
 * next innermost loop will finally be incremented to 1 and then we will loop though the outerloop.      
**/
       for(int i0=0;i0<8;i0++) 
        for(int i1=0;i1<8;i1++) 
            for(int i2=0;i2<8;i2++)
                for(int i3=0;i3<8;i3++)
                    for(int i4=0;i4<8;i4++)
                        for(int i5=0;i5<8;i5++)
                            for(int i6=0;i6<8;i6++)
                                for(int i7=0;i7<8;i7++){
                                    // now assigning the values to the q array usign the values from the for loops
                                     q[0]=i0; //corresponds to the value of 0
                                     q[1]=i1; //corresponds to the value of 1
                                     q[2]=i2; //corresponds to the value of 2
                                     q[3]=i3; //corresponds to the value of 3
                                     q[4]=i4; //corresponds to the value of 4
                                     q[5]=i5; //corresponds to the value of 5
                                     q[6]=i6; //corresponds to the value of 6
                                     q[7]=i7; //corresponds to the value of 7
                                      if(okay(q)) //now we pass it to the okay function if this is ok we will then print
                                      print(q, ++solutions); //and increment our solution and pass the value
    }
}
// end of the code