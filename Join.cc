

#include "Join.h"
int balancerJoin = 0;
Define_Module(Join);

Join::~Join()
{
    while (!jobsHeld.empty()) {
        delete jobsHeld.front();
        jobsHeld.pop_front();
    }
}

void Join::initialize()
{
    WATCH_PTRLIST(jobsHeld);
}

void Join::handleMessage(cMessage *msg)
{

    int n = gateSize("in");
    if (msg->arrivedOn("in$i")) {
        msg->setName("Job From AppServer");
        send(msg, "out$o");
    }else{
        msg->setName("Response From DBServer");
        send(msg, "in$o", balancerJoin%n);
        balancerJoin++;
        EV_INFO << "sent message from join to tomcat server" << endl;
    }
}
void Join::refreshDisplay() const
{
    getDisplayString().setTagArg("i2", 0, jobsHeld.size()>0 ? "status/hourglass" : "");
}
