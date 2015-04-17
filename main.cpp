<<<<<<< HEAD
#include <cstdio>
  
int max(int a, int b, int c) {
    return c> (a>b ? a : b) ? c: (a>b ? a : b);
}

int main() {
    int n, value, weight; // items, value, weight
	float helper3;			// readed item weight
	int s1, s2;				// sacks weight
	float helper1, helper2; // readed sack weight
	
    scanf("%f %f", &helper1, &helper2);
    
    helper1*=10; // helps cast weight of first knapsack to int
    helper2*=10; // helps cast weight of second knapsack to int
    
    s1 = int(helper1+0.5);	//http://www.cplusplus.com/forum/beginner/33018/
    s2 = int(helper2+0.5);
	    
	int **knapsack = new int *[s1+1];
		for (int a =0; a < s1+1; ++a) {
		knapsack[a] = new int [s2+1];
			for (int b = 0; b<s2+1; ++b) knapsack[a][b] = 0;
		}
		
	scanf("%d",&n);
    // filing knapsack
    for (int i = 0; i < n; i++) {
        scanf("%f %d", &helper3, &value);
        helper3*=10;
        weight = int(helper3+0.5); // same as above
    // need to fill up all the table cannot stop if one sack is full because item might fit in other
        for (int weight1 = s1; weight1 >= 0; weight1--) { // weight of first knapsack
            for (int weight2 = s2; weight2 >= 0; weight2--) { // weight of second knapsack
                 int value1 = 0;
				 int value2 = 0;
				 
                 	if(weight<=weight1) {
                   		value1 = knapsack[weight1 - weight][weight2] + value;
					}
                 	if(weight<=weight2) {
                   		value2 = knapsack[weight1][weight2 - weight] + value;
					}
					
					knapsack[weight1][weight2] = max(
						knapsack[weight1][weight2]	// we have best option
						,value1				// put into sack one
						,value2               // put into sack two
					);
            }
        }
    }

    printf("%d\n", knapsack[s1][s2]);

    return 0;
}
=======
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
>>>>>>> 83a8fb920a22d8a3a928d2f20ca113e97dccabab
