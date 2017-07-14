    #include <iostream>
    using namespace std;
     
    void MochilaMaxima(int, int, int[], int[]);
     
    int main() {
    	int N, M;
    	N = 5;//N itens
    	M = 10;//capacidade da mochila
    	int w[N];//peso wi (i - indice)
    	int v[N];//valor vi (i - indice)
     
    	for (int i = 0;i < N; i++) {
    		w[i] = rand()%5;
    		cout << "Peso[" << i << "] = " << w[i] << endl;
    		v[i] = rand()%10;
    		cout << "Valor[" << i << "] = " << v[i] << endl;
    	}
     
    	MochilaMaxima(N, M, w, v);
     
    	return 0;
    }
     
    void MochilaMaxima(int N, int M, int w[], int v[]) {
    	int MM[N][M];
    	bool Escolha[N-1][M-1];
     
    	for (int m = 0; m < M; m++)
    		MM[0][m] = 0;
    	for (int i = 1; i < N; i++)
    		for (int m = 1; m < M; m++) {
    			if (w[i] > m) {
    				MM[i][m] = MM[i-1][m];
    				Escolha[i][m] = false;
    			}
    			else if (MM[i-1][m] > MM[i-1][m-w[i]]+v[i]) {
    					MM[i][m] = MM[i-1][m];
    					Escolha[i][m] = false;
    				}
    			else
    				MM[i][m] = MM[i-1][m-w[i]] + v[i];
    				Escolha[i][m] = true;
    		}
    	int m = M;
    	for (int i = N -1; i > 0; i--)
    		if (Escolha[i][m]) {
    			cout << i << endl;
    			m = m - w[i];
    		}
    }
