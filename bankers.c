#include <stdio.h>
#define N 4 // Number of processes 
#define R 4 //Number of resources
int main() 
{ 
	int i, j, k; 
    //Allocation
	int alloc[N][R] = { { 1, 0, 2, 1 },    // P1
						{ 2, 1, 2, 1 },    // P2 
						{ 3, 1, 1, 2 },    // P3 
						{ 2, 1, 1, 0 } };  // P4 
    // Max Need 
	int max[N][R] = { { 6, 3, 3, 2 },    // P1
				      { 5, 2, 2, 1 },    // P2 
					  { 4, 2, 2, 3 },    // P3 
					  { 4, 2, 1, 2 } };  // P4                     
    //Available Resources 
	int avail[R] = { 3, 1, 0, 2 };



	int f[N], ans[N], ind = 0; 
	for (k = 0; k < N; k++) { 
		f[k] = 0; 
	} 
	int need[N][R]; 
	for (i = 0; i < N; i++) { 
		for (j = 0; j < R; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < N; k++) { 
		for (i = 0; i < N; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < R; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i + 1; 
					for (y = 0; y < R; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Safe Sequence : "); 
	for (i = 0; i < N - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d\n", ans[N - 1]); 

	return 0; 

} 
