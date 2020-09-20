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

#ifdef PROBE_WATCH_H
using namespace probe;
#endif

int main(int argc, char ** argv)
{
    if(argc == 1)
        ::printf("\n%s:%s\n\n", __FILE__, __FUNCTION__);

#ifdef PROBE_WATCH_H

    watch wa;
    wa.start();
    char buf[128]{0};
    ::std::cout << wa.now(buf, sizeof(buf)) << std::endl;
    wa.end();

    ::printf("Take %13.6lf ns  for get now time\n", wa.get_ns());
    ::printf("Take %13.6lf mis for get now time\n", wa.get_mis());
    ::printf("Take %13.6lf ms  for get now time\n", wa.get_ms());
    ::printf("Take %13.6lf s   for get now time\n", wa.get_s());
    ::printf("Take %13.6lf min for get now time\n", wa.get_min());
    ::printf("Take %13.6lf h   for get now time\n", wa.get_h());

#else
    ::std::cout << "no watch.cpp" << std::endl;
#endif

    return 0;
}
