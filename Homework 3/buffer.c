
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1
typedef int buffer_item;
#define BUFFER_SIZE 8

buffer_item START_NUMBER;

int insert_item(buffer_item item);

int remove_item(buffer_item *item);


buffer_item buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int insertPointer = 0, removePointer = 0;

void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item)
{
    /* Implementation of the insert_item() function */
	if(insertPointer>=BUFFER_SIZE) //return to beginning of buffer
		insertPointer=0;
	if(insertPointer<BUFFER_SIZE){
		buffer[insertPointer]=item;
		insertPointer++;
	}
	else
		return -1;
	return 0;
}


int remove_item(buffer_item *item)
{
	/* Implementation of the remove_item function */
	if(removePointer>=BUFFER_SIZE)	//return to beginning of buffer
		removePointer=0;
	if(removePointer>=0&&removePointer<BUFFER_SIZE){
		*item = buffer[removePointer];
		removePointer++;
	}
	else
		return -1;
	return 0;
}


int main(int argc, char *argv[])
{
/* 1. Get command line arguments argv[1],argv[2],argv[3],argv[4] */
/* 2. Initialize buffer */
/* 3. Create producer thread(s) */
/* 4. Create consumer thread(s) */
/* 5. Sleep */
/* 6. Exit */

	int sleepTime, producerThreads, consumerThreads;
	int i, j;

	if(argc != 5)
	{
		fprintf(stderr, "Usage: <sleep time> <producer threads> <consumer threads> <start number>\n");
		return -1;
	}

	sleepTime = atoi(argv[1]);
	producerThreads = atoi(argv[2]);
	consumerThreads = atoi(argv[3]);
	START_NUMBER = atoi(argv[4]);

	/* Initialize the synchronization tools */
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, BUFFER_SIZE);
	pthread_mutex_init(&mutex, NULL);

	/* Create the producer and consumer threads */
	pthread_t pro, con;
	for(int i=0; i<producerThreads;i++){
		pthread_create(&pro, NULL, producer, START_NUMBER); //create producers
	}
	for(int j=0; j<consumerThreads;j++){
		pthread_create(&con, NULL, consumer, NULL); //create consumers
	}

	/* Sleep for user specified time */
	sleep(sleepTime);

	return 0;
}

void *producer(void *param)
{
	/* Implementation of the producer thread -- refer to Figure 5.26 on page 256 */
	buffer_item item;

	while(TRUE){
		sleep(1);
		item=START_NUMBER;

		sem_wait(&empty); //lock empty semaphore if !0
		pthread_mutex_lock(&mutex); //mutex lock

		if(insert_item(item)){
			fprintf(stderr, "Insert into buffer failed\n");
		}
		else{
			printf("Producer %u produced %d \n",(unsigned int)pthread_self(), item);
	 		START_NUMBER++;
		}
		
		pthread_mutex_unlock(&mutex); //mutex unlock
    		sem_post(&full); //increment full semaphore
	}
}

void *consumer(void *param)
{
	/* Implementation of the consumer thread -- refer to Figure 5.26 on page 256 */
	buffer_item item;

	while(TRUE){
		sleep(2);
		sem_wait(&full); //lock full semaphore
    		pthread_mutex_lock(&mutex); //mutex lock

		if(remove_item(&item)){
			fprintf(stderr, "Removal from buffer failed\n");
		}
		else
			printf("Consumer %u consumed %d \n",(unsigned int)pthread_self(), item);

		pthread_mutex_unlock(&mutex); //mutex unlock
    		sem_post(&empty); //increments empty semaphore
	}
}
