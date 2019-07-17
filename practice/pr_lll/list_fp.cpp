#include "main.h"

void build(node * & head, node * & tail){

    srand (time(NULL));
    node * temp;
    node * n_node;
    int arr_size = (rand() % 15 + 1), index = 0;

    n_node = new node;
    n_node -> data = (rand() % 100 + 1);
    head = n_node;
    temp = n_node;

    do{
        ++index;
        n_node = new node;
        n_node -> data = (rand() % 100 + 1);
        temp -> next = n_node;
        temp = temp -> next;;
    }
    while( index < arr_size);

    n_node -> next = NULL;
    tail = n_node;
}

void display(node * head){


    while( head != NULL){
        cout << "(" << head -> data << ")";
        head = head -> next;
    }

    cout << "\n";
}

void destory(node * & head){

    if(!head)
        return;
    else{

        node * temp =  head;
        head = temp -> next;
        delete temp;
        destory(head);
        return;
    }
}

int sum_nodes(node * head){


    int sum = 0;

    /*if( head -> next == NULL){
        cout << "Sum: " << sum << endl;
        return sum;
    }
    else{
        sum += head -> data;
        sum_nodes(head -> next);
    }*/

    while(head -> next != NULL){
        sum += head -> data;
        head = head -> next;
    }
     
    cout << "Sum: " << sum << endl;

    return 0;
}

/*void swap_first_last(node * & head){

    if(!head)
        return;
    else{
        int first = 0, last = 0;
        node * current = head;
        first = head -> data;

        while(current -> next != NULL)
            current = current -> next;

        last = current -> data;
        current -> data = first; //Replace data with first node's data
        head -> data = last;
    }
}*/

void remove_even_num(node * & head){

    if(!head)
        return;
    else{

        node * current = head -> next;
        node * temp = current;

        while(current != NULL){

            if(head -> data % 2 == 0){
                temp = current -> next;
                head = temp -> next;
                delete current;
                current = temp;
            }

            else{

                if(current -> data % 2 == 0){
                    temp = current -> next;
                    delete current;
                    current = temp;
                }

                else
                    current = current -> next;
            }
        }
    }
}


bool is_last_odd(node * head){

    if(!head)
        return false;
    else{

        while( head -> next != NULL)
            head = head -> next;

        if(head -> data % 2 == 1)
            return true;

        return false;
    }
}

/*bool is_palidrome(int & num_arr[], int begin, int end){

        if( num_arr[begin] == num_arr[end] )
            return true;
        else
            return is_palindrom(num_arr, begin + 1, end - 1);

        if( begin > end || end >
}*/

/*void get_int(){

    int user_arr[5];

    cout << "Please enter a 5 number quence: ";

    cin.get(user_arr, 5, '\n');
    cin.ignore();

    is_palindrom(arr, 4, 0);

}*/

void backward_LLL(node * head){

    if(!head)
        return;
    backward_LLL(head -> next);

    cout << head -> data << endl;
    
}

int num_even_rec(node * head){

    if(!head)
        return 0;
    else{

        if( head -> data % 2 == 0 )
            return num_even_rec(head -> next) + 1;
        else
            return num_even_rec(head -> next) + 0;
    }
}

void sum_rec(node * head, int & sum){

    if(!head)
        return;
    sum_rec(head -> next, sum);
    sum += head -> data;
}

void display_last_two(node * head){

    if(!head)
        return;
    else{

        while(head -> next -> next != NULL)
            head = head -> next;

        cout << "2nd last: " << head -> data 
             << "\nLast: " << head -> next -> data << endl;

    }
}

void swap_first_last(node * & head){

    if(!head)
        return;
    else{

        node * first = head, * current = head, * last;

        while(current -> next -> next != NULL)
            current = current -> next;

        last = current -> next;
        head = last;
        head -> next = first -> next;
        current -> next = first;
        first -> next = NULL;

    }
}

void move_first_last(node * & head){

    if(!head)
        return;
    else{

        node * current = head, * temp = head; 

        while(current -> next != NULL)
            current = current -> next;

        head = temp -> next;
        current -> next = temp;
        temp -> next = NULL;
    }
}
