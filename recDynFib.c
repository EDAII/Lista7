#include<stdio.h>
#include<time.h>

double fib(int num, double *array){
    double valor;
    if(array[num] != 0){
        return array[num];
    }
    else if(num == 1 || num == 2){
        return 1;
    }
    else{
        valor = fib(num-1, array) + fib(num-2, array);
        array[num] = valor;
        return valor;
    }
}

int main(){
    int num;
    double fibo;
    double array[100000] = {0};
    scanf("%d", &num);

    clock_t begin = clock();
    fibo = fib(num, array);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Fibonacci: %.0lf\n Tempo gasto: %lf\n", fibo, time_spent);
    return 0;
}