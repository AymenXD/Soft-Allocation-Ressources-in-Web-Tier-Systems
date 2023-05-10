#include "AppServer.h"

Define_Module(AppServer);

void AppServer::initialize()
{
    // TODO - Generated method body
}

void AppServer::handleMessage(cMessage *msg)
{
    EV_INFO << "Received message in AppServer" << *msg << " of client." << endl;

        if (msg->arrivedOn("appServerIn$i"))
        {
            EV_INFO << "Sending message from AppServer to MySQL." << endl;
            send(msg, "appServerOut$o");
        } else if(msg->arrivedOn("appServerOut$o")) {
            EV_INFO << "Sending message from AppServer to WebServer." << endl;
            send(msg, "appServerIn$i");
        }
}
/*void AppServer::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
            // This message was scheduled by the initialize() function
            // or a previous handleMessage() call

            // Send the message out through the output gate
            if(strcmp(msg->getName(), "Job From WebServer") == 0){
                msg->setName("Job From AppServer");
                send(msg, "appServerOut$o");
            }
            else if(strcmp(msg->getName(), "Response From DBServer") == 0){
                msg->setName("Response From AppServer");
                send(msg, "appServerIn$o");
            }

    }else{
        // This message arrived on the input gate
               numMessagesProcessed++;
               // Process the message
               EV_INFO << "Processing message: " << msg->getName() << endl;
               simtime_t serviceDelay = serviceTime; // Add some random variation to the service time
               scheduleAt(simTime() + serviceDelay, msg);
    }
}*/
void AppServer::finish()
{
    // Output the number of messages processed
    EV_INFO << "Number of messages processed: " << numMessagesProcessed << endl;
}

