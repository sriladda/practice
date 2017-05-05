//http://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/

#include <stdio.h>
#define NA -1

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
 
  printf("\n");
}

void moveToEnd(int mPlusN[], int n) {
  int i, spaces=0;

  for (i = n-1; i >=0; i--, spaces=0 ) {
    while ( i-spaces > 0 && mPlusN[i-spaces] == NA) {
	spaces++;
    }
    if (i - spaces >= 0 && spaces) {
	mPlusN[i] = mPlusN[i-spaces];
	mPlusN[i-spaces] = NA;
    }
  }
  //printArray(mPlusN, n);
}

void merge(int mPlusN[], int total, int N[], int n) {
  int i, j;
  int from_mPlusN = 0;

  for(i =0, j =0; i < total; i++) {
    if(mPlusN[from_mPlusN + spaces] < N[j] ) {
       mPlusN[i] = mPlusN[from_mPlusN + spaces];
       from_mPlusN++;
    } else if ( N[j] < mPlusN[from_mPlusN +spaces]){
       mPlusN[i] = N[j];
       j++;
    }
  }
  printf("i -1 = %d j-1 = %d\n", i-1, j-1);
  if (mPlusN[i-1] < N[j-1]) {
     mPlusN[i-1] = N[j-1];
  }
    printArray(mPlusN, total);
}

int main() {

  int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
  int N[] = {5, 7, 9, 25};
  int n = sizeof(N)/sizeof(N[0]);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
 
  /*Move the m elements at the end of mPlusN*/
  printArray(mPlusN, m+n);
  moveToEnd(mPlusN, m+n);
  merge(mPlusN, m+n, N, n);
  return 0;
}
