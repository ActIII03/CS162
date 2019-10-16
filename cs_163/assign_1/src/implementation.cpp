//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include "assign1.h"

void menu(int & decision)
{
    cout << "Which of the option would like to choose?:\n"
         << "(1) Add Food Cart w/ Favorite Food \n(2) Display Food Cart(s) by Food Type \n(3) Delete Favorite Food from Exisiting Cart \n"
         << "(4) Add Top Three Favorite Food to an Existing Cart \n(5) Display Food Cart(s) \n(6) Quit Program \nChoice(1-6):";
    cin >> decision;
    cin.ignore();
    cin.clear();
}

void greeting()
{
    cout << "Welcome to Food Cart Registery!" << endl;
}

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


    else if(menu_choice == 2)
    {
        //Food Type
        cout << "Please enter a food type you want to see (Example -- Thai): " ;
        cin.get(new_cart.type, BUFFER_SIZE, '\n'); 
        cin.ignore(100, '\n');
        cin.clear();
        cout << "\n";

    }
    

    else if(menu_choice == 3)
    {

        //Delete Favorite Food
        cout << "Please enter the Food Cart you want to delete your favorite food from (Example: Stack High Sandwiches): ";
        cin.get(new_cart.type, BUFFER_SIZE, '\n');
        cin.ignore(100, '\n');
        cin.clear();
        
        cout << "Please enter your favorite food item you want to delete (Example: California Steak Burrito): ";
        cin.get(new_cart.fav_food.f_1, BUFFER_SIZE, '\n');
        cin.ignore(100, '\n');
        cin.clear();
    }


    else if(menu_choice == 4)
    {

        cout << "Please enter the Food Cart you want to add your favorite food too (Example: Stack High Sandwiches): ";
        cin.get(new_cart.name, BUFFER_SIZE, '\n');
        cin.ignore();
        cin.clear();
        
        
        //Favorite Food
        cout << "Please enter your top favorite food item you want to add to an existing food cart (Example: California Steak Burrito)(1): ";
        cin.get(new_cart.fav_food.f_1, BUFFER_SIZE, '\n');
        cin.ignore();
        cin.clear();
    }
    return 0;

}

//List constructor
FoodCartList::FoodCartList()
{
    head = NULL;
    tail = NULL;

}

//Destructor
FoodCartList::~FoodCartList()
{
    if(head)
    {
        destroy(head);
    }

}

//Add to LLL
int FoodCartList::add_cart(const d_food_cart & add_cart)
{

    //Emptt List
    if(!head)
    {

        node * n_cart = new node;
        head = n_cart;
        head -> next = NULL;

        int test = (strlen(add_cart.name) + 1);
        cout << "Length: " << test << endl;
        
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
    /*if(!head)
        return 1;
    else
    {
        char buffer[BUFFER_SIZE];
        cout << "Please enter any type of food-type you wish to display: ";
        cin.get(buffer, BUFFER_SIZE, '\n');
        cin.ignore(BUFFER_SIZE, '\n');

        while(head)
        {
            if(strcmp(buffer, cart.name))
            {
                
            }
        }
    }      */ 

        return 0;
}

int FoodCartList::count(node * head) 
{
    int count = 0;

    if(!head)
    {
        cout << "Number of Entries: " << count;
        return count;
    }
    else
    {
        while(!head)
        {
            ++count;
            head = head->next;
        }
        cout << "Number of Entries: " << count;
        return count;
    }
}


int FoodCartList::display_by_type(const d_food_cart & cart)
{
    if(!head)
        return 1;
    else
    {
        char buffer[BUFFER_SIZE];
        cout << "Please enter any type of food-type you wish to display carts who cook that way: ";
        cin.get(buffer, BUFFER_SIZE, '\n');
        cin.ignore(BUFFER_SIZE, '\n');

        while(head)
        {
            if(strcmp(buffer, head->fd_cart.type))
            {
                cout << "Name: " << head->fd_cart.name << endl;
                cout << "Address: " << head->fd_cart.c_address.line_1 << endl;
                cout << "Location: " << head->fd_cart.c_address.location << endl;
                cout << "Food Type: " << head->fd_cart.type << endl;
                cout << "Review: " << head->fd_cart.review << endl;
                cout << "Favorite Food(1): " << head->fd_cart.fav_food.f_1 << endl;
                cout << "Favorite Food(2): " << head->fd_cart.fav_food.f_2 << endl;
                cout << "Favorite Food(3): " << head->fd_cart.fav_food.f_3 << endl;
            }
            head = head -> next;
        }
    }
    return 0;
}

int FoodCartList::delete_fav_food(const d_food_cart & delete_fav)
{
    //Stub
    return 0;
}

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

int FoodCartList::display()
{
    if(!head)
    {
        cout << "NO ENTRIES\n";
        return 1;
    }
    else
    {
       while(head)
        {
            //Look up how to redesign this function
            cout << "Name: " << head->fd_cart.name << endl;
            cout << "Address: " << head->fd_cart.c_address.line_1 << endl;
            cout << "Location: " << head->fd_cart.c_address.location << endl;
            cout << "Food Type: " << head->fd_cart.type << endl;
            cout << "Review: " << head->fd_cart.review << endl;
            cout << "Favorite Food(1): " << head->fd_cart.fav_food.f_1 << endl;
            cout << "Favorite Food(2): " << head->fd_cart.fav_food.f_2 << endl;
            cout << "Favorite Food(3): " << head->fd_cart.fav_food.f_3 << endl;
            head = head->next;
        }
        
       return 0;
    }
}
