
#include "tree.h"

int main(){
    Tree* arb1 = new Tree(1, NULL, NULL);
    Tree* arb2 = new Tree(5, NULL, NULL);
    Tree* arb3 = new Tree(6, NULL, NULL);
    Tree* arb4 = new Tree(2, arb1, NULL);
    Tree* arb5 = new Tree(9, arb4, arb2);
    Tree* arb6 = new Tree(3, arb3, NULL);
    Tree* arb7 = new Tree(8, arb5, arb6);

    int v = arb7->addElements();
    printf("Suma elementos = %d\n", v);
    arb7->preorder();
    printf("\n");
    arb7->posorder();
    printf("\n");

    return 0;
}
