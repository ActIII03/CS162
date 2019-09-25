#include "cs162_list.h"


//Implement the following functions for Lab #8

//Insert a node at the beginning of a linear linked list
void list::insert(int to_add)
{
	//Step #5 - Write the code here
    if(!head)
        return;
    else
    {
        node * temp = new node;
        temp -> data = to_add;
        temp -> next = head;
        head = temp;
    }
}

//Count the number of nodes in the LLL, returning the result
//Add a new node to the front of the list
//with the count as the data member
int list::count_and_insert()
{
     	//Step #6 - Write the code here
    if(!head) //1st Case
        return 0;

    int count = 0;

    if(!head -> next)  //Is there only one node
    {
        ++count;
        node * temp = new node;  //Create a temp node that points to the new node
        temp -> data = count;    //Place new data into new node
        temp -> next = head;     //Assign the next point from struct node to head
        head = temp;             //Point head to temp, placing it at the beginning
        return count;            //Return count
    }

    else            //This is for multiple nodes
    {
        node * current = head;  //Set pointer to head so we can begin traversal
        
        while(current)          //Same as while(current != NULL) This is the technique to traverse
        {
            ++count;
            current = current -> next;  //Update current pointer to prevent an infinite loop
        }

        node * temp = new node;         //After traversal, we want to create a node to held new data member
        temp -> data = count;           //Place count at the beginning of the list
        temp -> next = head;            //We assign this new node to the beginning of the list
        head = temp;                    //Update the head
        return count;
    }
}

//Append a node to the end of a linear linked list
void list::append(int to_add)
{
        //Step #7 - Write the code here
    if(!head)  //Add stuff here
    {
        head = new node;
        head -> data = to_add;
        head -> next = NULL;
        return;
    }
    
    /*if(!head -> next)       //Is there only one node
    {
        node * temp = new node;
        temp -> data = count;    //Place new data into new node
        temp -> next = head;     //Assign the next point from struct node to head
        head = temp;             //Point head to temp, placing it at the beginning
    }*/

    else        //Multiple nodes
    {
        node * current = head;

        while(current -> next != NULL)          //Technique for traversing till the last node
        {
            current = current -> next;
            current -> next  = new node;


}


//Remove the last node from the list
void list::remove_last()
{
//Step #7 - Write the code here
}

//Deallocate all nodes (Destructor)
list::~list()
{
    //Step #8 - Write the code here
}

//Challenge - 
void list::copy_last()
{

}      

