#include "queue.h"
#include "job.h"
#include <stdlib.h>
#include <stdio.h>

Queue * CreateQueue() {
	Queue * queue = (Queue*)malloc(sizeof(Queue));
	if (!queue) {
		return NULL;
	}
	queue->size = 0;
	queue->first = NULL;
	return queue;
}
void DestroyQueue(Queue * queue) {
	if(queue != NULL){
		Job* temp = queue->first;
		int size = queue -> size;
		for (int i = 0; i < size; i++) {
			temp = Dequeue(queue);
			DestroyJob(temp);

		}
		queue -> first = NULL;
	}
}
void Enqueue(Queue * queue, Job * job) {
	Job* temp;
	if(job == NULL){

	}
	else if (queue->size == 0) {
		queue->first = job;
		queue->size++;
	}
	else {
		temp = queue->first;
		for (int i = 0; i < queue->size-1; i++) {
			temp = temp->next;
		}
		temp->next = job;
		queue->size++;
	}
	
}
Job * Dequeue(Queue * queue) {
	Job* temp;
	if (queue->size == 0) {
		return NULL;
	}
	temp = queue->first;
	if (queue->size >= 2) {
		queue->first = queue->first->next;
		queue->size=queue->size-1;
		return temp;
	}
	queue->first = NULL;
	queue->size= 0;
	return temp;
}
int GetQueueSize(Queue * queue) {
	int fin;
	if(queue == NULL) fin = -1;
	else fin = queue->size;
	return fin;
}
