
struct accessory_node
{
    char * name;
    char * category;
    char * status;
    accessory_node * next;
};

struct room_node
{
    SmartHome new_room;
    room_node * next;
    accessory_node * head;
};

class list()
{
    public:

        list();
        ~list();

        //Add room node to LLL
        //int create_room(   *Work on argument* );

        //Add accesory node to LLL
        //int create_accessory( *Work on argument* );

        //Remove one room node
        //int remove_room(  *Work on argument* );

        //Remove one accessory node
        //int remove_accessory(  *Work on argument* );

        //Remove all accessories
        //int remove_all_accessories(  *Work on argument* );

        //Find room to
        //int find_room(char * room);

        //Display all accessories
        //int display_all_accessories();
        
        //Traverse room LL
        //int traverse_room();

    private:
       
        //Recursively remove all accessories


        //Recursively search for room

        //Recursively display all accessories

        room_node * head;
        room_node * tail;
};
