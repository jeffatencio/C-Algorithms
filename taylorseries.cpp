#include <stdio.h>

using namespace std;


double e(int x, int n){

    /*instead of returning for different fuctions pow and fact 
    use static variables
    this implementation has O(n^2) time*/

    static double p = 1 , f = 1;
    double r;

    if(n==0){
        return 1;
    }
    else{
        r = e(x, n-1);
        p = p*x;
        f = f*n;
        return r+p/f;
    }
}


 /*These two implementations use O(n) time*/
double eUsingForLoop(int x, int n){
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for(i= 1; i<=n;i++){
        num *= x;
        den *= i;
        s+= num/den;
    }
    return s; 
}

double eUsingRecursion(int x, int n){
    static double s;

    if(n == 0){
        return s;
    }
    else{
        s = 1 + x*s / n;
        return eUsingRecursion(x, n-1);
    }
}
int main(){

    printf("%lf \n", e(1,10));
    printf("%lf \n", eUsingForLoop(1,10));
    printf("%lf \n", eUsingRecursion(1,10));
    

    return 0;
}