#include "users.h"

int main(void)
{
    forum  * f1 = new forum;
    forum  * f2 = new forum;
    UserTable ut1;

    cin >> f1;
    ut1.add_post(*f1);
    delete f1;
    cin >> f2;
    ut1.add_post(*f2);

    return 0;
}

