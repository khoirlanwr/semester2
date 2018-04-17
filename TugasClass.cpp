#include <iostream>
using namespace std;

class Base {
	private:
		int s;
		int matrix[10][10];
		
	public:
		Base(int size) {s = size; };
		~Base() { cout << "Object deleted..." << endl; };
		void set();
		void print();
		void jumlahkan(Base*, Base*);
		void kurangi(Base*, Base*);
		void kali(Base* , Base*);
};

void Base::set() {
	for(int i=0; i<s; i++) {
		for(int j=0; j<s; j++) {
			cout << "Entry elemen ke[" << i << "][" << j <<"]: ";
			cin >> this->matrix[i][j];
		}
	}
};

void Base::print() {
	for(int i=0; i<s; i++) {
		for(int j=0; j<s; j++) {
			cout << this->matrix[i][j] << " ";
		}
		cout << "\n";
	}
};

void Base::jumlahkan(Base* a, Base* b) {
	for(int i=0; i<s; i++) {
		for(int j=0; j<s; j++) {
			this->matrix[i][j] = (a->matrix[i][j] + b->matrix[i][j]);
		}
	}
}

void Base::kurangi(Base* a, Base* b) {
	for(int i=0; i<s; i++) {
		for(int j=0; j<s; j++) {
			this->matrix[i][j] = (a->matrix[i][j] - b->matrix[i][j]);
		}
	}
}

void Base::kali(Base* a, Base* b) {
	// flush
	for(int i=0; i<s; i++) {
		for(int j=0; j<s; j++) {
			this->matrix[i][j] = 0;
		}
	}
	
	for(int i=0; i<s; ++i) {
		for(int j=0; j<s; ++j) {
			for(int k=0; k<s; ++k) {
				this->matrix[i][j] += (a->matrix[i][k] * b->matrix[k][j]);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	
	Base a(N);
	Base b(N);
	Base c(N);

	a.set();
	b.set();
	
	cout << "0. Penjumlahan" << endl;
	cout << "1. Pengurangan" << endl;
	cout << "2. Perkalian" << endl;
	
	int se;
	cin >> se;
	if (se == 0) 
		c.jumlahkan(&a, &b);
	else if(se == 1) 
		c.kurangi(&a, &b);
	else if(se == 2)
		c.kali(&a, &b);
	
	cout << "Hasil: " << endl;
	c.print();
	
	return 0; 
}
