    #include <iostream>
    #include <math.h>
    #include <stdio.h>
     
    #define PI acos(-1);
     
    using namespace std;
     
    int main() {
     
    	double r1, r2, r3;
    	int n;
    	cin >> n;
     
    	while (n--) {
    		cin >> r1; 
    		cin >> r2; 
    		cin >> r3;
    		double p, l1, l2, l3;
    		double A, a1, a2, a3, ang1, ang2, ang3;
     
    		l1 = r2 + r3;
    		l2 = r1 + r3;
    		l3 = r1 + r2;
    		p = (l1 + l2 + l3)/2;
    		A = sqrt(p*(p - l1)*(p - l2)*(p - l3));
    		ang1 = acos((l2*l2 + l3*l3 - l1*l1)/(2*l2*l3));
    		ang2 = acos((l1*l1 + l3*l3 - l2*l2)/(2*l1*l3));
    		ang3 = acos((l2*l2 + l1*l1 - l3*l3)/(2*l2*l1));
     
    		a1 = r1*r1*ang1/2.0;
    		a2 = r2*r2*ang2/2.0;
    		a3 = r3*r3*ang3/2.0;
    		double result;
    		result = A - a1 -a2 -a3;
    		printf("%.6f\n", result);
    	}
    	return 0;
    }
