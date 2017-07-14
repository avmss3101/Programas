    #include <iostream>
    using namespace std;
     
    void escrever(int, int[]);
    void GerarArranjos(int, int, int, int[], bool[]);
     
    int main() {
    	int N, P, U;
    	N = 3;//N elementos
    	P = 2;//tamanho do arranjo
     
    	int Perm[P];
    	U = 0;
    	for (int i = 0; i < P;i++)
    		Perm[i] = 0;
     
    	bool Usado[N];
    	for (int i = 0; i < N; i++)
    		Usado[i] = false;
     
    	GerarArranjos(N, P, U, Perm, Usado);
     
    	return 0;
    }
     
    void escrever(int N, int Perm[]) {
    	cout << "[";
    	for (int i = 0; i < N; i++)
    		if (i + 1 != N)
    			cout << Perm[i] +1<< ", ";
    			else
    				cout << Perm[i]+1;
    	cout << "]" << endl;
    }
     
    void GerarArranjos(int N, int P, int U, int Perm[], bool Usado[]) {
    	if (U == P)
    		escrever(P, Perm);
    	else
    		for (int i = 0; i < N; i++)
    			if (!Usado[i]) {
    				Perm[U] = i;
    				Usado[i] = true;
    				U++;
    				GerarArranjos(N, P, U, Perm, Usado);
    				U--;
    				Perm[U] = 0;
    				Usado[i] = false;
    			}
    }
