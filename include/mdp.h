#ifndef MDP
#define MDP

#include "common.h"


struct mdpPort{
    uint32_t gpioBaseAddress;
    uint8_t pinOffset;
};

void mdpCreatePort(uint32_t gpioAdd, uint8_t pinOffs, struct mdpPort *port);

void mdpSetPort(struct mdpPort port, bool value);





#endif