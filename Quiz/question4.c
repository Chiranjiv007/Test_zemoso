#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

// Default dictionary
#define DICTIONARY "dictionaries/large"
#define SIZE 40

struct queue {
    char* items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

int main(void)
{

	char source[MAX_LENGTH], destination[MAX_LENGTH];
	bool loaded = load(DICTIONARY);

	get_string("source: ",source);
	get_string("Destination: ",destination);

	// Exit if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", DICTIONARY);
        return 1;
    }

    travel(source,destination);

	
	
	return 0;
}

void get_string(const char call_for_var[MAX_LENGTH],int &input[MAX_LENGTH])
{
    
    printf("%s\n", call_for_var);
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input)-1]='\0';

    return;
}

void travel()
{



	if(strlen(source) != strlen(destination))
	{
		printf("Not possible\n");
		return;
	}

	struct queue* q =createQueue();

	bfs

	int checkpoint[strlen(source)] = {-1};

	while(source != destination)
	{
		for(int i = 0; i < strlen(source); i++)
		{
			for(int j = 0; j < strlen(source); j++)
			{
				if(j != checkpoint[i])
				{
					char *temp;
					temp = source;


					if(source[j] == destination[j])
					{
						continue;
					}
					source[j] = destination[j];
					

					if(check(source))
					{
						check_point[i] = j;
						break;
					}
					else
					{
						source = temp;
					}
				}
			}

		}

	}
}

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, char* value){
    if(q->rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

char* dequeue(struct queue* q){
    char* item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    char* i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%s ", q->items[i]);
        }
    }    
}