
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include "priority-queue.h"

using namespace std;

class Comparator{

  public:
  Comparator() {}
  
  bool operator()(pair<int, string> a, pair<int, string> b){
    bool ans = a.second < b.second;
    return ans;
   }

};

int main(){
  PriorityQueue pq;
    int n, v, i;

    /*
    cin >> n;
    while(n--){
	cin >> v;
	pq.push(v);
    }

    while(!pq.empty()){
	printf("%d ", pq.top());
	pq.pop();
    }
    printf("\n");*/

    // Colas de prioridad STL
    /*
      priority_queue<int, vector<int>, Comparator> q;

    
    cin >> n;
    while(n--){
	cin >> v;
       q.push(v);
    }

    printf("Tamaño: %d\n", q.size());

    while(!q.empty()){
	printf("%d ", q.top());
	q.pop();
    }
    printf("\n");
    */

    priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> q2;
    q2.push(make_pair(3, "hola"));
    q2.push(make_pair(22, "super"));
    q2.push(make_pair(12, "mundo"));
    q2.push(make_pair(1, "cruel"));
    q2.push(make_pair(22, "hola"));
    q2.push(make_pair(19, "cruel"));

    while(!q2.empty()){
      printf("(%d, %s)\n", q2.top().first, q2.top().second.c_str());
      q2.pop();
    }
 
    return 0;
}
