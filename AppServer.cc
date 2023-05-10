#include "AppServer.h"

Define_Module(AppServer);

void AppServer::initialize()
{
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


void AppServer::finish()
{
    // Output the number of messages processed
    EV_INFO << "Number of messages processed: " << numMessagesProcessed << endl;
}

