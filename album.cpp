    #include <iostream>
    using namespace std;
     
    int MDC(int a, int b) {   
    	if (b == 0) return a;
        else return MDC(b, a % b);
    }
     
    int main() {
    	int n, a, b, c;
     
    	cin >> n;
     
    	while (n--) {
    		cin >> a >> b;
    		c = MDC(a, b);
    		cout << c << endl;
    	}
     
    	return 0;
    }
