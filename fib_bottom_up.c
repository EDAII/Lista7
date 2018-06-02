#include<stdio.h>
#include<time.h>

double fib(int num, double *array){
    int i;
    array[0] = 1;
    array[1] = 1;
    for(i = 2; i < num; i++){
        array[i] = array[i-1] + array[i-2];
    }
    return array[num-1];
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