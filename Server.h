#ifndef __RUBIS_SERVER_H_
#define __RUBIS_SERVER_H_

#include <omnetpp.h>

using namespace omnetpp;

class Server : public cSimpleModule
{
private:
    float performanceRandomizer = 0;
    float serviceTime = 0.2;
    int numMessagesProcessed = 0;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

#endif
