#include <iostream>

using namespace std;

const int tamanho = 10;

class Pilha{
private:
	int vetor[tamanho];
	int n;

public:
	Pilha(){
    n = 0;
	}

	void push(int data){
		if( !(tamanho == n) ){
			vetor[n] = data;
			n++;
			return;
		}
		cout << "PILHA NO LIMITE!\n";
	}

	void pop(){
		if( !(n == 0) ){
			n--;
			return;
		}
		cout << "PILHA VAZIA!\n";
	}

	void peek(){
		if( !(n == 0) ){
			cout << vetor[n] << "\n";
		}
	}

	void change(){
		for(int i(0); i < n/2; i++){
			swap(vetor[i], vetor[n-i-1]);
		}
	}

	void show(){
		for(int i(0); i < n; i++){
			cout << vetor[i] << " ";
		}
		cout << "\n";
	}

	void t(){
    cout << "\nTAMANHO : " << n << "\n";
	}

};

int main(){
	Pilha p;

	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);
	p.push(6);
	p.push(7);
	p.push(8);
	p.push(9);
	p.push(10);
	p.push(11);

	p.t();

  cout << "\n\n";

	p.show();

	p.change();

	p.show();

	cin.get();
}
