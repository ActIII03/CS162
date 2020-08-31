#include "list_operator.h"

//Modifies first operand ---> (string)
string & string::operator=(const string & s2)
{
    //Check for self-assingment
    if(this == &s2)
        //Return this dereferenced which is a string obj by ref, instead of pointer
        return *this; 
    //If current obj has a value
    if(str)
        //Then delete any dynamic memory allocated
        delete [] str;

    str = new char[s2.len + 1];
    strcpy(str, s2.str);
    len = s2.len;
    return *this;
}

//Both Insertion and Extraction operators are overloaded as friend function because first operand isn't of string type
ostream & operator<<(ostream & out, const string & s)
{
    out << s.str;
    return out;
}

istream & operator>>(istream & in, string & s)
{
    //Create temp variable to hold inputted data
    char buffer[MAX];
    in >> buffer;
    s.len = strlen(buffer);
    s.str = new char[s.len + 1];
    strcpy(s.str, buffer);
    return in;
}

//Modifies first operand 
string & string::operator+=(const string & s)
{
    //Copy length
    len += s.len;
    //Allocate temp char
    char * temp = new char[s.len + 1];
    //Copy from s --> temp
    strcpy(temp, str);
    //Concatenate temp w/ s2.str
    strcat(temp, s2.str);
    //Copy over pointer from temp ---> str
    str = temp;
    //Return *this 
    return * this;
}

string & string::operator+=(char * lit){}

//Modifies first operand by concatenating it with the second operand
//Elimantes the uneccessary copy constructor invocation by explicitly using constructor on the return statement
string & string::operator+(const string & s, char * lit)
{
    char * temp = new char[strlen(lit) + 1];
    strcpy(temp, lit);
    strcat(s.str, temp);
    return string(temp);
}

string & string::operator+(char * lit, const string & s){}
string & string::operator+(const string & s, const string & s1){}

//Always implement as a mbr function
char & string::operator[](int num)
{
    return str[num];
}


//List class implementation
list::list(const list & l)
{
    //Check if incoming obj has items
    if(!l.head)
        head = tail = ptr = NULL;
    else
    {
        head = new node;
        head -> obj = l.head -> obj;

        //Create local variables to start copying from l
        node * dest = head;
        node * source = l.head;
        //Traverse and copy incoming list obj
        while(source)
        {
            dest -> next = new node;
            dest = dest -> next;
            //Uses the overloaded assignment operator to copy over contents
            dest -> obj = source -> obj; 
        }
        dest -> next = NULL;
        tail = dest;
        ptr = head;
    }

}

list & list::operator=(const list & l)
{
    //Check for self-assignment
    if(this == &l) return *this;
    //Check contents of this obj before assigning new contents
    node * current;
    while(head)
    {
        current = head -> next;
        delete head;
        head = current;
    }
    //Check if second operand has items
    if(!l.head)
        head = tail = ptr = NULL;
    else
    {
        head = new node;
        head -> obj = l.head -> obj;

        //Create local variables 
        node * dest = head;
        node * source = l.head;
        while(source)
        {
            dest -> next = new node;
            dest = dest -> next;
            dest -> obj = source -> obj;

        }

        dest -> next = NULL;
        tail = dest;
        ptr = head;
    }

}





