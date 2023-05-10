
#ifndef __RUBIS_JOIN_H_
#define __RUBIS_JOIN_H_

#include <omnetpp.h>
#include <list>
#include "QueueingDefs.h"
#include "Job.h"

using namespace omnetpp;


class Join : public cSimpleModule
{
  public:
    ~Join();
  protected:
    std::list<Job*> jobsHeld;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void refreshDisplay() const override;
};

#endif
