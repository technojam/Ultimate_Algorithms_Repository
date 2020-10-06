//Implementation of Circular Queue using Array
/*Circular Queue is a linear data structure in which the operations are performed 
based on FIFO (First In First Out) principle and the last position is connected back 
to the first position to make a circle.*/

#include<bits/stdc++.h> 
using namespace std; 
  
struct Queue 
{ 
    // Initialize front and rear 
    int rear, front; 
  
    // Circular Queue 
    int size; 
    int *arr; 
  
    Queue(int s) 
    { 
       front = rear = -1; 
       size = s; 
       arr = new int[s]; 
    } 
  
    void enQueue(int value); 
    int deQueue(); 
    void displayQueue(); 
}; 
  
  
/* Function to create Circular queue */
void Queue::enQueue(int value) 
{ 
    if ((front == 0 && rear == size-1) || 
            (rear == (front-1)%(size-1))) 
    { 
        printf("\nQueue is Full"); 
        return; 
    } 
  
    else if (front == -1) /* Insert First Element */
    { 
        front = rear = 0; 
        arr[rear] = value; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        arr[rear] = value; 
    } 
  
    else
    { 
        rear++; 
        arr[rear] = value; 
    } 
} 
  
// Function to delete element from Circular Queue 
int Queue::deQueue() 
{ 
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return INT_MIN; 
    } 
  
    int data = arr[front]; 
    arr[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return data; 
} 
  
// Function displaying the elements of Circular Queue 
void Queue::displayQueue() 
{ 
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", arr[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", arr[i]); 
    } 
} 
  
int main() 
{ 
    Queue q(5); 
  	
    // Inserting elements in Circular Queue 
    q.enQueue(14); 
  
    // Display elements present in Circular Queue 
    q.displayQueue(); 
  
    // Deleting elements from Circular Queue 
    printf("\nDeleted value = %d", q.deQueue());  
  
    q.displayQueue(); 
  
    q.enQueue(9); 
  
    q.displayQueue(); 
  
    q.enQueue(20); 
    return 0; 
} 
