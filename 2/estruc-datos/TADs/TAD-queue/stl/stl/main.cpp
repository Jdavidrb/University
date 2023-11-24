/*
Colas STL
Octubre 27 de 2023

queue:

push
front
pop
empty
size

 */

#include <queue>
#include <iostream>

using namespace std;

int main(){
  queue<int> q;
  q.push(10);
  q.push(4);
  q.push(3);
  q.push(11);

  while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}
