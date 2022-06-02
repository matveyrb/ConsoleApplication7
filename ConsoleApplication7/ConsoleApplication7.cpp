#include <iostream>
#include <stdlib.h>
using namespace std;
//функция, сливающая массивы
void Merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[last+1];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++)  //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};
//рекурсивная процедура сортировки
 void MergeSort(int* A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);  //сортировка левой части
        MergeSort(A, (first + last) / 2 + 1, last);  //сортировка правой части
        Merge(A, first, last);  //слияние двух частей
    }
}
double timePerf(int c, int n) {
    double sum = 0;
    for (int i = 0; i < c; i++) {
        int* A = new int[n];
        srand(time(NULL));
        for (i = 0; i < n; i++) {
            A[i] = rand() % 100;
        }
        double cltimeStart = clock();
        MergeSort(A, 0, n-1);
        double cltimeEnd = clock();
        double durationCL = ((double)cltimeEnd - cltimeStart) / (double)
               CLOCKS_PER_SEC;
        sum += durationCL;
        delete[] A;
    }
    return sum / c;
}
//главная функция
void main() {
    int n, c;
    cout << "Number of measurements: ";
    cin >> c;
    cout << "Array size:  ";
    cin >> n;
    cout << "Average measurement time: " << timePerf(c, n);
}