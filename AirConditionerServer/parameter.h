#ifndef PARAMETER_H
#define PARAMETER_H

enum wind{low,medium,high};

struct parameter
{
    int cool_target_tmpr=25;
    int cool_tmpr_toler=2;
    int cool_target_wind=medium;

    int warm_target_tmpr=28;
    int warm_tmpr_toler=2;
    int warm_target_wind=low;

    int fee=1;
    int wait_timer=100;
};

#endif // PARAMETER_H
