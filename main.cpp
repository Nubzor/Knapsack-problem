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
