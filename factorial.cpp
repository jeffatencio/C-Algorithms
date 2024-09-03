#include <iostream>
#include <stdio.h>

using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    
    return factorial(n-1) * n;
}

int main(){

    int result = factorial(5);
    printf("%d", result);

    return 0;
}