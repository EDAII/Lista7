#include<stdio.h>
#include<time.h>

double naive_fib(int num){
    double valor;
    if(num == 1 || num == 2){
        return 1;
    }
    else{
        valor = naive_fib(num-1) + naive_fib(num-2);
        return valor;
    }
}



int main(){
    int num;
    double fibo;
    scanf("%d", &num);
    clock_t begin = clock();
    fibo = naive_fib(num);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Fibonacci: %.0lf\n Tempo gasto: %lf\n", fibo, time_spent);
    return 0;
}
