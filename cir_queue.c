#include <stdio.h>
#include <stdlib.h>

#define QSIZE 100  /*max size of the queue space*/
#define TEST_DATA1 12
#define TEST_DATA2 43 /*test data*/

typedef int data_type;
typedef struct {
	data_type data[QSIZE];
	int front; /*head pointer*/
	int rear;  /*tail pointer*/
	int count; /*counter,note down the number of the elements */
	
}cir_queue;

void initial(cir_queue *q)
{
	q->front = q->rear = 0;
	q->count = 0;
}

int is_empty(cir_queue *q)
{
	return (q->front == q->rear);
}

int is_full(cir_queue *q)
{
	return (q->front == q->front + QSIZE - 1);
}

int enqueue(cir_queue *q,data_type data)
{
	if(is_full(q)) {
		printf("Queue overflow\n");
		return -1;
	}
	
	q->count ++;
	q->data[q->rear] = data;
	q->rear = (q->rear + 1) % QSIZE;

	return 0;
}

data_type dequeue(cir_queue *q)
{
	data_type temp;

	if(is_empty(q)) {
		printf("The queue is empty.\n");
		exit(1);
	}

	temp = q->data[q->front];
	q->count --;
	q->front = (q->front + 1) % QSIZE;
	
	return temp;
}

data_type front(cir_queue *q)
{
	if(is_empty(q)) {
		printf("The queue is empty.\n");
		exit(1);
	}

	return q->data[q->front];
}

int main(int argc, char *argv[])
{
	cir_queue queue;

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
