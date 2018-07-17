#include <stdio.h>

#define MaxN 100

void solution1();

void print(int N, int*a){
    int i;
    for (i=0; i<N; i++)
        printf("%d   ", a[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int bubleSort(int N, int *a){

    // counter - переменная, в которой будем хранить количество операций, подсчет не точный, просто, чтобы был понятен порядок цифр...

    int counter = 0;

    for(int i = 0; i<N;i++){
        counter += 1;
        for (int j = 0; j < N-1; ++j) {
            counter += 1;
            if (a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                counter+=1;
            }
        }
    }

    return counter;
}

int main (int argc, char* argv[]){

    solution1();

    return 0;
}

void solution1(){

//    1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//    оптимизированной и не оптимизированной программы. Написать функции сортировки, которые
//    возвращают количество операций.

    int a[MaxN];

    int N;

    FILE *in;
    in = fopen("D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\03\\homework3\\testData.txt","r");
    fscanf(in,"%i",&N);

    for(int i = 0; i<N; i++){
        fscanf(in,"%i",&a[i]);
    }

    fclose(in);

    puts("Массив до сортировки:");
    print(N,a);
    int counter = bubleSort(N,a);
    puts("Массив после сортировки:");
    print(N,a);
    printf("Количество операций: %d\n",counter);
}