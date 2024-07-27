/*
    n-Queens is the problem of placing N chess queens on N*N chessboard so that no 2 queens attach each other. Today this problems can be solved using different programming algorithms, once the most suitable ones is depth first search. DFS is an algorithm for searching a tree data structure, it selects a single path and explores as far as possible along each branch before backtracking. DFS is often performed to a limited depth due to limited resources. In this program we try to solve this puzzel using C++ language. this game is designed so that no queen can attack other queen horizontly, vertially or digonally.

*/
#include <algorithm>
#include <array>
#include <iostream>
#include <stdio.h>
#include <vector>

using std::cout;
using std::endl;

// defining chessboard size and the number of queens to position
#define N 4
#define SPACE " "
#define LINE "|"
#define NEW_ROW "---------"

/*This function prints out the queen locations*/
void print_grid(int x[], int y[]) {
  for (int i = 0; i < N; i++) {
    cout << SPACE << endl;
    cout << NEW_ROW << endl;
    for (int j = 0; j < N; j++) {

      if (x[i] == i && y[i] == j) {
        cout << 'Q';
      } else {
        cout << SPACE;
      }

      cout << LINE;
    }
  }
  cout << endl << NEW_ROW << endl;
}

/* This function findes if there is a queen in the row of interest, Returns 0
(false) if haven't been used in the row and 1 (true) if it has been used in that row.*/

int used_in_row(int row, int x[]) {
  // for every single column
  for (int col = 0; col < N; col++) {
    if (x[col] == row) {
      // there is a queen in this row
      return 1;
    }
  }
  return 0;
}

/* This function findes if there is a queen in the coloumn of interest, Returns
0 (false) if haven't been used in the column and 1 (true) if it has been used in that column.*/

int used_in_col(int col, int y[]) {
  // for every single row
  for (int row = 0; row < N; row++) {
    if (y[row] == col) {
      // there is a queen in this column
      return 1;
    }
  }
  return 0;
}

/* This function finds if there is a queen in the diagonal of interest. Returns
 0 (false) if haven't been used in the diagonal and 1 (true) if it has been
 used in that diagonal.*/


int used_in_diagonalL(int row, int col, int x[], int y[])
{
  // going diagonally down increases both row and col no.
	for(int i = row, j = col; i < N, j < N; i++, j++)
	{
    // check every queen's location
		for(int k =0; k < N; k++)
		{
			if(x[k] == i && y[k] == j)
			{
				return 1;
			}
		}
	} 
  // going diagonally up reduces both row and col no.
	for(int i = row, j = col; i >= 0, j >= 0; i--, j--)
	{
		for(int k =0; k < N; k++)
		{
			if(x[k] == i && y[k] == j)
			{
				return 1;
			}
		}
	}
	return 0;
}



/* This function finds if there is a queen in the diagonal of interest. Returns 0 (false) if haven't been used in the diagonal and 1 (true) if it has been used in that diagonal. */

int used_in_diagonalR(int row, int col, int x[], int y[]){
  for (int i = row, j = col; i >= 0, j < N; i--, j++) {
    for (int k = 0; k < N; k++) {
      if (x[k] == i && y[k] == j) {
        return 1;
      }
    }
  }
  // down
  for (int i = row, j = col; i < N, j >= 0; i++, j--) {
    for (int k = 0; k < N; k++) {
      if (x[k] == i && y[k] == j) {
        return 1;
      }
    }
  }
  return 0;
}

/* This function calls used_in_row, used_in_col, used_in_diagonalL, and used_in_diagonalR functions to check if all of them return a 0 indicating that it is safe to position the new queen in [row, col] location given the current queen locations stored in x[] and y[].*/

int is_safe(int row, int col, int x[], int y[]) {
  return !used_in_row(row, x) && !used_in_col(col, y) &&
         !used_in_diagonalL(row, col, x, y) &&
         !used_in_diagonalR(row, col, x, y);
}

/*This function implements depth first search*/
int nQueenSolver(int queens, int x[], int y[])
{
   /*int queens indicate how many queens are left to position, so check if there is any*/
  if(queens == 0){
	print_grid(x,y);
    return 1;
  } // if all queens have been placed


  for(int i = 0; i < N; i++) {
	  for(int j = 0 ; j < N; j++){
		  if(is_safe(i,j,x,y)){
				x[N - queens] = i;
				y[N - queens] = j;
				queens--;
				if(nQueenSolver(queens,x,y)){
					return 1;
				}
				else{
				queens++;
				x[N - queens] = -1;
				y[N - queens] = -1;
				}
		  }
		  
	  }

  }
  return 0;
}

int main(){
  int x[N];
  int y[N];

  for(int i = 0; i < N; i++)
  {
    x[i] = -1;
    y[i] = -1;
  }
//Calling DFS function: if(nQueenSolver(queens, x, y)).
  
	if(nQueenSolver(N,x,y)==false){
    cout << "No solution exists for the given N-queens puzzel";
  }
  return 0;
}

 