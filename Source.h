#ifndef __RUBIS_SOURCE_H_
#define __RUBIS_SOURCE_H_

#include <omnetpp.h>

using namespace omnetpp;


class Source : public cSimpleModule
{
    private:
      int numJobsToSend = 20;
      int numJobsSent = 0;
      int counter = 0;
      float interarrivalTime = 0.1;
      simsignal_t numMsg;
      simsignal_t responseTime;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

#endif
