#include<stdio.h>
#include<stdlib.h>

int main() {
  int N, i, j, k, l;
  scanf("%d", &N);
  int* array = (int*) malloc((N + 1)*sizeof(int));
  
  *(array) = 0;
  *(array + 1) = 0;
  for(i = 2; i <= N + 1; i++)
    *(array + i) = *(array + i) + 1;
  
  for(i = 2; i <= N + 1; i++) {
    if(*(array + i) == 1) {
      if(*(array + i - 2) == 1)
	printf("%d %d\n", i - 2, i);
      for(j = i + i; j <= N + 1; j = j + i)
	*(array + j) = 0;
    }
  }
  printf("\n");
  
  return 0;
}
