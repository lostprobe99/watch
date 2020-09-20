#include "src/watch.h"
#include <iostream>

// day of the week from SUN to SAT
static const char *WEEK[7] = {
    "SUN",
    "MON",
    "TUE",
    "WEN",
    "THU",
    "FRI",
    "SAT"
};

using namespace probe;

int main(int argc, char ** argv)
{
    if(argc == 1)
        ::printf("\n%s:%s: \n", __FILE__, __FUNCTION__);

    watch wa;
    wa.start();
    char buf[128]{0};
    ::printf("watch::now: %s\n\n", wa.now(buf, sizeof(buf)));
    wa.end();

    ::printf("Take %14.6lf ns  for get now time\n", wa.get_ns());
    ::printf("Take %14.6lf mis for get now time\n", wa.get_mis());
    ::printf("Take %14.6lf ms  for get now time\n", wa.get_ms());
    ::printf("Take %14.6lf s   for get now time\n", wa.get_s());
    ::printf("Take %14.6lf min for get now time\n", wa.get_min());
    ::printf("Take %14.6lf h   for get now time\n", wa.get_h());

    ::printf("\nCurrent time is: %s\n", buf);

    return 0;
}
