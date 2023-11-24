/*
Pilas STL

push
top    (peek)
pop
empty
size

 */

#include <stack>
#include <iostream>

using namespace std;

int main(){
  stack<int> p;
  p.push(10);
  p.push(11);
  p.push(6);
  p.push(4);

  cout << "Tamaño: " << p.size() << endl;
  
  while(!p.empty()){
    cout << p.top() << endl;
    p.pop();
  }


  return 0;
}
