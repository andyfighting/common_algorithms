#include <stdio.h>
#include <stdlib.h>

#define TEST_DATA1 12
#define TEST_DATA2 43 /*test data*/

typedef char data_type;

typedef struct node {
	data_type data;
	struct node *next;
}queue_node;

typedef struct {
	queue_node *front; /*head pointer*/
	queue_node *rear;  /*tail pointer*/
}link_queue;

void initial(link_queue *q)
{
	q->front = q->rear = NULL;
}

int is_empty(link_queue *q)
{
	return ((q->front == NULL) && (q->rear == NULL));
}

void enqueue(link_queue *q,data_type data)
{
	/*new element*/
	queue_node *p = (queue_node *)malloc(sizeof(queue_node));
	p->data = data;
	p->next = NULL;
	
	if(is_empty(q)) {
		/*insert element into empty queue*/
		q->front = q->rear = p;
	}
	else {
		q->rear->next = p;
		q->rear = p;
	}
}

data_type dequeue(link_queue *q)
{
	data_type temp;
	queue_node *p;

	if(is_empty(q)) {
		printf("The queue is empty.\n");
		exit(1);
	}

	p = q->front;
	temp = p->data;
	q->front = p->next;

	/*if one element*/
	if(q->rear == p)
		q->rear = NULL;
	
	free(p);
	
	return temp;
}

data_type front(link_queue *q)
{
	if(is_empty(q)) {
		printf("The queue is empty.\n");
		exit(1);
	}

	return q->front->data;
}

int main(int argc, char *argv[])
{
	link_queue queue;

	data_type one,two;
	
	initial(&queue);

	enqueue(&queue,TEST_DATA1);
	
	enqueue(&queue,TEST_DATA2);

	/*data fetch*/
	one = front(&queue);
	dequeue(&queue);

	two = front(&queue);
	dequeue(&queue);

	printf("data one:%d | two : %d\n",one,two);

	return 0;
}
