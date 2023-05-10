#ifndef __RUBIS_APPSERVER_H_
#define __RUBIS_APPSERVER_H_


#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class AppServer : public cSimpleModule
{
private:
    float serviceTime = 0.2;
    int numMessagesProcessed = 0;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

#endif
