//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this

package prog4;
//Libraries for utilities
import java.io.*;
import java.lang.Runtime;
import java.util.Scanner;
import java.io.PrintWriter; // Step 1
import java.io.IOException;

public class Util {
    //Input utility
    final String OS;
    protected Scanner input;
    protected String choice;
    protected String file_name;
    //Default constructor
    public Util(){
        OS = System.getProperty("os.name");
        input = new Scanner(System.in);
        file_name = null;
    }
    //Greet User
    public void greet(){
        System.out.print("Welcome to the Food Ordering system!\n");
    }
    //Get file name from user
    public String get_file_name(){
        System.out.print("Please input the filename (Default: output.txt ): ");
        input.nextLine();
        String file_name = new String();
        file_name = input.next();
        return file_name;
    }
    //Prompt user of choices
    public int prompt_menu(){
        System.out.print("List of items to pick from:\n"
                + "(1) Burgers\n"
                + "(2) Pizza\n"
                + "(3) Drink\n"
                + " Choice (1-3) : ");
        int choice = input.nextInt();
        return choice;
    }
    //Ask user to delete current item
    public boolean ask_delete(){
        choice = new String();
        System.out.print("\nWould you like to delete? (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            return true;
        return false;
    }
    //Ask user to keep viewing
    public boolean ask_to_view(){
        choice = new String();
        System.out.print("\nWould you like to keep viewing? (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            return true;
        return false;
    }
    //Ask Again
    protected boolean again(){
        choice = new String();
        System.out.print("\nWould you like to go again?(Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            return true;
        return false;
    }
    //Clear screen of text
    public void clear_screen() {
        //Check Operating Sytem
        if (OS.contains("Windows")) {
            try {
                Runtime.getRuntime().exec("cls");
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            try {
                Runtime.getRuntime().exec("clear");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    //Write to inputted name of text file
    public void write_to_file(Food to_write, String orderer) throws IOException {

        //Create filename
       if(file_name == null) {
            file_name = get_file_name();
            System.out.print("Created:" + file_name + "\n");
            File myObj = new File(file_name);
        }
        // Open the file.
        PrintWriter out = new PrintWriter(file_name);
        //Write to file
        out.print(orderer + ";"
        + to_write.delivery + ";"
        + to_write.quantity + ";");
        //RTTI to print distinct data items
        //Burgers data
        if(to_write instanceof Burger){
            Burger new_burger = (Burger) to_write;
            out.print("Burger;"
            + new_burger.patties + ";"
            + new_burger.cheese + ";"
            + new_burger.lettuce + ";"
            + new_burger.onions + ";"
            + new_burger.pickles + ";");
        }
        //Pizza
        else if(to_write instanceof Burger){
            Pizza new_pizza = (Pizza) to_write;
            out.print("Pizza;"
            + new_pizza.size + ";"
            + new_pizza.ham + ";"
            + new_pizza.pepperoni + ";"
            + new_pizza.olives + ";"
            + new_pizza.sausage + ";"
            + new_pizza.pineapple + "'");
        }

        //Drink
        else{
            Drink new_drink = (Drink) to_write;
        }

        //Close file
        out.close();
        System.out.print("File closed\n");

    }
}
