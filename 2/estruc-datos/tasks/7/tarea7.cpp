/* 
Jose David Ruano Burbano 
Tarea 7 Estructura de datos 
21-11-2023

*/

#include <stack>
#include <queue>
#include <map>
#include <deque>

using namespace std;
// 1
void eliminarPoscicionesPila(stack<int> & pil, deque<int> &l){
  	
  int i;	
  for(i = 0; i < l.size();i++){
    int pos = l[i];
    stack<int> aux;
    int j = 0;
    while(j < pos-1){
      aux.push(pil.top());
      pil.pop();
    }
    pil.pop();
    while(!aux.empty()){
      pil.push(aux.top());
      aux.pop();
    }
  }
}
// 3
bool verificarOrdenadoCola(queue<int> & que){
  bool flag_min = true;
  bool flag_max = true;
  bool flag;
  queue<int> q = que;
  
  for(int i = 0; i < q.size() && flag; i++){
    
    int num1 = q.front();
    
    q.pop();
    int num2 = q.front();
    q.pop();
    if(num1 > num2)
      flag_min == false;
    else 
      flag_max == false;
    if(!flag_max && !flag_min) 
      flag = false;
    q.push(num1);
    q.push(num1);
  }
  bool ans;
  if (flag_max || flag_min)
    ans = true;
  else 
    ans = false;
  return ans;      
}
// 4
class comparator{
  public:
  comparator();
  bool operator()(int a, int b){
    bool ans;
    ans = a < b;
    return ans;
  }
};

int obtenerMenorCosto(deque<int> &l){
  priority_queue<int,vector<int>,comparator> pq; 
  for(int i = 0; i < l.size(); i++){
    pq.push(l[i]);
  }
  int cost = 0;
  int aux;
  int n1 = pq.top();
  pq.pop();
  cost = n1;
  while(!pq.empty()){ 
    int n2 = pq.top();
    pq.pop();
   
    cost += n2;
    
  }
  return cost;
}

// 5
bool verificarParentesisBalanceados(string cad){
  bool ans;
  stack<char> pil;
  int tam = cad.size();
  for(int i = 0; i < tam; i++){
    
    if(cad[i] == '(')
    pil.push('(');
  
    else if (cad[i] == ')' && !pil.empty())
    pil.pop();
    
  }
  if (pil.empty())
    ans = true;
  else ans = false;
  return ans;
}

// 6
int verificarRepetidos(queue<int> &col){
  int ans = 0;
  queue<int> q = col;
  map<int,int> m;
  while(!q.empty()){
    int value = q.front();
    q.pop();
    m[value]++;
    if (m[value] > 1){
      ans++;
   
    }
  }
  return ans;
}
// 7
map<char, deque<int>> obtenerPosicionesOcurrencias(string cad) {
    map<char, deque<int>> ans;
    for(int i = 0; i < cad.size(); i++){
        ans[cad[i]].push_back(i);
    }
    return ans;
}

// 8
bool verificarRepetidosCola(queue<int> &col){
  queue<int> q = col;
  bool ans = false;
  bool flag;
  map<int,int> m;
  while(!q.empty() && flag){
     int value = q.front();
     q.pop();
     m[value]++;
     if(m[value] > 1){
       flag = false;
       ans = true;
     }
  }

  return ans;
}  

// 9
stack<int> filtrarNparesCola (queue<int> &col, int N){
  stack<int> ans;
  queue<int> q = col;
  int i = 0;
  while(i < N && !q.empty()){
    int value = q.front();
    q.pop();
    if(value % 2 == 0){
      ans.push(value);
      i++;
    }
  }
  return ans;
}
