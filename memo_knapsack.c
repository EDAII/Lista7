#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 60
#define CAP 300

int memo[TAM+1][CAP+1] = {0};

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int capacity, int weight[], int value[], int position){
    if(memo[position][capacity] != 0){
        return memo[position][capacity];
    }
    if (position == 0 || capacity == 0){
        return 0;
    }

    if (weight[position-1] > capacity){
        return knapsack(capacity, weight, value, position-1);
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
    int value[TAM];
    for(i = 0; i < TAM ; i++){
        value[i] = rand() % 50 + 1;
    }
    int weight[TAM];
     for(i = 0; i < TAM ; i++){
        weight[i] = rand() % 100 + 1;
    }
    int capacity = CAP;
    int position = TAM;

    clock_t begin = clock();

    int result = knapsack(capacity, weight, value, position);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %lf\n",time_spent);
    printf("resultado: %d\n", result);
    return 0;
}