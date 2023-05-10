#include "Server.h"

Define_Module(Server);

void Server::initialize()
{
}

void Server::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
            // This message was scheduled by the initialize() function
            // or a previous handleMessage() call
            EV_INFO << "Schedule" << msg->getName() << endl;
            // Send the message out through the output gate
            if(strcmp(msg->getName(), "Job From Client") == 0){
                msg->setName("Job From WebServer");
                EV_INFO << "in Job Client" << msg->getName() << endl;
                send(msg, "connOut$o");
            }
            else if(strcmp(msg->getName(), "Response From AppServer") == 0){
                msg->setName("Response From WebServer");
                EV_INFO << "in Response AS" << msg->getName() << endl;
                send(msg, "connIn$o");
            }else if(strcmp(msg->getName(), "Job To Process") == 0){
                EV_INFO << "in Tomcat" << msg->getName() << endl;
                send(msg, "connOut$o");
            }else{
                send(msg, "connIn$o");
            }

    }else{
        // This message arrived on the input gate
               numMessagesProcessed++;
               // Process the message
               EV_INFO << "Processing message: " << msg->getName() << endl;
               //performanceRandomizer = ( (double)rand() / (double)RAND_MAX ) - 0.5;
               simtime_t serviceDelay = exponential(serviceTime); // Add some random variation to the service time
               scheduleAt(simTime() + serviceDelay, msg);
    }
}

void Server::finish()
{
    // Output the number of messages processed
    EV_INFO << "Number of messages processed: " << numMessagesProcessed << endl;
}
