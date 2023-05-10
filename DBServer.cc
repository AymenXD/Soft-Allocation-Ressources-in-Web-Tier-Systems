#include "DBServer.h"

Define_Module(DBServer);

void DBServer::initialize()
{
    ProcessingTime = registerSignal("ProcessingTime");

}

void DBServer::handleMessage(cMessage *msg)
{

    if (msg->isSelfMessage()) {
            // This message was scheduled by the initialize() function
            // or a previous handleMessage() call

            // Send the message out through the output gate
            if(strcmp(msg->getName(), "Job From AppServer") == 0){
                msg->setName("Job From DBServer");
                send(msg, "connIn$o");
                emit(ProcessingTime,simTime().dbl());
                i++;
            }

    }else{
        // This message arrived on the input gate
               numMessagesProcessed++;
               // Process the message
               EV_INFO << "Processing message: " << msg->getName() << endl;
               simtime_t serviceDelay = exponential(serviceTime); // Add some random variation to the service time
               scheduleAt(simTime() + serviceDelay, msg);
    }
}

void DBServer::finish()
{
    // Output the number of messages processed
    EV_INFO << "Number of messages processed: " << numMessagesProcessed << endl;
}
