    #include <iostream>
    #include <stdio.h>
    #include <math.h>
     
    #define PI acos(-1)
     
    using namespace std;
     
    int main() {
    	double a, b, c;
     
    	while (cin >> a >> b >> c) {
    		double at, ac, AC, s, r, R;
    		s = (a + b + c)/2.0;
    		at = sqrt(s*(s - a)*(s - b)*(s - c));
    		r = at/s;
    		R = a*b*c/(4.0*at);
     
    		ac = PI*r*r;
    		AC = PI*R*R;
     
    		double asunf, aviol;
    		asunf = AC - at;
    		aviol = at - ac;
     
    		printf("%.4f %.4f %.4f\n", asunf, aviol, ac);
    	}
    	return 0;
    }
