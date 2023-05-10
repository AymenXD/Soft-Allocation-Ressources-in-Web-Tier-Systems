

#ifndef __RUBIS_FORK_H_
#define __RUBIS_FORK_H_

#include "QueueingDefs.h"


class  Fork : public cSimpleModule{
  protected:
    virtual void handleMessage(cMessage *msg) override;
    virtual ~Fork();
};



#endif

