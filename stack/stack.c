//Implementation of a menu driven program for stack operations
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5 //define SIZE

int stack[SIZE], top_of_stack;

//function initialization for stack operations 

void Push(int stack[], int); //to insert the element in to stack
void Pop(int stack[]);  //to remove an element from stack
void Peek(int stack[] );
void Display(int stack[]);  //to display the contents of stack

void main(){

int num=0;
int option = 0;
top_of_stack = -1;
while(1)
{
    printf("\n 1: Push \n 2: Pop \n 3: Peek \n 4: Display \n 5: Exit \n Enter your choice: ");
    scanf("%d", &option);
    switch(option)
    {
	case 1: 
		printf("Push\n");
		printf("Enter the item to insert into stack\n");
		scanf("%d", &num);
		Push(stack,num);
	break;

	case 2: 
		printf("Pop\n");
	
		Pop(stack);
	break;

	case 3: 
		printf("Peek \n");
		Peek(stack);
	break;

	case 4: 
		printf("Display\n");
		Display(stack);
	break;

	case 5: 
		exit(0);
	break;
	
	default:
		 printf("choose the valid option\n");
	break;
    }
 }
}
//function definition for the Push function
void Push(int stack[], int num)
{
 if(top_of_stack == SIZE-1)
 {
  printf("can not insert elements into stack, STACK OVERFLOW!!!!!\n"); //checking overflow condition
  return;
 }
 top_of_stack++;  //incrementing the top_of_stack pointer
 stack[top_of_stack] = num;   //inserting the element in to top of the stack
}

//function definition for poping elements from stack
void Pop(int  stack[]) 
{
 printf("Element will be poped from stack\n");
 int del_num;
 if(top_of_stack == -1)
 {
   printf("Element can not be poped from stack STACK UNDERFLOW!!!!\n"); //checking underflow condition
   return;
 }
 del_num = stack[top_of_stack]; //assign top_of_stack element to del_num
 top_of_stack--;  //decrementing the top_of_stack pointer it will pop the top element
 printf("the deleted element is %d\n",del_num);//printing the poped element 
 return;
}

//function definition for displaying peek value of stack
void Peek(int  stack[])
{
  int peek_val;
  if(top_of_stack == -1)
 {
  printf("can not peek, STACK UNDERFLOW!!!!!"); //checking underflow condition
  return;
 }
 peek_val = stack[top_of_stack];
 printf("the element at top of stack is: %d\n", peek_val);

}

//function definition for displaying the contents of stack
void Display(int stack[])  
{
 printf("Displaying the elements of stack\n");
 int i = 0;
 if(top_of_stack == -1)
 {
   printf("Element can not be poped from stack STACK UNDERFLOW!!!!\n"); //checking underflow condition
   return;
 }
 for(i = top_of_stack; i>=0; i--)
 {
   printf("%d\n",stack[i]);  //displaying the contents of stack
 }
 printf("\n\n");
}



