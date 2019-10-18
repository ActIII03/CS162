//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Description: Below are function implementations used in my program

#include "assign1.h"

//Menu Function
void menu(int & decision)
{
    cout << "Which of the option would like to choose?:\n"
         << "(1) Add Food Cart w/ Favorite Food \n(2) Display Food Cart(s) by Food Type \n(3) Delete Favorite Food from Exisiting Cart \n"
         << "(4) Add Top Three Favorite Food to an Existing Cart \n(5) Display Food Cart(s) \n(6) Delete a Food "
         << "\n(7) Quit Program \nChoice(1-7):";
    cin >> decision;
    cin.ignore();
    cin.clear();
}

//Greets user
void greeting()
{
    cout << "Welcome to Food Cart Registery!\n\n";
}

//Read in data from user base off of user's menu choice
int get_char(d_food_cart & new_cart, int menu_choice)
{

    if(menu_choice == 1)
    {
        //Cart Name
        cout << "Please enter the cart's name: ";
        cin.get(new_cart.name, BUFFER_SIZE, '\n'); 
        cin.ignore(100,'\n');
        cin.clear();
        
        //Address Line 1
        cout << "Please enter the cart's address(Example -- 1234 NE John Jones DR): ";
        cin.get(new_cart.c_address.line_1, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();

        //Location
        cout << "Please enter the cart's Location (Example -- Park Avenuce OR 4th Avenue): ";
        cin.get(new_cart.c_address.location, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();
        
        //Food Type
        cout << "Please enter the cart's food type (Example -- Thai): ";
        cin.get(new_cart.type, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();

        //Review   
        cout << "Please enter a review of the cart: ";
        cin.get(new_cart.review, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();

        //Favorite Food
        cout << "Please enter top three favorite food (Example -- Chicken Pad Thai)" ;
        cout << "1:";
        cin.get(new_cart.fav_food.f_1, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();

        cout << "2:";
        cin.get(new_cart.fav_food.f_2, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();
        
        cout << "3:";
        cin.get(new_cart.fav_food.f_3, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();
        cout << "\n";

    }


    if(menu_choice == 2)
    {
        //Food Type
        cout << "Please enter a food type you want to see (Example -- Thai): " ;
        cin.get(new_cart.type, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();
        cout << "\n";

    }
    

    if(menu_choice == 3)
    {

        //Delete Favorite Food
        cout << "Please enter the Food Cart you want to add your favorite food (Example: Stack High Sandwiches): ";
        cin.get(new_cart.name, BUFFER_SIZE, '\n');
        cin.ignore(100, '\n');
        cin.clear();
        
    }


    if(menu_choice == 4)
    {

        cout << "Please enter the Food Cart you want to add your favorite food too (Example: Stack High Sandwiches): ";
        cin.get(new_cart.name, BUFFER_SIZE, '\n');
        cin.ignore();
        cin.clear();
        
    }

    else if(menu_choice == 6)
    {

        cout << "Please enter the Food Cart you want to delete: ";
        cin.get(new_cart.name, BUFFER_SIZE, '\n');
        cin.ignore();
        cin.clear();
        
    }
    return 0;

}

//Constructors
FoodCartList::FoodCartList()
{
    head = NULL;
    tail = NULL;

}

//Constructor for address
address::address()
{
    line_1 = NULL;
    location = NULL;
}

//Constructor for favorite_three
favorite_three::favorite_three()
{
    f_1 = NULL;
    f_2 = NULL;
    f_3 = NULL;
}

//Constructor for food_cart
food_cart::food_cart()
{
    name = NULL;
    review = NULL;
    type = NULL;
}

//Destructor for FoodCartList
FoodCartList::~FoodCartList()
{
    if(head)
    {
        destroy(head);
    }

}

//Destructor for address
address::~address()
{
    if(line_1)
    {
        delete line_1;
        line_1 = NULL;
    }
    if(location)
    {
        delete location;
        location = NULL;
    }
}

//Destructor for favorite_three
favorite_three::~favorite_three()
{
    //Make individual if statement
    if(f_1)
    {
        delete f_1;
        f_1 = NULL;
    }
    if(f_2)
    {
        delete f_2;
        f_2 = NULL;
    }
    if(f_3)
    {
        delete f_3;
        f_3 = NULL;
    }
}

//Destructor for food_cart
food_cart::~food_cart()
{
    if(name)
    {
        delete name;
        name = NULL;
    }
    if(review)
    {
        delete review;
        review = NULL;
    }
    if(type)
    {
        delete type;
        type = NULL;
    }
}

//Add to LLL
int FoodCartList::add_cart(const d_food_cart & add_cart)
{

    //Empty List
    if(!head)
    {

        node * n_cart = new node;
        head = n_cart;
        head -> next = NULL;

        
        //Name
        n_cart -> fd_cart.name = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  
        
        //Line 1
        n_cart -> fd_cart.c_address.line_1 = new char[strlen(add_cart.c_address.line_1)+1];
        strcpy(n_cart -> fd_cart.c_address.line_1, add_cart.c_address.line_1);  

        //Location
        n_cart -> fd_cart.c_address.location = new char[strlen(add_cart.c_address.location)+1];
        strcpy(n_cart -> fd_cart.c_address.location, add_cart.c_address.location);  

        //Review
        n_cart -> fd_cart.review = new char[strlen(add_cart.review)+1];
        strcpy(n_cart -> fd_cart.review, add_cart.review);  
        
        //Food type
        n_cart -> fd_cart.type = new char[strlen(add_cart.type)+1];
        strcpy(n_cart -> fd_cart.type, add_cart.type);  

        //Top Three Favorite Food 
        n_cart -> fd_cart.fav_food.f_1 = new char[strlen(add_cart.fav_food.f_1)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_1, add_cart.fav_food.f_1);  

        n_cart -> fd_cart.fav_food.f_2 = new char[strlen(add_cart.fav_food.f_2)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_2, add_cart.fav_food.f_2);  

        n_cart -> fd_cart.fav_food.f_3 = new char[strlen(add_cart.fav_food.f_3)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_3, add_cart.fav_food.f_3);  

    }

    //One Item in list and add to End of LLL
    else if(head -> next == NULL)
    {
        
        node * n_cart = new node;
        head -> next = n_cart;
        n_cart -> next = NULL;
        tail = n_cart;
        
        //Name
        n_cart -> fd_cart.name = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  
        
        //Line 1
        n_cart -> fd_cart.c_address.line_1 = new char[strlen(add_cart.c_address.line_1)+1];
        strcpy(n_cart -> fd_cart.c_address.line_1, add_cart.c_address.line_1);  

        //Location
        n_cart -> fd_cart.c_address.location = new char[strlen(add_cart.c_address.location)+1];
        strcpy(n_cart -> fd_cart.c_address.location, add_cart.c_address.location);  

        //Review
        n_cart -> fd_cart.review = new char[strlen(add_cart.review)+1];
        strcpy(n_cart -> fd_cart.review, add_cart.review);  

        //Food type
        n_cart -> fd_cart.type = new char[strlen(add_cart.type)+1];
        strcpy(n_cart -> fd_cart.type, add_cart.type);  

        //Top Three Favorite Food 
        n_cart -> fd_cart.fav_food.f_1 = new char[strlen(add_cart.fav_food.f_1)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_1, add_cart.fav_food.f_1);  

        n_cart -> fd_cart.fav_food.f_2 = new char[strlen(add_cart.fav_food.f_2)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_2, add_cart.fav_food.f_2);  

        n_cart -> fd_cart.fav_food.f_3 = new char[strlen(add_cart.fav_food.f_3)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_3, add_cart.fav_food.f_3);  
    }

    //Insert at the end
    else
    {

        node * n_cart = new node; 
        tail -> next = n_cart;
        tail = n_cart;
        n_cart -> next = NULL;

        
         //Name
        n_cart -> fd_cart.name = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  
        
        //Line 1
        n_cart -> fd_cart.c_address.line_1 = new char[strlen(add_cart.c_address.line_1)+1];
        strcpy(n_cart -> fd_cart.c_address.line_1, add_cart.c_address.line_1);  

        //Location
        n_cart -> fd_cart.c_address.location = new char[strlen(add_cart.c_address.location)+1];
        strcpy(n_cart -> fd_cart.c_address.location, add_cart.c_address.location);  

        //Food type
        n_cart -> fd_cart.type = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  

        //Review
        n_cart -> fd_cart.review = new char[strlen(add_cart.review)+1];
        strcpy(n_cart -> fd_cart.review, add_cart.review);  

        //Favorite Foods
        n_cart -> fd_cart.fav_food.f_1 = new char[strlen(add_cart.fav_food.f_1)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_1, add_cart.fav_food.f_1);  

        n_cart -> fd_cart.fav_food.f_2 = new char[strlen(add_cart.fav_food.f_2)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_2, add_cart.fav_food.f_2);  

        n_cart -> fd_cart.fav_food.f_3 = new char[strlen(add_cart.fav_food.f_3)+1];
        strcpy(n_cart -> fd_cart.fav_food.f_3, add_cart.fav_food.f_3);  
               
    }

    return 0;
}


//Add to beginning
int FoodCartList::add_fav_food(const d_food_cart & add_cart)
{
    if(!head)
        return 1;
    else
    {
        char buffer[BUFFER_SIZE];
        int success = 1;
        node * current = head;

        while(current)
        {
            //Check if User's input matches an existing Cart
            if(!strcmp(current->fd_cart.name, add_cart.name))
            {
                cout << "Please enter a favorite food you want to enter: ";
                cin.get(buffer, BUFFER_SIZE, '\n');
                cin.ignore(BUFFER_SIZE, '\n');

                //Check for NULL
                if(!current->fd_cart.fav_food.f_1)
                {
                    current->fd_cart.fav_food.f_1 = new char[strlen(buffer)+1];
                    strcpy(current->fd_cart.fav_food.f_1, buffer);
                    success = 0;
                }
                else if(!current->fd_cart.fav_food.f_2)
                {
                    current->fd_cart.fav_food.f_2 = new char[strlen(buffer)+1];
                    strcpy(current->fd_cart.fav_food.f_2, buffer);
                    success = 0;
                }
                else if(!current->fd_cart.fav_food.f_3)
                {
                    current->fd_cart.fav_food.f_3 = new char[strlen(buffer)+1];
                    strcpy(current->fd_cart.fav_food.f_3, buffer);
                    success = 0;
                }
                else
                {
                    cout << "Looks like you are trying to overwrite an existing Favorite Food entry.\n"
                         << "Please Delete an existing entry first then try adding again!\n";
                }

            }

            current = current-> next;
        }

        return success;
    }      

        return 0;
}

//Display Carts by Food Type
int FoodCartList::display_by_type(const d_food_cart & cart)
{
    if(!head)
        return 1;
    else
    {
        cout << "cart.type: " << cart.type << endl;
        node * current = head;

        while(current)
        {
            if(!strcmp(cart.type, current->fd_cart.type))
            {
                cout << "Name: " << current->fd_cart.name << endl;
                cout << "Address: " << current->fd_cart.c_address.line_1 << endl;
                cout << "Location: " << current->fd_cart.c_address.location << endl;
                cout << "Food Type: " << current->fd_cart.type << endl;
                cout << "Review: " << current->fd_cart.review << endl;
                cout << "Favorite Food(1): " << current->fd_cart.fav_food.f_1 << endl;
                cout << "Favorite Food(2): " << current->fd_cart.fav_food.f_2 << endl;
                cout << "Favorite Food(3): " << current->fd_cart.fav_food.f_3 << endl;
                cout << "\n\n";
            }
            current = head -> next;
        }
    }
    return 0;
}

//Delete Favorite Food from an existing Food Cart
int FoodCartList::delete_fav_food(const d_food_cart & delete_fav)
{
    char buffer[BUFFER_SIZE];
    node * current = head;
    int success = 1;
    while(current)
    {
        if(!strcmp(current->fd_cart.name, delete_fav.name))
        {
            cout << "Favorite Food(1): " << current->fd_cart.fav_food.f_1 << endl;
            cout << "Favorite Food(2): " << current->fd_cart.fav_food.f_2 << endl;
            cout << "Favorite Food(3): " << current->fd_cart.fav_food.f_3 << endl;
            cout << "Enter your choice of deletion which matches the aforementioned Favorites: ";
            cin.get(buffer, BUFFER_SIZE, '\n');
            cin.ignore(BUFFER_SIZE, '\n');

            if(current->fd_cart.fav_food.f_1)
            {
                delete current->fd_cart.fav_food.f_1;
                current->fd_cart.fav_food.f_1 = NULL;
                success = 0;   
            }
            else if(current->fd_cart.fav_food.f_2)
            {
                delete current->fd_cart.fav_food.f_2;
                current->fd_cart.fav_food.f_2 = NULL;
                success = 0;   
            }
            else if(current->fd_cart.fav_food.f_3)
            {
                delete current->fd_cart.fav_food.f_3;
                current->fd_cart.fav_food.f_3 = NULL;
                success = 0;   
            
            }
            else
            {
                cout << "Your choice does not match anything!\n"
                     << "Please re-do your menu choice!";

            }
        }
    }
    return success;
}

//Delete existing Food Cart
int FoodCartList::delete_cart(const d_food_cart & delete_cart)
{
    //Empty List
    if(!head)
        return 0;

    //One item list
    else if(!head->next)
    {

        node * current = head;

        if(!strcmp(current->fd_cart.name, delete_cart.name))
        {
            delete current;
            head = NULL;
        }
    }

    //Many items
    else
    {

        node * current = head;

        //First item is a match
        if(strcmp(current->fd_cart.name, delete_cart.name))
        {
            head = head -> next;
            delete current;
            current = head;
        }

        //No match with first node
        else
        {
            node * previous = current;
            node * temp = current -> next -> next;
            current = current -> next;
            
            while(current)
            {
                if(strcmp(current->fd_cart.name, delete_cart.name))
                {
                    previous -> next = temp;
                    delete current;
                    current = temp;
                    temp = temp -> next;
                }

                else
                {
                    previous = current;
                    current = temp;
                    temp = temp -> next;
                }
            }
        }
    }
    return 0;
}

//FoodCartList destructor helper function
void FoodCartList::destroy(node * & head)
{
    if(!head)
        return;
    else
    {
        node * temp = head -> next;
        delete head;
        head = NULL;
        destroy(temp);
    }
    return;
}

//Display Existing Food Carts
int FoodCartList::display()
{
    if(!head)
    {
        cout << "NO ENTRIES\n";
        return 1;
    }
    else
    {
       node * current = head;   
       while(current)
        {
            //Look up how to redesign this function
            cout << "Name: " << current->fd_cart.name << endl;
            cout << "Address: " << current->fd_cart.c_address.line_1 << endl;
            cout << "Location: " << current->fd_cart.c_address.location << endl;
            cout << "Food Type: " << current->fd_cart.type << endl;
            cout << "Review: " << current->fd_cart.review << endl;
            cout << "Favorite Food(1): " << current->fd_cart.fav_food.f_1 << endl;
            cout << "Favorite Food(2): " << current->fd_cart.fav_food.f_2 << endl;
            cout << "Favorite Food(3): " << current->fd_cart.fav_food.f_3 << endl;
            cout << "\n\n";
            current = current->next;
        }
        
       return 0;
    }
}
