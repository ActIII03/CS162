#include <iostream>

const int MAX = 100;

class string{
    public:
        //Constructor
        string(): str(NULL), len(0){}; 
        //Copy constructor
        string(const string &);
        //User-defined type conversion
        string(const char *, const int);
        //Destructor
        ~string();
        //Assignment operator <--- Lvalue
        string & operator=(const string &); 
        //Extraction operator <--- Lvalue
        friend ostream & operator<<(ostream &, const string &);
        //Insertion operator <--- Lvalue
        friend istream & operator>>(istream &, string &);
        //Compound addition operator <--- Lvalue
        string & operator+=(const string &);
        string & operator+=(char * );       
        //Addition operator <--- Rvalue
        string & operator+(const string &, char *);
        string & operator+(char *, const string&); 
        string & operator+(const string &, const string &);
        //Subscript operator <--- Lvalue
        char & operator[](int) const;
        //Prefix:
        //in the prefix form, the residual value is the post incremented or post decremented value
        string & operator++();
        string & operator--();
        //Postix:
        //in the postfix form, the residual value is the pre incremented or pre decremented valu
        string operator++(int);
        string operator--(int);


    private:
        char * str;
        int data
        int len;
};

class node{
    string obj;
    node * next;
}

class list{
    public:
        //Default constructor
        list(): head(0){}
        //Copy constructor
        list (const list &);
        ~ list();
        list & operator = (const list &);
        friend ostream & operator << (ostream &, const list &);
        friend istream & operator >> (istream &, list &);
        friend list operator + (const list &, const list &);
        friend list operator + (const list &, const string &);
        friend list operator + (const string &, const list &);
        list & operator += (const list &);
        list & operator += (const string &);
        bool operator == (const list &) const;
        bool operator != (const list &) const;
        string & operator [] (int) const;
        string & operator ++ (); //prefix
        string operator ++ (int); //postfix

    private:
        node * head, * ptr, * tail;
};























}




