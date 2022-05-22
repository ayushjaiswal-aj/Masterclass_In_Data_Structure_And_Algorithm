#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node {
    int element;
    struct Node *next;
    struct Node *prev;
};

void test();

int main(void){
    test();

    exit(EXIT_SUCCESS);
}

void text(){
    int i;

    struct Node *node1 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *) malloc(sizeof(struct Node));

    struct Node *nodeRun = NULL;

    node1->element = 10;
    node2->element = 20;
    node3->element = 30;
    node4->element = 40;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;
    
    nodeRun = node1;
    while(nodeRun != NULL){
        printf("element: %d", nodeRun->element);
        nodeRun = nodeRun->next;
    }
}