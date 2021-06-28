#include <iostream>
using namespace std;

template <typename T> class Lista {
public:
  virtual bool insere(T valor) = 0;
  virtual bool remove(int pos) = 0;
  virtual int busca(T valor) = 0;
  virtual int buscaBinaria(T valor) = 0;
  virtual void imprime() = 0;
  virtual ~Lista() {}
};

#define MAX 10
template <typename T> class LES : public Lista<T> {
private:
  T v[MAX];
  int n;

public:
  LES() : n(0) {}

  bool insere(T valor) {
    // Checa n<MAX
    if (n == MAX)
      return false;

    // posicao de inserir
    int i;
    for (i = 0; i < n && v[i] < valor; i++)
      ;

    // deslocar para direita
    for (int j = n; j > i; j--) {
      v[j] = v[j - 1];
    }

    // inserir
    v[i] = valor;
    // n++
    n++;

    return true;
  }
  bool remove(int pos) {
    if(pos >= n || pos < 0)
      return false;

    for (int i = pos; i + 1 < n; i++) {
      v[i] = v[i + 1];
    }
    n--;
    return true;
  }

  int busca(T valor) {
    // i=0
    int i = 0;
    // varrer até pos  i=n-1  /// ou paro no primeiro num maior
    // valor == v[i]
    for (int i = 0; i < n && v[i] <= valor; i++) {
      //  se em algum momento v[i] == valor buscado
      if (v[i] == valor)
        //   return i
        return i;
    }

    return -1;
  }

  int buscaBinaria(T valor) {
    int i = 0;
    int f = n - 1;
    int p;
    while (i <= f) {
      p = (i + f) / 2;
      if (v[p] < valor)
        i = p + 1;
      else if (v[p] > valor)
        f = p - 1;
      else
        return p;
    }
    return -1;
  }

  void imprime() {
    for (int i = 0; i < n; i++) {
      cout << v[i] << endl;
    }
  }
  ~LES() {}
};

int main() {
  LES<float> l;
  l.insere(5.2);
  l.insere(1);
  l.insere(9);
  l.insere(0);
  cout << l.busca(1) << endl;
  l.remove(l.busca(8));
  l.remove(l.busca(1));
  cout << l.busca(1) << endl;
  cout << "======" << endl;
  l.imprime();

  return 0;
}