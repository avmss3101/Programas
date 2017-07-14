    #include <iostream>
    #include <stdlib.h>
    using namespace std;
     
    void ordena(int*, int);
    void quickSort(int* arr, int, int);
     
    int main() {
    	int n;
    	cin >> n;
     
    	int* age = (int*) malloc(n*sizeof(int));
     
    	while (n != 0) {
    		for (int i = 0; i < n; i++)
    			cin >> *(age + i);
     
    		//ordena(age, n);
    		quickSort(age, 0, n - 1);
     
    		for (int i = 0; i < n - 1; i++)
    			cout << *(age + i) << " ";
    		cout << *(age + n - 1);
    		cout << endl;
     
    		cin >> n;
    	}
     
    	return 0;
    }
     
    void ordena(int* age, int n) {
    	int aux;
    	for (int i = 0; i < n; i++) {
    		for (int j = i; j < n; j++) {
    			if (*(age + i) >= *(age + j)) {
    				aux = *(age + i);
    				*(age + i) = *(age + j);
    				*(age + j) = aux;
    			}
    		}
    	}
    }
     
    void quickSort(int* arr, int left, int right) {
          int i = left, j = right;
          int tmp;
          int pivot = *(arr + (left + right) / 2);
     
          while (i <= j) {
                while (*(arr + i) < pivot)
                      i++;
                while (*(arr + j) > pivot)
                      j--;
                if (i <= j) {
                      tmp = *(arr + i);
                      *(arr + i) = *(arr + j);
                      *(arr + j) = tmp;
                      i++;
                      j--;
                }
          };
     
          if (left < j)
                quickSort(arr, left, j);
          if (i < right)
                quickSort(arr, i, right);
    }
