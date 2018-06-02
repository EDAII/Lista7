#include<stdio.h>
#include<stdlib.h>
#define TAM 5
int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int capacity, int weight[], int value[], int position){
    if (position == 0 || capacity == 0){
        return 0;
    }

    if (weight[position-1] > capacity){
        return knapsack(capacity, weight, value, position-1);
    }

    else {
        int lol = max( value[position-1] + knapsack(capacity - weight[position-1], weight, value, position-1),
        knapsack(capacity, weight, value, position-1));
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
    int capacity = 60;
    int position = TAM;
    int result = knapsack(capacity, weight, value, position);
    for(i = 0; i < TAM ; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
    for(i = 0; i < TAM ; i++){
        printf("%d ", weight[i]);
    }
    printf("\n");
    printf("%d\n", result);
    return 0;
}