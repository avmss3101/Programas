    #include <iostream>
    #include <math.h>
    #include <stdio.h>
    using namespace std;
     
    int main() {
    	double a, b, c;// length, width, hipotenusa
    	double ang, l, k;
    	char inutil;
    	int n;
    	n = 1;
     
    	while(cin >> a >> inutil >> b) {
    		double L, W;
    		c = sqrt(a*a + b*b);
    		c = c/2.0;
    		ang = acos((2.0*c*c - b*b)/(2.0*c*c));
    		//l = ang*c;
    		k = 200.0/(a + ang*c);
    		L = a*k;
    		W = b*k;
     
    		printf("Case %d: %.10f %.10f\n", n, L, W);
    		n++;
    	}
    	return 0;
    }
