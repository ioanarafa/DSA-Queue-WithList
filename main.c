#include <stdio.h>
#include <stdlib.h>

//coada cu lista

typedef struct _queue{
    int key;
    struct _queue* next;

}queue;

//1
queue* creaza(int givenkey){
    queue* p = (queue*)malloc(sizeof(queue));
    p->key = givenkey;
    p->next = NULL;
    return p;
}

//2
void enqueue(int givenkey, queue** first, queue** last)
{
    queue* p = creaza(givenkey);
    if(*first == NULL)
    {
        *last = p;
        *first = p;
    }
    else{
        (*last)->next = p;
        *last = p;
    }
}

//3
int dequeue( queue** first, queue** last){

    queue* p = *first;
    int  val = p->key;
    p= p->next;
    free(*first);
    *first = p;

    if(*first == NULL) *last= NULL;

    return val;

}

//4
void afiseaza(queue* first){
    queue* p = first;
    while(p != NULL)
    {
        printf("%d ", p->key);
        p= p->next;
    }

    printf("\n");
}

int main()
{
    queue* first = NULL;
    queue* last = NULL;

    enqueue(3, &first, &last);
    enqueue(1, &first, &last);
    enqueue(5, &first, &last);
    afiseaza(first);

    dequeue( &first, &last);
    dequeue( &first, &last);
    afiseaza(first);

    return 0;
}
