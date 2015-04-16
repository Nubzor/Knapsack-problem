#include <iostream>
#include <cstdio>

void printMap (int **table, int width, int height) {
    for (int m=0; m<height; m++) {
        for (int n=0; n<width; n++) {
            printf("%d ", table[m][n]);
        }
        printf("\n");
    }
}

int max (int a, int b) {
    return a > b ? a : b;
}


int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int n, weight; // items, sack1, sack2, gain, cost
    float kp1, kp2, weight_helper;
    int s1, s2, gain;
    
    scanf("%f %f", &kp1, &kp2);
    s1 = kp1 * 10;
    s2 = kp2 * 10;
    scanf("%d", &n);
    
    int **knapsack = new int *[s1];
    for (int j = 0; j < s1; j++) {
        knapsack[j] = new int [s2];
    }
    s1--;
    s2--;
    
    // filing knapsack
    for (int i = 0; i < n; i++) {
        scanf("%d %f", &gain, &weight_helper);
        weight = weight_helper * 10;
        for (int w1 = s1; w1 >= 0; w1--) {
            for (int w2 = s2; w2 >= 0; w2--) {
                int val1 = 0, val2 = 0;
                
                if(weight<=w1) {
                    val1 = knapsack[w1 - weight][w2] + gain;
                }
                if(weight<=w2) {
                    val2 = knapsack[w1][w2 - weight] + gain;
                }
                
                knapsack[w1][w2] = max3(
                        knapsack[w1][w2]                   // we have best option
                        ,val1              // put into sack one
                        ,val2               // put into sack two
                );
                
                printMap(knapsack, s2, s1);
                printf("---------------\n");
            }
        }
    }
    printf("\n\n");
    printMap(knapsack, s2+1, s1+1);
    printf("\n%d %d\n%d\n", s1, s2, knapsack[s1][s2]);
    
    return 0;
}