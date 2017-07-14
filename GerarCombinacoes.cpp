    #include <iostream>
    using namespace std;
     
    void GerarCombinacoes (int, int, int, int[]);
    void escrever(int, int[]);
     
    int main() {
    	int N, P, U;
    	cin >> N;//N elementos
    	cin >> P;//tamanho do arranjo
     
    	U = 0;
    	int Perm[P];
    	for (int i = 0; i < P; i++)
    		Perm[i] = 0;
     
    	GerarCombinacoes(N, P, U, Perm);
     
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
     
    void GerarCombinacoes (int N, int P, int U, int Perm[]) {
    	if (N - Perm[U] >= P - U) {
    		if (U == P)
    			escrever (P, Perm);
    		else
    			for (int i = Perm[U]; i < N; i++) {
    				Perm[U] = i;
    				U++;
    				GerarCombinacoes(N, P, U, Perm);
    				U--;
    				Perm[U] = 0;
    			}
    	}
    }
