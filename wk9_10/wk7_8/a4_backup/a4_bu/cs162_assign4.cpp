#include "cs162_list.h"

int main()
{
    activity_type new_act; //<--struct
    outdoor_activity out_act; //object

    greetings();
    //Place Menu foo here
    out_act.read_in(new_act);
    out_act.~outdoor_activity();

    return 0;
}

