package prog4;

public class Main extends Util {
    public static void main(String[] args){
        Order order_system = new Order();


        order_system.greet();
        do {

            switch(order_system.order_menu()) {
                case 1: //Create order
                    order_system.create_order();
                    break;
                case 2: //Display all
                    order_system.display_all();
                    break;
                case 3: //Display a single orderer's orders
                    order_system.display_order();
                    break;
                case 4: //Delete all
                    order_system.delete_all();
                    break;
            }
        }while(order_system.again()); //Prompt user

    }

}
