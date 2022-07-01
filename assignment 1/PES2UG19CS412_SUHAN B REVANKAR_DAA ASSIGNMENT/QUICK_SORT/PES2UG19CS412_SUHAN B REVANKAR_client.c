#include "header.h"
int main() 
{ 
	double count=0;
    clock_t time;
    double elapse;
    FILE *fp1, *fp2, *fp3;
    fp1=fopen("time.txt","w");
    fp2=fopen("comp.txt","w");
    printf("Please wait...");
    for(int n=100000; n<=1000000; n+=50000){
		int a[n]; 
		time=clock();
		randrange(a,n);
		/* printf("\nOld array: ");
		for (int i=0; i < n; i++){
			printf("%d ", a[i]); 
		} */
		quick_sort(a, 0, n-1,&count);
		// printArray(a,n);
		time=clock()-time;
        elapse=((double)time)/CLOCKS_PER_SEC;
		fprintf(fp1,"%d\t%lf\n",n,elapse);
        fprintf(fp2,"%d\t%lf\n",n,count);
        printf("\nCompleted the record for array size = %d",n);
		/* printf("\nNew array: ");
		for (int i=0; i < n; i++){
			printf("%d ", a[i]); 
		}
		printf("\n");  */
	}
    fclose(fp1);
    fclose(fp2);
}
