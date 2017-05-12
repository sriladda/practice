//http://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
#include <stdio.h>

#define COL_SIZE 4

// Function to print the matrix
void displayMatrix(int mat[][COL_SIZE], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);
 
        printf("\n");
    }
    printf("\n");
}

void rotateMatrix(int mat[][COL_SIZE], int N)
{
   int row, col, temp1, temp2, temp3;

   for(row = 0; row < N/2; row++)
   {
      for(col = row; col < N-row-1; col++)
      { 
         temp1 = mat[row][col]; //00 saved in temp1, 01 saved
         mat[row][col] = mat[col][N-1-row]; //03 copied to 00
         temp2 = mat[N-1-col][row]; // 30 saved in temp2
         mat[N-1-col][row] = temp1; //temp1 copied to 30
         temp3 = mat[N-1-row][N-1-col]; // 33 saved in temp3 
         mat[N-1-row][N-1-col] = temp2; // temp2 copied to 33
         mat[col][N-1-row] = temp3; // temp3 copied to 03
         //displayMatrix(mat, COL_SIZE);
      }
      //displayMatrix(mat, COL_SIZE);
   }
}

/* Driver program to test above functions */
int main()
{
    // Test Case 1
     int mat[][COL_SIZE] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    }; 
 
 
    // Tese Case 2
     /*int mat[][COL_SIZE] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    }; */
     
 
    // Tese Case 3
    /*int mat[COL_SIZE][COL_SIZE] = {
                    {1, 2},
                    {4, 5}
                }; */
 
    displayMatrix(mat, COL_SIZE);
 
    rotateMatrix(mat, COL_SIZE);
 
    // Print rotated matrix
    displayMatrix(mat, COL_SIZE);
 
    return 0;
}
