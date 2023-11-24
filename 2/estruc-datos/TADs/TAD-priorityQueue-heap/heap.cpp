
#include "heap.h"

Heap::Heap(){}

Heap::Heap(vector<int>& m){
    mont = vector<int>(m);
    int i, l = mont.size() / 2 - 1;
    for(i = l; i >= 0; --i)
	heapify(i);
}

int Heap::getLeft(int i){
    int ans = 2 * i  + 1;
    return ans;
}

int Heap::getRight(int i){
    int ans = 2 * (i + 1);
    return ans;
}

int Heap::getParent(int i){
    int ans = (i - 1) / 2;
    return ans;
}

void Heap::heapify(int i){
    int l = getLeft(i), r = getRight(i), m, aux;
    if(l < mont.size() && mont[l] > mont[i])
	m = l;
    else
	m = i;
    if(r < mont.size() && mont[r] > mont[m])
	m = r;
    if(m != i){
	aux = mont[i];
        mont[i] = mont[m];
	mont[m] = aux;
	heapify(m);
    }
}

int Heap::getMax(){
    int ans = mont[0];
    return ans;
}

void Heap::deleteMax(){
    int aux = mont[0];
    mont[0] = mont[mont.size() - 1];
    mont[mont.size() - 1] = aux;
    mont.pop_back();
    heapify(0);
}

void Heap::addElement(int e){
    int aux, i, p;
    bool flag = true;
    mont.push_back(e);
    i = mont.size() - 1;
    while(i > 0 && flag){
	p = getParent(i);
	if(mont[p] < mont[i]){
	    aux = mont[i];
	    mont[i] = mont[p];
	    mont[p] = aux;
	    i = p;
	}
	else
	    flag = false;
    }
}

void Heap::print(){
    int i;
    for(i = 0; i < mont.size(); ++i)
	printf("%d ", mont[i]);
    printf("\n");
}

bool Heap::empty(){
    bool ans = mont.empty();
    return ans;
}
