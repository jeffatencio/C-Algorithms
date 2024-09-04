#include <stdio.h>

using namespace std;

int pow(int m, int n){
    if(n == 0)
        return 1;

    if(n % 2 == 0)
        return pow(m*m, n/2);
    else
        return m*pow(m*m, (n-1)/2);
}

int main(){

    int result = pow(2,4);
    printf("%d", result);
    return 0;
}
