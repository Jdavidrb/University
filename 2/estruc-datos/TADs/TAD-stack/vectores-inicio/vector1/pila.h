
/*
Implementación Pilas con Listas
Octubre 20 de 2023

 */

#include <vector>

using namespace std;

class Stack{
  private:
    vector<int> vec;

  public:
    Stack();
  void push(int);
    int peek();
    void pop();
    bool empty();
};
