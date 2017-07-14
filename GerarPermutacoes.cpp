    #include <iostream>
    using namespace std;
     
    void GerarPermutacoes(int, int, int[]);
    void escrever(int, int[]);
     
    int main() {
    	int U, N;
    	U = 0;
    	N = 3;
    	int Perm[N];
    	for (int i = 0; i < N; i++)
    		Perm[i] = 0;
     
    	GerarPermutacoes(U, N, Perm);
     
    	return 0;
    }
     
    void escrever(int N, int Perm[]) {
    	cout << "[";
    	for (int i = 0; i < N; i++)
    		if (i + 1 != N)
    			cout << Perm[i] << ", ";
    			else
    				cout << Perm[i];
    	cout << "]" << endl;
    }
     
    void GerarPermutacoes(int U, int N, int Perm[]) {
    	if (U == N)
    		escrever(N, Perm);
    	else {
    		for (int i = 0; i < N; i++)
    			if (Perm[i] == 0) {
    				U++;
    				Perm[i] = U;
    				GerarPermutacoes(U, N, Perm);
    				U--;
    				Perm[i] = 0;
    			}
    	}
    }
