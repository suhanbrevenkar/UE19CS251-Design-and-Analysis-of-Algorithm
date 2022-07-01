#include"header.h"
int randrange(int a[], int n){
    int num;
    srand(0);
    // int b[5]={90,2,10,30,1};
    for(int i=0; i<n; i++){
        a[i]=rand()%10000;
    }
}
int* swap(int a[], int i){
    if(i>=0){
        // printf("Swapping now...\n");
        a[i]   =  a[i] + a[i+1];
        a[i+1] =  a[i] - a[i+1];
        a[i]   =  a[i] - a[i+1];
    }/* 
    printf("After the swap: ");
    for(int z=0; z<n; z++){
        printf("%d ",a[z]);
    }
    printf("\n"); */
    return a;
}
int bbl_sort(int a[], int n, double * count){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                *count=*count+1;
                a = swap(a,j);
            }
        }
    }
}
