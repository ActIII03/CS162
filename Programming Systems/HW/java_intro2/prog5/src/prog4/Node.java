
//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

import java.io.IOException;

public class Node extends Util{
    //Data Fields
    protected Food head;
    protected Food tail;
    protected Node right_root;
    protected Node left_root;
    protected String name_of_person;
    protected int count;
    protected int height = 1;
    //Default Constructor
    Node(){
        head = null;
        tail = null;
        left_root = null;
        right_root = null;
    }
    public Node(String name){
        head = null;
        tail = null;
        right_root = null;
        left_root = null;
        name_of_person = new String(name);
    }
    //Pick food type and return it
    public Food make_item(int choice){
        Food item;
        if(choice == 1)
            item = new Burger();
        else if(choice == 2)
            item = new Pizza();
        else
            item = new Drink();
        return item;
    }
    //Prompt client
    public int order_menu(){
        int choice = 0;
        System.out.print("\nMenu of Order System:"
                + "\n(1) Create Order"
                + "\n(2) Display all orders"
                + "\n(3) Display orderer's order(s)"
                + "\n(4) Delete all orders"
                + "\nChoice (1-4): ");
        choice = input.nextInt();
        return choice;
    }
    //Get current's right reference
    Node go_right(){
        return this.right_root;
    }
    //Get current's left reference
    Node go_left(){
        return this.left_root;
    }
    //Create Food list
    public void create_item(){
        int choice = prompt_menu();
        Food new_item = make_item(choice);
        new_item.read_in();
        insert(new_item);
    }
    //Insert into Doubly Linked list chronologically
    protected void insert(Food to_insert){
        //If list is empty, then create head and insert into list
        if(head == null){
            head = to_insert;
            //Set tail to head since after one insertion. first node will be at the end
            tail = head;
        }
        //Otherwise, insert at the head of the Doubly Linked list
        else{
                to_insert.set_next(head);
                head = to_insert;
        }
        //Keep track of list size
        ++count;
        try {
            //Write to user-supplied
            write_to_file(to_insert, name_of_person);
        }
        catch (IOException error)
        {
             System.err.println(error);
             System.out.print("File not present...\n");
        }

    }
    //Display Doubly Linked list
    public void display(){
        if(head == null)
            System.out.println("List of order is empty!");
        System.out.print("Name of orderer: " + name_of_person);
        display(this.head);
    }
    //Recursively display Doubly Linked list
    public void display(Food current){
        if(current == null)
            return;
        current.display();
        display(current.get_next());
    }
    public void display_current(Food current) {
        if (current == null)
            return;
        //Display parent data
        current.display();
    }
    //Delete
    public void delete(){
        //If DLL is empty, then return
        if(this.head == null)
            return;
        clear_screen();
        delete(this.head);
    }
    //Recursively Delete and ask here <--- Work on
    protected void delete(Food current){

        display_current(current);
        if(current == null) {
            System.out.print("Returning now");
            return;
        }
        //If they pick "Yes" for an answer, then delete
        if(ask_delete()) {
            //Check current pointer is pointing to head
            if (current == this.head) {
                if (head.get_next() != null) {
                    head = head.get_next();
                } else {
                    head = null;
                }
            } else {
                return;
            }
            --count;
            delete(current.get_next());
        }
        if(again())
            delete(current.get_next());
        return;
    }
    //Set current's right reference to
    protected void set_right(Node current){
        this.right_root = current;
    }
    //Set current's left reference to
    protected void set_left(Node current){
        this.left_root = current;
    }
    protected void test() {
        do {
            int num;
            display();

            do {
                System.out.print("\nNumber: ");
                num = input.nextInt();
                Food new_item = new Burger(num);
                insert(new_item);
            } while (again());

            display();
            System.out.print("Before deletion:\n");
            delete();
            System.out.print("After deletion:\n");
            display();

        }while(again());
    }

}
