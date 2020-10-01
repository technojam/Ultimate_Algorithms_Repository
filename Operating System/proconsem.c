#include<stdio.h>
     #include<pthread.h>
     #include<sys/types.h>
     #include<unistd.h>
     #include<stdlib.h>
     #include<semaphore.h>
     sem_t empty,full,mutex;
     char buf[10];
     void *producer(void *arg)
    {
        int i;
        for(i=0;i<10;i++)
        {
            sem_wait(&empty);
            sem_wait(&mutex);
            buf[i]=i;
            printf("item produced is %d \n",buf[i]);
            sem_post(&mutex);
            sem_post(&full);
            sleep(2);
        }
        pthread_exit("consumer\n");
    }
    void *consumer(void *arg)
    {
        int j;
        //printf("inside consumer \n");
        for(j=0;j<10;j++)
        {
            sem_wait(&full);
            sem_wait(&mutex);
            sleep(1);
            j=buf[j];
            printf("consumed item is %d \n",buf[j]);
            sem_post(&mutex);
            sem_post(&empty);
            sleep(1);
            
        }
    }
    
    int main()
    {
        void *status;
        pthread_t pid1,pid2;
        sem_init(&empty,0,1);
        sem_init(&full,0,0);
        sem_init(&mutex,1,1);
        pthread_create(&pid1,NULL,producer,NULL);
        pthread_create(&pid2,NULL,consumer,NULL);
        pthread_join(pid1,&status);
        pthread_join(pid2,&status);
       // printf("status %s\n",(char*)status);
        return 0;
    }