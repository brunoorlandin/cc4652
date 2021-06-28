/**
 * @author      : Guilherme Wachs Lopes (gwachs@fei.edu.br)
 * @file        : heap
 * @created     : quarta mai 12, 2021 22:17:38 -03
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



template <typename T, int MAX>
class Heap{
  private:
    T v[MAX];
    int n;

    int fe(int idx){
      return 2*idx+1;
    }
    int fd(int idx){
      return 2*idx+2;
    }
    int pai(int idx){
      return (idx-1)/2;
    }
    int ultimoPai(int n){
      return pai(n-1);
    }

  public:
    Heap(T *v, int n): n(n) {
      copy(v, v+n, this->v);
      constroiHeap();
    }
    Heap(): n(0) {
    }

    void sift(int idx){
      if(idx > ultimoPai(n) || n==1)
        return;

      int idxmaiorFilho = fe(idx);
      if ( fd(idx) < n && v[fd(idx)] > v[idxmaiorFilho])
        idxmaiorFilho = fd(idx);

      if (  v[idx] < v[idxmaiorFilho] ){
        T temp = v[idx];
        v[idx] = v[idxmaiorFilho];
        v[idxmaiorFilho] = temp;
        sift(idxmaiorFilho);
      }

    }

    void constroiHeap(){
        for (int i = ultimoPai(n); i >= 0; i--) {
          sift(i);
        }
    }

    int tamanho(){
      return n;
    }

    bool insere(T valor){
      if (n==MAX)
        return false;

      v[n] = valor;
      n++;
      //constroiHeap(v, n);  //demorado
      for (int i = ultimoPai(n); i > 0; i = pai(i)) {
        sift(i);
      }
      sift(0);

      return true;
    }

    void imprime(){
      for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
      }
    }

   T remove(){
     swap(v[0], v[n-1]);
     n--;
     sift(0);
     return v[n];
   }
};

int main() {

  vector<int> vi{5,7,6,20,15};
  make_heap(vi.begin(), vi.end());
  for_each(vi.begin(), vi.end(), [](int x){
      cout << x << endl;
      });
  cout << "===================" << endl;
  pop_heap(vi.begin(), vi.end());
  vi.pop_back();
  for_each(vi.begin(), vi.end(), [](int x){
      cout << x << endl;
      });
  

  cout << "===================" << endl;

  int v[]={5,7,6,20,15};
  Heap<int, 15> x(v,5);
  x.imprime();
  x.insere(50);
  cout << "===================" << endl;
  x.imprime();
  cout << "===================" << endl;
  while(x.tamanho() > 0){
    int rem = x.remove();
    cout << rem << endl;
  }
  //HEAP SORT!
  

  return 0;
}
