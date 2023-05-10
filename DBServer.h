#ifndef _RUBIS_DBSERVER_H
#define _RUBIS_DBSERVER_H

#include <omnetpp.h>

using namespace omnetpp;


class DBServer : public cSimpleModule
{
  private:
    float serviceTime = 0.2;
    int numMessagesProcessed = 0;
    simsignal_t ProcessingTime;
    int i=0;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

#endif
