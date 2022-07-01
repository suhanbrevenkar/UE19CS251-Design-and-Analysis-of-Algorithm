#include "header.h"
int randrange(int a[], int n){
    int num;
    srand(0);
    // int b[7]={10,80,30,90,40,50,70};
    for(int i=0; i<n; i++){
        a[i]=rand()%100000;
    }
}
void merge(int a[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		a[k] = R[j];
		j++;
		k++;
	}
}
void merge_sort(int a[], int l, int r, double * count){
	if (l < r) {
		*count = *count + 1;
		int m = l + (r - l) / 2;
		merge_sort(a, l, m, count);
		merge_sort(a, m + 1, r, count);
		merge(a, l, m, r);
	}
}
