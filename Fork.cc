
#include "Fork.h"
#include "Job.h"


Define_Module(Fork);
int balancer = 0;
void Fork::handleMessage(cMessage *msg)
{

    int n = gateSize("out");
    if (msg->arrivedOn("in$i")) {
        msg->setName("Job To Process");
        send(msg, "out$o", balancer%n);
        balancer++;
    }else{
        send(msg, "in$o");
    }

}

Fork::~Fork()
{
    // delete remaining parent jobs
    while (getNumOwnedObjects() > 0)
        delete getOwnedObject(0);
}


