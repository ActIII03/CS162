//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

public class Order extends Util{
    //Data field
    protected Food head;
    protected Food tail;
    protected int count;
    //Default Constructor
    Order(){
        head = null;
        tail = null;
    }
    public Order(String name){
        head = null;
        tail = null;
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
        + "\n(5) Delete order(s) from a single orderer"
        + "\nChoice (1-5): ");
        choice = input.nextInt();
        input.nextLine();
        return choice;
    }
    //Create_order
    public void create_order(){
        //Get name
        String name = new String();
        System.out.print("\nName of orderer: ");
        name = input.next();
        input.nextLine();
        int choice = prompt_menu();
        Food add_item = make_item(choice);
        add_item.read_in();
        add_item.name_of_person = new String(name);
        // If empty DLL, then create head
        if(this.head == null){
            head = add_item;
            return;
        }
        int compare_result = head.name_of_person.compareToIgnoreCase(name);
        //Else if the node is less than head's, then insert before
        if(compare_result > 0){
            add_item.set_next(head);
            head.set_previous(add_item);
            head = add_item;
            add_item.set_previous(head);
            return;
        }

        //Otherwise, traverse DLL, inserting alphabetically
        Food current = head;
        insert(current, add_item, name);
    }
    //Recursively insert into DLL
    protected void insert(Food current, Food to_insert, String name){

        //Traversed to end of DLL
        if(current.get_next() == null){
            to_insert.set_previous(current);
            current.set_next(to_insert);
            return;
        }

        int compare_result = current.name_of_person.compareToIgnoreCase(name);
        //If current node is greater than new node, then insert before

        //Else If name of current node matches new node's creator, then insert after current node
        if(compare_result == 0){
            to_insert.set_next(current.get_next());
            current.set_next(to_insert);
            to_insert.set_previous(current);
            to_insert.get_next().set_previous(to_insert);
            return;
        }
        //Otherwise traverse
        insert(current.get_next(), to_insert, name);
    }
    //Delete all
    public void destroy_all(){
        if(head == null)
            System.out.print("List doesn't exists!\n");
        destroy_all(head);
    }
    //Recursively delete all
    protected int destroy_all(Food current){
        if(current == null)
            return 1;
        current = current.get_next();
        if(destroy_all(current) == 1) {
            head = current;
        }
        return 0;
    }
    //Delete a single order
    public void delete_order(){
        do {
            //If list exists, then don't display
            if (head == null)
                System.out.print("\nList is empty!");
            else {
                //Get name
                String name = new String();
                System.out.print("\nName of orderer whose orders you want to delete from: ");
                name = input.next();
                input.nextLine();
                int compare_result = head.name_of_person.compareToIgnoreCase(name);
                //If head matches desired name and the user wants to delete it, then reset head
                if (compare_result == 0) {
                    head.display();
                    if (ask_delete()) {
                        head.set_previous(head.get_next());
                    }
                }
                Food current = head;
                //Otherwise, recursively traverse while asking user to delete their previously entered orders
                delete_order(current, name);
            }
        }while(again());
    }
    //Recursively delete a single order or more
    protected void delete_order(Food current, String to_delete){

        //List is either empty or traversed to end of list
        if(current == null) {
            System.out.print("\nList is empty or traversed to end of list!");
            return;
        }
        int compare_result = current.name_of_person.compareToIgnoreCase(to_delete);
        //Check result of string compare
        if(compare_result == 0){
            current.display();
            if(ask_delete()){
                //If last item, then add that into account when deleting
                if(current.get_next() == null){
                    current.get_previous().set_next(null);
                    System.out.print("Successful delete from end\n");
                }

                //Otherwise, normal deletion
                else {
                    Food temp = current.get_next();
                    temp.set_previous(current.get_previous());
                    current.get_previous().set_next(temp);
                }
                return;
            }
        }
        delete_order(current.get_next(), to_delete);
    }

    //Display all
    public void display_all(){
        if(head == null)
            System.out.print("\n****************************************************"
                    + "List of orders is empty");
        Food current = head;
        System.out.print("\n****************************************************"
        + "\nOrdered items\n");
        display_all(current);
    }
    //Recursively traverse to display all items in DLL
    protected void display_all(Food current){
        if(current == null)
            return;
        System.out.print("\nOrderer: " + current.name_of_person);
        current.display();
        current = current.get_next();
        display_all(current);
    }
    //Display order(s) based on name supplied
    public void display_orderer(){
        if(head == null)
            System.out.print("\nList is empty!");

        String name = new String();
        System.out.print("\nName of orderer you want to search for: ");
        name = input.next();
        input.nextLine();
        display_orderer(head, name);
    }
    //Recursively display order(s) based on name supplied
    protected void display_orderer(Food current, String name){

        if(current == null) {
            System.out.print("No name matches\n");
            return;
        }

        if(current.name_of_person.equals(name))
            current.display();
        display_orderer(current.get_next(), name);
    }
    protected void test() {
        do {

            create_order();
            create_order();
            create_order();
            create_order();
            display_all();
            delete_order();
            display_all();


        }while(again());
    }

}
