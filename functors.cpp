#include <iostream>
using namespace std;


//Functor: é uma classe que se passa por função
class Multiplicador{
  private:
    int fator;
  public:
    Multiplicador(int fator): fator(fator){
    }

    int operator () (int valor){
      return this->fator*valor;
    }
};

class MinhaFuncao{
  public:
    void operator()(){
      cout << "Minha Funcao Executada" << endl;
    }
};


template <typename Funcao>
class ExecutorRemoto{
  private:
    Funcao f;
  public:
    void rodarCodigo(){
      cout << "enviando codigo para comp remoto" << endl;
      f();
      cout << "funcao executada" << endl;
    }
};

int main() {

  ExecutorRemoto<MinhaFuncao> executor;
  executor.rodarCodigo();

  
  return 0;
}

