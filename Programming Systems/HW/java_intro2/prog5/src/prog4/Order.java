
//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

public class Order extends Node{
    //Data field
    Node root;
    protected String name_of_person;
    //Default constructor
    Order(){
        root = null;
    }
    //Pick food type and return it
    public Food make_item(int choice){
        Food item;
        if(choice == 1){
            item = new Burger();
            //item.read_in();
        }
        else if(choice == 2){
            item = new Pizza();
            //item.read_in();
        }
        else{
            item = new Drink();
            //item.read_in();
        }
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
    //Is max function
    public int is_max(int l_tree, int r_tree){
        //if left sub-tree height is greater than right sub-tree height, then return left sub-tree height. Otherwise, return right sub-tree's height
        return (l_tree > r_tree) ? l_tree : r_tree;
    }
    //Get height
    protected int height(Node current){
        if(current == null)
            return 0;
        return current.height;
    }
    //Get balance factor
    protected int get_balance(Node current){
        //if current node is node, then return 0 for balance factor

        //Otherwise, return the difference of height from current node in right and left sub-tree
        return height(current.go_left()) - height(current.go_right());
    }
    //Right rotate
    protected Node right_rotate(Node current){
        Node current_left = current.go_left();
        Node temp = current_left.go_left();

        //Rotate
        current_left.set_right(current);
        current.set_left(temp);

        //Update height
        current.height = is_max(height(current.go_left()), height(current.go_right()));
        current_left.height = is_max(height(current_left.go_left()), height(current_left.go_right()));

        return current_left;
    }
    //Left Rotate
    protected Node left_rotate(Node current){
        Node current_right = current.go_right();
        Node temp = current_right.go_left();

        //Rotate
        current_right.set_right(current);
        temp.set_left(temp);

        //Update height
        current.height = is_max(height(current.go_left()), height(current.go_right()));
        current_right.height = is_max(height(current_right.go_left()), height(current_right.go_right()));

        return current_right;
    }
    //Create_order
    public void create_order(){
        //Get name
        String name = new String();
        System.out.print("\nName of orderer: ");
        name = input.next();
        //Recursively insert into AVL
        this.root = create_order(this.root, name);
    }
    //Recursively insert into AVL
    protected Node create_order(Node add_order, String find_person){
        //If AVl doesn't exists, then create order for root
        if(add_order == null){
            add_order = new Node(find_person);
            add_order.create_item();
            return add_order;
        }
        int compare_result = add_order.name_of_person.compareToIgnoreCase(find_person);
        //Go left for insertion
        if(compare_result < 0)
            add_order.set_left(create_order(add_order.go_left(), find_person));
        //Go right for insertion
        else if(compare_result > 0)
            add_order.set_left(create_order(add_order.go_left(), find_person));
        //Current node matches name of person creating new order
        else
            add_order.create_item();
        //Update height of this ancestor node
        add_order.height = 1 + is_max(height(add_order.go_left()), height(add_order.go_right()));

        //Get balance factor (Absolute difference of the node of this ancestor node to check whether this node became unbalanced
        int balance = get_balance(add_order);

        //If this node become unbalanced, then there are 4 cases:
        // Case 1: left left case
        if(balance > 1 && add_order.name_of_person.compareToIgnoreCase(add_order.go_left().name_of_person) < 0)
            return right_rotate(add_order);
        //If this node becomes unbalanced (balance > 1) and if compare_result with current node's left name is less than. Right rotate current node
        // Case 2: right right case
        //If this node becomes unbalanced (balance < -1) and if compare_result with current node's right name is greater than. Left rotate current node
        if(balance < -1 && add_order.name_of_person.compareToIgnoreCase(add_order.go_right().name_of_person) > 0)
            return left_rotate(add_order);
        // Case 3: left right case
        //If this node becomes unbalanced (balance > 1) and if compare_result with current node's left name is greater than. Left rotate current node's left child and right rotate current node
        if(balance > 1 && add_order.name_of_person.compareToIgnoreCase(add_order.go_left().name_of_person) > 0){
            add_order.set_left(left_rotate(add_order.go_left()));
            return right_rotate(add_order);
        }
        // Case 4: right left case
        //If this node becomes unbalanced (balance < -1) and if compare_result with current node's right name is greater than. Right rotate current node's left child and left rotate current node
        if(balance < -1 && add_order.name_of_person.compareToIgnoreCase(add_order.go_right().name_of_person) < 0){
            add_order.set_right(right_rotate(add_order.go_right()));
            return left_rotate(add_order);
        }

        return add_order;
    }
    //Display all orders
    public void display_all(){
        //Check for root
        if(this.root == null) {
            System.out.print("No Orders...\n");
            return;
        }
        display_all(this.root);
        return;
    }
    //Recursively Display all orders in pre-order
    protected void display_all(Node to_display){

        //Base case
        if(to_display == null){
            return;
        }
        //Traverse left
        display_all(to_display.go_left());
        //Traverse right
        display_all(to_display.go_right());
        //If orders exist, then display
        to_display.display();
        return;
    }
    //Display orders based on user-supplied search (Name of orderer)
    protected void display_order() {

        if(this.root == null) {
            System.out.print("No orders\n");
            return;
        }
        //Get name
        String name = new String();
        System.out.print("\nName of orderer: ");
        name = input.next();
        display_order(this.root, name);

    }
    //recursively Display orders based on user-supplied search (Name of orderer)
    protected void display_order(Node current, String name_to_find){
        if(current == null){
            System.out.print("Name wasn't found");
            return;
        }
        int compare_result = current.name_of_person.compareToIgnoreCase(name_to_find);
        if(compare_result == 0){
            current.display();
            return;
        }
        else if(compare_result > 0)
            display_order(current.go_left(), name_to_find);
        else
            display_order(current.go_right(), name_to_find);
        return;
    }
    //Delete all orders
    protected void delete_all(){
        if(this.root == null)
            System.out.print("No orders to delete\n");
        this.root = delete_all(this.root);
    }
    //Recursively delete all orders doing post-order traversal
    protected Node delete_all(Node current){
        if(current == null)
            return null;
        current.set_left(delete_all(current.go_left()));
        current.set_right(delete_all(current.go_left()));
        return current;
    }
    //Test
    protected void test(){

        do{
            //Create list of items
            do {
                create_order();
            }while (again());
            //Display all
            //display_all();
            //Display based on user-supplied
            //Delete

        }while(again());


    }
}
