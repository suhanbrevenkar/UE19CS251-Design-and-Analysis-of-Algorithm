#include "header.h"
int main(void){
    double count=0;
    clock_t time;
    double elapse;
    FILE *fp1, *fp2;
    fp1=fopen("time.txt","w");
    fp2=fopen("comp.txt","w");
    // fp3=fopen("Arrays.txt","w");
    printf("Please wait...");
    for(int i = 100000; i<=1000000; i+=50000){
        // fprintf(fp3,"For i = %d\n---------------------------------\n",i);
        int a[i];
        time=clock();
        randrange(a,i);
        /* fprintf(fp3,"Oiginal array = ");
        for(int z=0; z<i; z++){
            fprintf(fp3,"%d ",a[z]);
        } */
        /* printf("\nOld array: ");
        for(int z=0; z<i; z++){
            printf("%d ",a[z]);
        } */
        sel_sort(a,i,&count);
        time=clock()-time;
        elapse=((double)time)/CLOCKS_PER_SEC;
        fprintf(fp1,"%d\t%lf\n",i,elapse);
        fprintf(fp2,"%d\t%lf\n",i,count);
        printf("\nCompleted the record for array size = %d",i);
        /* fprintf(fp3,"\nNew array: ");
        for(int z=0; z<i; z++){
            fprintf(fp3,"%d ",a[z]);
        } */
        /* printf("\nNew array: ");
        for(int z=0; z<i; z++){
            printf("%d ",a[z]);
        } */
        printf("\n");
        // fprintf(fp3,"\n---------------------------------\n");
    }
    fclose(fp1);
    fclose(fp2);
}
