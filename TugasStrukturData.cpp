#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct arr{
	double arr[100][100];
};

void perkalian(int size, arr* matriks0, arr* matriks1, arr* matriks2) 
{
	int i, j, k;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			matriks2->arr[i][j] = 0;
			for(k=0; k<size; k++) {
				matriks2->arr[i][j] += matriks0->arr[i][k] * matriks1->arr[k][j];
			}
		}
	}
	
}

void penjumlahan(int size, arr* matriks0, arr* matriks1, arr* matriks2) 
{
	int i, j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			matriks2->arr[i][j] = matriks0->arr[i][j] + matriks1->arr[i][j];
		}
	}
}

void pengurangan(int size, arr* matriks0, arr* matriks1, arr* matriks2) 
{
	int i, j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			matriks2->arr[i][j] = matriks0->arr[i][j] - matriks1->arr[i][j];
		}
	}
}

void print(int size, arr* matriks2) 
{
	int i, j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			cout << matriks2->arr[i][j] << " ";
		}
		cout << endl;		
	}
}

int main()
{
	int N;
	int i, j;
	
	cout << "Masukkan jumlah ordo matriks: ";
	cin >> N;
	
	// creating object
	arr matriks0; 
	arr matriks1;
	arr matriks2;
	
	matriks0.arr[N][N];
	matriks1.arr[N][N];
	matriks2.arr[N][N];
	
	// Input matriks0
	cout << "Masukkan element matriks A: " << endl;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			cout << "Input element ke[" << i <<"][" << j << "]: ";
			cin >> matriks0.arr[i][j];		
		} 
	}
	
	// Input matriks1
	cout << "\n";
	cout << "Masukkan element matriks B: " << endl;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			cout << "Input element ke[" << i <<"][" << j << "]: ";
			cin >> matriks1.arr[i][j];		
		} 
	}
	
	// Output matriks0
	cout << "\n";
	cout << "Output matriks A: " << endl;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			cout << matriks0.arr[i][j] << " ";		
		}
		cout << "\n";
	}
	
	
	// Output matriks0
	cout << "\n";
	cout << "Output matriks B: " << endl;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			cout << matriks0.arr[i][j] << " ";		
		}
		cout << "\n";
	}
	
	cout << "\n";
	cout << "Perkalian: " << endl;
	// Memanggil fungsi
	perkalian(N, &matriks0, &matriks1, &matriks2);
	print(N, &matriks2);
	
	cout << "\n";
	cout << "Penjumlahan: " << endl;
	// Memanggil fungsi
	penjumlahan(N, &matriks0, &matriks1, &matriks2);
	print(N, &matriks2);
	
	cout << "\n";
	cout << "Pengurangan: " << endl;
	// Memanggil fungsi
	pengurangan(N, &matriks0, &matriks1, &matriks2);
	print(N, &matriks2);
	
}
