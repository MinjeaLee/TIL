#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ADT 
typedef struct doublelinkedlist{
    char data;
    struct doublelinkedlist *next;
    struct doublelinkedlist *prev;
}DLL;

typedef struct _list{
    DLL* head;
    DLL* tail;
    int size;
}list;

void init(list *chart){
    DLL *ohead, *otail;
    ohead = (DLL*)malloc(sizeof(DLL));
    otail = (DLL*)malloc(sizeof(DLL));

    chart->head = ohead;
    ohead->prev = NULL;
    ohead->next = otail;

    chart->tail = otail;
    otail->prev = ohead;
    otail->next = NULL;

    chart->size = 2;
}

void add(list *chart, int order, char data){
    if((chart->size) - 1 < order){
        printf("invalid position\n");
        return;
    }

    DLL *temp;
    temp = chart->head;
    DLL *newnode;
    newnode = (DLL*)malloc(sizeof(DLL));
    newnode->data = data;

    for(int i = 0; i < order; i++){
        temp = temp->next;
    }

    newnode->next = temp;
    newnode->prev = temp->prev;

    temp->prev = newnode;
    temp = newnode->prev;
    temp->next = newnode;

    chart->size++;

}

void delete(list *chart, int order){

    if((chart->size) - 2 < order){
        printf("invalid position\n");
        return;
    }

    DLL *temp, *prev_temp, *next_temp;
    temp = chart->head;

    for(int i = 0; i < order; i++){
        temp = temp->next;
    }

    prev_temp = temp->prev;
    next_temp = temp->next;

    prev_temp->next = next_temp;
    next_temp->prev = prev_temp;

    free(temp);

    chart->size--;
}

void get(list *chart, int order){ 
    DLL *temp;
    temp = chart->head;

    if(chart->size - 2 < order){
        printf("invalid position\n");
        return;
    }

    for(int i = 0; i < order; i++){
        temp = temp->next;
    }

    printf("%c\n", temp->data);
}

void print(list *chart){
    DLL *temp;
    temp = chart->head;

    for(int i = 0; i < chart->size - 2; i++){
        temp = temp->next;
        printf("%c", temp->data);
    }
    printf("\n");
}

int main(){
    int n;
    char command;

    int order;
    char data;

    list *array;

    array = (list*)malloc(sizeof(list));
    init(array);

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%c", &command);

        if(command == 'A'){ 
            scanf("%d %c", &order, &data);
            getchar();
            add(array, order, data);
        }
        else if(command == 'D'){
            scanf("%d", &order);
            getchar();
            delete(array, order);
        }
        else if(command == 'G'){
            scanf("%d", &order);
            getchar();
            get(array, order);
        }
        else if(command == 'P'){
            print(array);
            getchar();
        }

    }
        

    return 0;
}