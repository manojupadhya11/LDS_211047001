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
shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT); //creates shared memory segment with key 2345, having size 1024 bytes. IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permisions on the shared segment
printf("Key of shared memory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
printf("Process attached at %p\n",shared_memory); //this prints the address where the segment is attached with this process    
//Initializing variable.
char str[100];  
int vowels=0;
    
    //Accepting input.
printf(" Enter  the string : ");
scanf("%[^\n]%*c", str);
    
    //Initializing for loop. 
for(i=0;str[i];i++)  
 {
   if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U')
   {
	vowels++;
    }
 }
 	
    //Printing the count of vowels.
    //printf(" Total number of vowels in the string = %d\n",vowels);

char scount[100];  //taking sproduct to convert the int to string then to print

sprintf(scount, "%d", vowels);

strcpy(shared_memory, scount);
printf("Count of Vowels : %s\n",(char *)shared_memory);


printf("\n");
//Reading from shared memory
printf("Key of shared memory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
printf("Process attached at %p\n",shared_memory);
printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}




