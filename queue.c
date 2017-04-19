#include "queue.h"
#include "job.h"
#include <stdlib.h>

Queue* CreateQueue() {
	Queue * queue = (Queue*)malloc(sizeof(Queue));
	if (!queue) {
		return NULL;
	}
	queue->size = 0;
	queue->first = NULL;
	return queue;
}
void DestroyQueue(Queue * queue) {
	Job* temp = queue->first;
	for (int i = 0; i < queue -> size; i++) {
		DestroyJob(temp);
		temp++;
	}
	free(queue);
	queue = NULL;
}
void Enqueue(Queue * queue, Job * job) {
	Job* temp = queue->first;
	for (int i = 0; i < queue->size; i++) {
		temp = temp->next;
	}
	temp->next = job;
	queue->size++;
}
Job* Dequeue(Queue * queue) {
	Job* temp;
	if (queue->size == 0) {
		return NULL;
	}
	temp = queue->first;
	if (queue->size >= 2) {
		queue->first = queue->first->next;
		return temp;
	}
	else return NULL;
}
int GetQueueSize(Queue * queue) {
	return queue->size;
}



