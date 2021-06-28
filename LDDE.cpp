/**
 * @author      : Guilherme Wachs Lopes (gwachs@fei.edu.br)
 * @file        : LDE
 * @created     : quinta abr 08, 2021 21:16:02 -03
 */

// __________________________________ 
//< Completar os métodos comentados >
// ---------------------------------- 
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||
//
#include <iostream>
using namespace std;

template <typename T> class Lista {
public:
  virtual bool insere(T valor) = 0;
  virtual bool remove(int pos) = 0;
  virtual int busca(T valor) = 0;
  virtual void imprime() = 0;
  virtual ~Lista() {}
};

template <typename T> class Node {
public:
  T value;
  Node<T> *next;
  Node<T> *prev; //<----adicionado
};

template <typename T> class ListaDinamicaEncadeada : public Lista<T> {
private:
  Node<T> *first;
  Node<T> *last; //<------adicionado
  int n;

public:
  ListaDinamicaEncadeada() {
    first = nullptr;
    last = nullptr;
    n = 0;
  }
  bool insere(T valor) {
   //AJUSTAR

    // 1 Alocar novo nó
    Node<T> *novo = new Node<T>;
    if (novo == nullptr)
      return false;

    // 2 preencher atributos
    novo->value = valor;
    novo->next = nullptr;
    novo->prev = nullptr;

    // 3 encontrar vizinhos
    Node<T> *ptrAtual = first;
    Node<T> *ptrAnterior = nullptr;

    while (ptrAtual && ptrAtual->value < valor) {
      ptrAnterior = ptrAtual;
      ptrAtual = ptrAtual->next;
    }

    // 4 conectar
    if (ptrAnterior) {
      ptrAnterior->next = novo; // proteção
      novo->prev = ptrAnterior;
    } else
      first = novo;

    
    if (ptrAnterior){
      ptrAnterior->next = novo;
    }
    else{
      first = novo;
    }
    if (ptrAtual){
      ptrAtual->prev= novo; 
    }
    else{
      last = novo;
    }

    novo->next = ptrAtual;
    novo->prev =ptrAnterior;
    
    if(novo->next == nullptr){
      last = novo;
    }
    // 5 vai pro abraço
    n++;
    return true;
  }

  bool remove(int pos) {
    //AJUSTAR
    Node<T> *ptrAnterior = nullptr;
    Node<T> *ptrAtual = first;
    if (pos >= n || pos < 0)
      return false;

    for (int i = 0; i < pos; i++) {
      ptrAnterior = ptrAtual;
      ptrAtual = ptrAtual->next;
    }

    Node<T> *ptrProximo = ptrAtual->next;
    delete ptrAtual;

    if (ptrAnterior)
      ptrAnterior->next = ptrProximo;
    else
      first = ptrProximo;

    if(ptrProximo){
      ptrProximo->prev = ptrAnterior;
    }
    else{
      last = ptrAnterior;
    }

    n--;
    return true;
  }

  int busca(T valor) { 
    //IMPLEMENTAR. Retorne -1 caso não encontrado. 
    Node<T> *t = first;
    int i = 0;
    while (t) {
      if (t->value == valor) {
        return i;
      i++;
      t = t->next;   
      } 
      else {
        t = t->next;  
      }
    }
    return -1;
    cout << endl;
   
    
  };
  void imprime() {
    Node<T> *t = first;
    while (t) {
      cout << t->value << "  ";
      t = t->next;
    }
    cout << endl;
  };

  void imprimeReverso() {
    Node<T> *t = last;
    while (t) {
      cout << t->value << "  ";
      t = t->prev;
    }
    cout << endl;
  };
  
  ~ListaDinamicaEncadeada() {
    while (remove(0))
      ;
  }
};

int main() {
  //NÃO ALTERAR O MAIN!

  ListaDinamicaEncadeada<int> l;
  l.insere(10);
  l.insere(5);
  l.insere(50);
  l.insere(7);
  l.insere(0);
  l.imprime();
  l.imprimeReverso();
  cout << (l.remove(0) ? "removido idx 0" : "nao removido") << endl;
  cout << (l.remove(3) ? "removido idx 3" : "nao removido") << endl;
  cout << (l.remove(3) ? "removido idx 3" : "nao removido") << endl;
  l.remove(3);
  cout << "Imprime" << endl;
  l.imprime();
  cout << "Imprime Reverso" << endl;
  l.imprimeReverso();
  cout << "encontrado 5 na posicao: " << l.busca(5) << endl;
  cout << (l.remove(0) ? "removido idx 0" : "nao removido") << endl;
  cout << "encontrado 5 na posicao: " << l.busca(5) << endl;
  cout << "Imprime" << endl;
  l.imprime();
  cout << "Imprime Reverso" << endl;
  l.imprimeReverso();
  cout << (l.remove(0) ? "removido idx 0" : "nao removido") << endl;
  l.imprime();
  cout << "Imprime Reverso" << endl;
  l.imprimeReverso();
  cout << (l.remove(0) ? "removido idx 0" : "nao removido") << endl;
  l.imprime();
  cout << "Imprime Reverso" << endl;
  l.imprimeReverso();
  cout << (l.remove(0) ? "removido idx 0" : "nao removido") << endl;


  return 0;
}