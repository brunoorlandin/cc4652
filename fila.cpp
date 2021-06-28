#include <iostream>
#include <string>

using namespace std;

template <typename T> class Fila {
public:
  virtual bool enfileirar(T valor) = 0;
  virtual T desenfileirar() = 0;
  virtual int tamanho() = 0;
  virtual int busca(T valor) = 0;
  virtual void imprime() = 0;
  virtual ~Fila() {}
};

template <typename T, int MAX> class FilaEstaticaCircular : public Fila<T> {
private:
  T v[MAX];
  int i = 0;
  int f = 0;

public:
    bool enfileirar(T valor) {
        if ((f+1) % 8 == i){
            return false;
        }else{
            v[f] = valor;
            f = (f+1)%MAX;
            return true;
        }

    }
    T desenfileirar() {
        if (f == i){
            return v[0];
        }else{
            i = (i+1)%MAX;
            return v[i-1];


        }
    }
    int tamanho() {
        if (f>=i){
            return f-i;
        }else{
            return MAX - i + f;
        }

    }
    int busca(T valor) {
        int x;
        for(x = i; x != f; x = (x+1) % MAX){
            if(v[x] == valor){
                if (x>=i){
                    return x-i;
                }else{
                    return MAX - i + x;
                }
            }
        }
    }

    void imprime() {
        int x;
        for(x = i; x != f; x = (x+1) % MAX){
            cout << v[x] << endl;
        }
    }
    ~FilaEstaticaCircular() {}
};

//Não alterar essa classe
template <typename T> class No {
public:
  No(){
    cout << "no criado" << endl;
  }
  T valor;
  No<T> *proximo;
  ~No(){
    cout << "no destruido" << endl;
  }
};

template <typename T> class FilaDinamicaEncadeada : public Fila<T> {
private:
  No<T> *primeiro;
  No<T> *ultimo;
  int n;

public:
    FilaDinamicaEncadeada() {
        primeiro = nullptr;
        ultimo = nullptr;
        n = 0;
    }

  bool enfileirar(T valor) {
    No<T> *novo = new No<T>;

    if(novo == nullptr){
        return false;
    }

    novo->valor = valor;
    novo->proximo = nullptr;

    if(ultimo){
        ultimo->proximo = novo;
    }else{
        primeiro=novo;
    }

    ultimo=novo;
    n++;
    return true;
  }
  T desenfileirar() {
    No<T> *aux = primeiro;
    T ret;
    if (!primeiro){
        return ret;
    }
    primeiro = primeiro->proximo;
    ret = aux->valor;
    n--;
    delete aux;
    return ret;
  }
  int tamanho() {
    return n;
  }
  int busca(T valor) {
    return -1;
  }

  void imprime() {
    No<T> *t = primeiro;
    while (t) {
      cout << t->valor << endl;
      t = t->proximo;
    }
    cout << endl;
  }

  ~FilaDinamicaEncadeada() {}
};

int main() {

 FilaEstaticaCircular<string, 10> fila;

  fila.enfileirar("João");
  fila.enfileirar("Milena");
  fila.enfileirar("Vitor");
  fila.enfileirar("Shawn");

  cout << fila.desenfileirar() << endl;
  fila.enfileirar("Camylla");
  fila.enfileirar("Mateus");
  cout << fila.desenfileirar() << endl;
  fila.enfileirar("Vitor");
  fila.enfileirar("Shawn");
  cout << fila.desenfileirar() << endl;
  cout << fila.desenfileirar() << endl;
  cout << fila.desenfileirar() << endl;
  cout << fila.desenfileirar() << endl;
  cout << fila.desenfileirar() << endl;
  cout << fila.desenfileirar() << endl;


  FilaDinamicaEncadeada<string> fila2;

  fila2.enfileirar("João");
  fila2.enfileirar("Milena");
  fila2.enfileirar("Vitor");
  fila2.enfileirar("Shawn");

  cout << fila2.desenfileirar() << endl;
  fila2.enfileirar("Camylla");
  fila2.enfileirar("Mateus");
  cout << fila2.desenfileirar() << endl;
  fila2.enfileirar("Vitor");
  fila2.enfileirar("Shawn");
  cout << fila2.desenfileirar() << endl;
  cout << fila2.desenfileirar() << endl;
  cout << fila2.desenfileirar() << endl;
  cout << fila2.desenfileirar() << endl;
  cout << fila2.desenfileirar() << endl;
  cout << fila2.desenfileirar() << endl;

  return 0;

}