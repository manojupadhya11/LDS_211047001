#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
int i;
void *shared_memory;
char buff[100];
int shmid;
int firstnumber, secondnumber,product;
shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT); //creates shared memory segment with key 2345, having size 1024 bytes. IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permisions on the shared segment
printf("Key of shared memory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
printf("Process attached at %p\n",shared_memory); //this prints the address where the segment is attached with this process

printf("Enter the first number\n");
scanf("%d",&firstnumber);
printf("Enter the second number\n");
scanf("%d",&secondnumber);
product = firstnumber*secondnumber;

char sproduct[100];  //taking sproduct to convert the int to string then to print

sprintf(sproduct, "%d", product);
strcpy(shared_memory, sproduct);

printf("You wrote the product of   %d*%d : %s\n", firstnumber,secondnumber,(char *)shared_memory);


//Reading from shared memory
printf("Key of shared memory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
printf("Process attached at %p\n",shared_memory);
printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}

