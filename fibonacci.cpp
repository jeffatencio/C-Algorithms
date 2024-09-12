#include <stdio.h>

using namespace std;

/*fibonacci using recursion*/

int fib(int n){
    if(n<= 1){
        return n;
    }
    return fib(n-2)+fib(n-1);
}

/*fibonacci using iteration*/
int fibIterative(int n){
    int a = 0;
    int b = 1;
    int s;

    if(n<=1){
        return n;
    }
    for(int i = 2; i <= n; i++){
        s = a+b;
        a = b;
        b = s;
    }
    return s;


}
/*fibonacci using memoization*/

int F[10];

int mFib(int n){
    if(n==1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2] = mFib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1] = mFib(n-1);
        }
        return F[n-2]+F[n-1];
    }

}

int main(){
    int t;
    for(int i = 0; i<10; i++){
        F[i]=-1;
    }
    printf("%d \n", mFib(5));
    return 0;
}