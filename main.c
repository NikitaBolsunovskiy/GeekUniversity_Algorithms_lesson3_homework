#include <stdio.h>

#define MaxN 100

void solution1();
void solution2();
void solution3();
void solution4();

int main (int argc, char* argv[]){

    //solution1();
    //solution2();
    //solution3();
    solution4();

    return 0;
}

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

void readArrayFromTxtFile(int * N, int * a, char path[]){

    FILE *in;
    in = fopen(path,"r");
    int M = 0;
    fscanf(in,"%i",&M);
    for(int i = 0; i<M; i++){
        fscanf(in,"%i",&a[i]);
    }
    fclose(in);
    *N = M;
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

int shakerSort(int N, int *a){

    // counter - переменная, в которой будем хранить количество операций, подсчет не точный, просто, чтобы был понятен порядок цифр...

    int counter = 0;
    int min = 0;
    int max = N-1;



    for(int i = 0; i<N;i++){
        counter += 1;
        if(i%2==0){
            for (int j = min; j < max; j++) {
                counter+=1;
                if(a[j]>a[j+1]){
                    swap(&a[j],&a[j+1]);
                    counter+=1;
                }
            }
            max -= 1;
        } else {
            for (int j = max; j > min; j--) {
                counter+=1;
                if(a[j]<a[j-1]){
                    swap(&a[j],&a[j-1]);
                    counter+=1;
                }
            }
            min+=1;
        }
        //print(N,a);
    }

    return counter;
}

void solution1(){

//    1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//    оптимизированной и не оптимизированной программы. Написать функции сортировки, которые
//    возвращают количество операций.

    int a[MaxN];
    int N;

    readArrayFromTxtFile(&N,a,"D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\03\\homework3\\testData.txt");

    puts("Массив до сортировки:");
    print(N,a);
    int counter = bubleSort(N,a);
    puts("Массив после сортировки:");
    print(N,a);
    printf("Количество операций: %d\n",counter);

    readArrayFromTxtFile(&N,a,"D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\03\\homework3\\testData.txt");

    puts("Массив до сортировки:");
    print(N,a);
    counter = shakerSort(N,a);
    puts("Массив после сортировки:");
    print(N,a);
    printf("Количество операций: %d\n",counter);
}

void solution2(){

//    2. *Реализовать шейкерную сортировку.

    int a[MaxN];
    int N;

    readArrayFromTxtFile(&N,a,"D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\03\\homework3\\testData.txt");
    puts("Массив до сортировки:");
    print(N,a);
    int counter = shakerSort(N,a);
    puts("Массив после сортировки:");
    print(N,a);
    printf("Количество операций: %d\n",counter);
}

int searchSortedArray(int x, int N, int *a){

    int L = 0;
    int R = N-1;
    int m = L+(R-L)/2;
    while(L<=R && a[m]!= x){
        if(a[m]<x){
            L=m+1;
        } else {
            R=m-1;
        }
        m = L + (R-L)/2;
    }

    if (a[m]==x){
        return m;
    } else {
        return -1;
    }

}

void solution3(){

//    3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
//    массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.

    int a[MaxN];
    int N;

    int x;

    readArrayFromTxtFile(&N,a,"D:\\Java_projects_Study\\05_Algorithms_and_data_structures\\03\\homework3\\testData.txt");
    shakerSort(N,a);
    puts("Массив отсортированный:");
    print(N,a);

    printf("Введите число для поиска:\n");
    scanf("%d",&x);

    printf("позиция искомого числа: %d\n",searchSortedArray(x,N,a));

}

void solution4() {
//    4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
//    сложностью алгоритма.
    //Пока не очень понятно что нужно сделать...
    // нашел неплохую статью о сортировках массивов с примерами реализации и тестами... https://habr.com/post/335920/
}