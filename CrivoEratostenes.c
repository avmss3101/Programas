#include<stdio.h>
#include<stdlib.h>

int main() {
  int N, i, j, k, l;
  scanf("%d", &N);
  int* array = (int*) malloc(N*sizeof(int));
  
  *(array) = 0;
  *(array + 1) = 0;
  for(i = 2; i <= N; i++)
    *(array + i) = *(array + i) + 1;
  
  for(i = 2; i <= N; i++) {
    if(*(array + i) == 1) {
      printf("%d ", i);
      for(j = i + i; j <= N; j = j + i)
	*(array + j) = 0;
    }
  }
  printf("\n");
  
  return 0;
}
