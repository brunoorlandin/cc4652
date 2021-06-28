/**
 * @author      : Guilherme Wachs Lopes (gwachs@fei.edu.br)
 * @file        : Pilha
 * @created     : quarta mai 05, 2021 19:58:32 -03
 */
#include <iostream>
using namespace std;

//classe pilha estatica
template <typename T> class Pilha {
public:
  virtual bool empilha(T valor) = 0;
  virtual T desempilha() = 0;
  virtual int tamanho() = 0;
  virtual ~Pilha() {}
};

template <typename T, int MAX> class PilhaEstatica : public Pilha<T> {
private:
  T v[MAX];
  int n;
public:
  PilhaEstatica() {
    n=0;
  }
    int getn () {
      return n;
    }

    bool empilha(T valor) {
      if (n < MAX) {
        v[n] = valor;
        n++;
      }
      else {
        cout << "pilha cheia" << endl;
        
      }
      return false;
    }
    T desempilha() {
      if (n > 0) {
        n--;
        return v[n];
      }
      return -1;
    }
    int tamanho() {
      return n;
    }
    ~PilhaEstatica() {}
};

//No da pilha dinâmica (não alterar)
template <typename T> class No {
private:
public:
  No(){
    cout << "#No Criado#" << endl;
  }
  ~No(){
    cout << "#No Destruido#" << endl;
  }
  T valor;
  No<T> *proximo;
};

//Pilha dinamica
template <typename T> class PilhaDinamica : public Pilha<T>{
private:
    No<T> *ultimo;
    int n;
public:
    PilhaDinamica() {
        ultimo = nullptr;
        n = 0;
    }
    bool empilha(T value){
        No<T> *novo = new No<T>;
        if (novo == nullptr){
            return false;
        }

        novo->valor = value;
        novo->proximo = ultimo;
        ultimo = novo;
        n++;
        return true;
    }
    T desempilha(){
        No<T> *temp = ultimo;
        T ret = temp->valor;
        ultimo = ultimo->proximo;
        delete temp;
        n--;
        return ret;
    }
    int tamanho(){
        return n;
    };
    ~PilhaDinamica() {
        int tam = n;
        for (int i = 0; i < tam; i++){
            this->desempilha();
        }
    }
};


//Não alterar o teste
void testaPilha(Pilha<int> &p) {
  for (int i = 0; i < 5; i++) {
    p.empilha(i);
  }
  cout << p.desempilha() << endl;
  cout << p.desempilha() << endl;
  cout << p.desempilha() << endl;
  for (int i = 0; i < 3; i++) {
    p.empilha(i);
  }
  while (p.tamanho() > 2) {
    cout << p.desempilha() << endl;
  }
}

//Implementar as classes PilhaEstatica<T,MAX>  e PilhaDinamica<T>  herdando de Pilha<T>

//não alterar o main
int main() {
  PilhaEstatica<int, 20> pe;
  testaPilha(pe);

  PilhaDinamica<int> pd;
  testaPilha(pd);

  return 0;
}
