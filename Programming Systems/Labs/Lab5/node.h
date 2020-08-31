


//This file (node.h has the classes for managing an employee's
//performance review, implemented using a binary search tree.

//A node "is a" review (the data) plus the pointers to manage
//the left and the right. The beauty of this design is that the
//node class can (a) follow the rules of OOP and at the same
//time (b) allow the client direct access to the review's
//functionality (without having it implemented in the node class
//itself!)

class review
{
      public:
	    review( const char * initial_review);
            review( const review &);
            ~review();

	        //Just like string compare, returns zero if there
            //is a match, less than zero if the root's data is
            //less than the argument, and greater than otherwise
            int compare(const char * match) const;
            void display() const;
       
      protected:
            char * data;
};

class node: public review
{
      public:
             node(const char * review);
             node(const review &);

             node *& go_left();
             node *& go_right();
             void connect_left(node * connection);
             void connect_right(node * connection);
      protected:
             node * left;
             node * right;
};

