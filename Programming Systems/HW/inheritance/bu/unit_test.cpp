#include "activity.h"
#include "person.h"

int main(void)
{

    act_time dummy;
    hobby * d1;
    work * d2;
    school * d3;

    activity  * a = new activity("Dummy", "Work", dummy);
    work * c = new work("OVH Cloud");

    activity  * b = new activity("Dummy_2", "Work_2", dummy);
    work * d = new work("Burger King");

    int type = c -> check_datatype();

    person * user = new person("Armant");

    user -> create_day_planner(7);

    user -> add_activity(*a, *d1, *c, *d3, type);
    user -> add_activity(*b, *d1, *d, *d3, type);

    user -> display();


    return 0;
}
