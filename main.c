#include <stdio.h>

#define MaxN 100

void print(int N, int*a){
    int i;
    for (i=0; i<N; i++)
        printf("%d   ", a[i]);
    printf("\n");
}

void bubleSort(int N, int *a){

}

int main (int argc, char* argv[]){

    int a[MaxN];

    int N;

    FILE *in;
    in = fopen("D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\03\\homework3\\testData.txt","r");
    fscanf(in,"%i",&N);

    for(int i = 0; i<N; i++){
        fscanf(in,"%i",&a[i]);
    }

    puts("Массив до сортировки:");

    print(N,a);

    fclose(in);

    return 0;
}