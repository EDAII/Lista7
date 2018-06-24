#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 4
#define CAP 5

int memo[TAM][CAP+1] = {0};

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int capacity, int weight[], int value[], int position){
    int i, j, w;
    for(i=0 ; i<TAM+1; i++){
        for(j=0; j<CAP+1; j++){
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i <= position; i++)
   {
       for (w = 0; w <= capacity; w++)
       {
           if (i==0 || w==0)
               memo[i][w] = 0;
           else if (weight[i-1] <= w)
                 memo[i][w] = max(value[i-1] + memo[i-1][w-weight[i-1]],  memo[i-1][w]);
           else
                 memo[i][w] = memo[i-1][w];
       }
   }
 
   return memo[position][capacity];
}

int main(){
    int i;
    int j;
    int value[TAM] = {1,5,8,13};
    int weight[TAM] = {1,2,4,5};
    int capacity = CAP;
    int position = TAM;

    clock_t begin = clock();

    int result = knapsack(capacity, weight, value, position);

    clock_t end = clock();
    for(i=0 ; i<TAM+1; i++){
        for(j=0; j<CAP+1; j++){
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %lf\n",time_spent);
    printf("resultado: %d\n", result);
    return 0;
}