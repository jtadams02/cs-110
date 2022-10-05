#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols)
{
   int **matrix = (int**)malloc(numRows*(sizeof(int *)));
   for(int i=0;i<numRows;i++)
   {
      matrix[i] = (int *)malloc(numCols*sizeof(int));
   }
   return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols)
{
   for(int i=0;i<numRows;i++)
   {
      int* row = matrix[i];
      free(row);
   }
   free(matrix);
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
   int x;
   for(int i=0;i<numRows;i++)
   {
      for(int j=0;j<numCols;j++)
      {
         fscanf(fp,"%d",&x);
         matrix[i][j] = x;
      }

   }
   fclose(fp);
}

void printMatrix(int **matrix, int numRows, int numCols)
{
   for(int i=0;i<numRows;i++)
   {
      for(int j=0;j<numCols;j++)
      {
         printf("%d ",matrix[i][j]);
      }
      printf("\n");
   }
}

int rangeRow(int **matrix, int numRows, int numCols, int r)
{
   int max=-999;
   int mini=999;
   int range = 0;
   for(int i=0;i<numCols;i++)
   {
      if(matrix[r][i]<mini)
      { 
         int temp = matrix[r][i];
         mini = matrix[r][i];
         //printf("\nNumber is less: %d.\n",matrix[r][i]);
      }

      if(matrix[r][i]>max)
      {
         int temp = matrix[r][i];
         max = temp;
      }
   }
   range = (max)-(mini);
   return range;
}

void printCorners(int **matrix, int numRows, int numCols)
{
   printf("%d ",matrix[0][0]);
   printf("%d\n",matrix[0][numCols-1]);
   printf("%d ",matrix[numRows-1][0]);
   printf("%d\n",matrix[numRows-1][numCols-1]);
}

int sumSubMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol)
{
   int sum = 0;
   for(int i=startRow;i<=endRow;i++)
   {
      for(int j=startCol;j<=endCol;j++)
      {
         sum += matrix[i][j];
      }
   }
   return sum;
}
