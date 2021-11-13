#define _CRT_SECURE_NO_DEPRECATE 
#include <windows.h> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <iostream>


using namespace std;

#define LIGHTGRAY 7 
#define LIGHTRED  12


int mostFreqNum(int array[], int N) {
    int maxCnt = 0, maxVal = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = i + 1; j < N; j++) { //   for (int j = 0; j < N; j++) при таком цикле первый элемент будет отмечаться 
            if (array[i] == array[j])
                count++;
        }
        if (count > maxCnt) {
            maxCnt = count;
            maxVal = array[i];
        }
    }
    return maxVal;
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowArray(int A[], int N, int FreqNum) {

	for (int i = 0; i < N; i++) {
		TextColor(A[i] == FreqNum ? LIGHTRED : LIGHTGRAY); // A[i] == IdentNumbet - это условие делает ? Если условие верное, то будет LighRed, в противном случае LightGray. 
		printf("%d ", A[i], i % 10 == 9 ? "\r\n" : " ");
	}
	if (N % 10) printf("\n");
}

int main()
{
	int n, * a; // * показывает значение переменной по заданному адресу
	cout << "Please enter amount of number in array = "; cin >> n;

	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ShowArray(a, n, mostFreqNum(a,n));
	return 0;


}

