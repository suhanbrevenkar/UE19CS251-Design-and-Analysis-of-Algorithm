#include"header.h"
int randrange(int a[], int n){
    int num;
    // int b[5]={7,300,214,100,99};
    for(int i=0; i<n; i++){
        a[i]=rand()%10000;
    }
}
int* swap(int a[], int min_ind, int i){
    int temp = a[min_ind];
    a[min_ind] = a[i];
    a[i] = temp;
    return a;
}
int sel_sort(int a[], int n, double *count){
    int ind_min; 

	// One by one move boundary of unsorted subarray 
	for (int i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		ind_min = i; 
		for (int j = i+1; j < n; j++) 
		if (a[j] < a[ind_min]){
            *count = *count + 1;
            ind_min = j;
        } 

		// Swap the found minimum element with the first element 
		a = swap(a,ind_min, i); 
	}
}
