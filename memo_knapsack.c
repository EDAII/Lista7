#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 4
#define CAP 5

int memo[TAM][CAP+1] = {0};

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int capacity, int weight[], int value[], int position){
    int i,j;
    for(i=0 ; i<TAM+1; i++){
        for(j=0; j<CAP+1; j++){
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }
    printf("==============================\n");
    if(memo[position][capacity] != 0){
        return memo[position][capacity];
    }
    if (position == 0 || capacity == 0){
        return 0;
    }

    if (weight[position-1] > capacity){
        int lol = knapsack(capacity, weight, value, position-1);
        memo[position][capacity] = lol;
        return lol;
    }

    else {
        int lol = max( value[position-1] + knapsack(capacity - weight[position-1], weight, value, position-1),
        knapsack(capacity, weight, value, position-1));
        memo[position][capacity] = lol;
        return lol;
    }
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