#include"header.h"
int randrange(int a[], int n){
    int num;
    srand(0);
    // int b[7]={10,80,30,90,40,50,70};
    for(int i=0; i<n; i++){
        a[i]=rand()%100000;
    }
}
void swap(int a[], int i, int h){ 
	int temp = a[i]; 
	a[i] = a[h]; 
	a[h] = temp; 
} 
int split (int a[], int l, int h, double *count){ 
	int pivot = a[h];
	int i = (l - 1); 

	for (int j = l; j <= h- 1; j++){ 
		if (a[j] < pivot){
			i++;
			*count=*count + 1;
			swap(a, i, j); 
		} 
	} 
	swap(a, i + 1, h); 
	return (i + 1); 
} 
void quick_sort(int a[], int l, int h, double *count){ 
	if (l < h){ 
		int pi = split(a, l, h, count); 
		quick_sort(a, l, pi - 1, count); 
		quick_sort(a, pi + 1, h, count); 
	} 
} 
