
#include "node.h"

Node* createNode(Card data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node* insertAtEnd(Node* head, Card data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* last = head->prev;

    last->next = newNode;
    newNode->prev = last;

    newNode->next = head;
    head->prev = newNode;

    return head;
}

void deleteNode(Node** head, Node* del) {
    if(*head == NULL || del == NULL)
        return;

    if(*head == del)
        *head = del->next;

    if(del->next != NULL)
        del->next->prev = del->prev;

    if(del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void display(Node* head) {
    Node* itr = head;
    do {
        printf("%s\n", itr->data.name);  // Modify this to print your Card struct
        itr = itr->next;
    } while(head != itr);
}


Node* createDeck() {
    FILE* file = fopen("card_data.txt", "r");
    if (file == NULL) {
        printf("No se puede abrir el archivo.\n");
        return NULL;
    }

    Card allCards[20];
    int cardCount = 0;
    

    while (!feof(file)) {
        allCards[cardCount].name = (char*) malloc(sizeof(char) * 50);
        allCards[cardCount].description = (char*) malloc(sizeof(char) * 100);
        allCards[cardCount].type = (char*) malloc(sizeof(char) * 50);
        fscanf(file, "%[^,],%[^,],%[^,],%d,%d\n", allCards[cardCount].name, allCards[cardCount].description, allCards[cardCount].type, &(allCards[cardCount].value_use), &(allCards[cardCount].value_damage));
        cardCount++;
    }

    fclose(file);

    srand(time(NULL));
    Node* deck = NULL;
    for (int i = 0; i < 6; i++) {
        int randomIndex = rand() % cardCount;
        deck = insertAtEnd(deck, allCards[randomIndex]);
    }

    return deck;
}
void printDeck(Node* deck) {
    // Comprobamos si el mazo está vacío
    if (deck == NULL) {
        printf("El mazo está vacío.\n");
        return;
    }

    printf("Mazo de cartas:\n");

    // Recorremos el mazo e imprimimos cada carta
    Node* temp = deck;
    int i = 1;
    do {
        Card card = temp->data;
        printf("Carta %d:\n", i);
        printf("Nombre: %s\n", card.name);
        printf("Descripción: %s\n", card.description);
        printf("Tipo: %s\n", card.type);
        printf("Valor de uso: %d\n", card.value_use);
        printf("Valor de daño: %d\n\n", card.value_damage);
        temp = temp->next;
        i++;
    } while(temp != deck);
}

