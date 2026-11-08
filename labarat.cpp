 //Задание 1, вар 11/26

//#include <stdio.h>
//#include <iostream>
//#include <clocale>
//#include <windows.h>
//#include <time.h>
//#define N 10
//
//using namespace std;
//
//
//void sort(int arr[], int ind_min, int ind_max) {
//	int left = ind_min;
//	int right = ind_max;
//
//	if (left > right) {
//		left = ind_max;
//		right = ind_min;
//	}
//
//	for (int end = right - 1; end > left + 1; end--) {
//		for (int i = left + 1; i < end; i++) {
//			if (arr[i] < arr[i + 1]) {
//				int temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//	}
//}
//
//int main() {
//	int ind_min = 0, ind_max = 0;
//	time_t k;
//	srand(time(&k));
//	int arr[N];
//	int n = 0;
//	for (int i = 0; i < N; i++)
//		arr[i] = rand() % 100;
//
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] < arr[ind_min])
//		{
//			ind_min = i;
//		}
//
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] > arr[ind_max])
//		{
//			ind_max = i;
//
//		}
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
//	cout << ind_max << "\n";
//	cout << ind_min;
//
//	sort(arr, ind_min, ind_max);
//	cout << "\n";
//	for (int i = 0; i < N; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
// return 0;
}

// Задание 2


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    const int N = 8;
    int matrix[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 201 - 100;
        }
    }

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j >= N - 1) {
                SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << setw(5) << matrix[i][j];
                SetConsoleTextAttribute(console, 7);
            }
            else {
                cout << setw(5) << matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1 - i; j < N; j++) {
            if (matrix[i][j] > 0 && matrix[i][j] % 2 == 0) {
                count++;
            }
        }
    }

    cout << "Количество положительных чётных : " << count << "\n";

    int maxAr[4];
    int index = 0;

    for (int i = 1; i < N; i += 2) {
        int maxNum = matrix[i][0];
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
            }
        }
        maxAr[index] = maxNum;
        index++;
    }

    cout << "\nМаксимумы ч строк:" << "\n";
    for (int i = 0; i < 4; i++) {
        cout << maxAr[i] << " ";
    }
    cout << endl;

    return 0;
}
