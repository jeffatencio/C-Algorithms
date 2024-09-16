#include <stdio.h>

using namespace std;

int factorial(int n){
    if(n==0)return 1;
    return factorial(n-1)*n;
}

int nCr(int n, int r){
    int num, den;

    num = factorial(n);
    den = factorial(r)*factorial(n-r);
    
    return num/den;

}

int NCR(int n, int r){
    if(n==r || r == 0) 
        return 1;
    return NCR(n-1, r-1)+NCR(n-1,r);

}

int main(){

    printf("%d \n", nCr(5,2));
    printf("%d \n", NCR(4,2));
    return 0;
}