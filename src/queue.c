#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if(q == NULL || proc == NULL) return;
        if(q->size < MAX_QUEUE_SIZE) {
                q->proc[q->size++] = proc;
        } else {
                printf("Cannot enqueue");
        }
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if(empty(q)) return NULL;
        // int max_index = 0;
        // for(int i = 1; i < q->size; i++) {
        //         if(q->proc[i]->priority > q->proc[max_index]->priority) {
        //                 max_index = i;
        //         }
        // }
        // struct pcb_t * highest_priority_process = q->proc[max_index];
        // //delete a highest and move the array
        // for(int i = max_index; i < q->size - 1; i++) {
        //         q->proc[i]= q->proc[i+1];
        // }
        // q->size--;
        // return highest_priority_process;
        struct pcb_t *first_proc = q->proc[0];
        //remove first process from queue 
        for(int i = 0; i < q->size - 1; i++) {
                q->proc[i] = q->proc[i+1];
        } 
        q->size--;
        return first_proc;
}

