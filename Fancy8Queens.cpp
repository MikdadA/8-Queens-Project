#include <iostream>
#include <cmath>
using namespace std;

// Check if it's safe to place a queen in the current column 'c'
bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

// Print the chessboard with queens positioned based on the current solution
void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // Define a box as a 5x7 2D array of characters
   box bb, wb, *board[8][8]; // bb and wb are boxes. board is an 8x8 array of pointers to boxes.

   // Fill in bb (black box) and wb (white box)
   for (i=0; i<5; i++)
      for (j=0; j<7; j++) {
         bb[i][j] = ' ';
         wb[i][j] = char(219);
      }
   
   // Create 2 more boxes to represent the queens
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   // Fill board with pointers to bb and wb in alternate positions
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;
   
   // Set up the current solution on the chessboard
   for(i=0; i<8; i++)
      if((i+q[i])%2 == 0)
         board[q[i]][i] = &bq;
      else
         board[q[i]][i] = &wq;

   cout << "Solution #" << ++solution << ":\n ";
   
   // Print upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Print the board
   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << char(179);
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   // Print lower border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}

// Recursive function to find and print all solutions
void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 0; q[c] < 8; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}
