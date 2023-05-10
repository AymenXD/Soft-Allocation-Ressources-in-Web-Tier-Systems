#include "Source.h"

Define_Module(Source);

void Source::initialize()
{
    // Get a pointer to the output gate
    cGate *gOut = gateHalf("conn", cGate::OUTPUT);


    // Initialize the number of jobs sent to 0
    numJobsSent = 0;
    numMsg = registerSignal("numMsg");
    responseTime = registerSignal("responseTime");

    // Schedule the first job
    scheduleAt(simTime(), new cMessage("newJob"));
}

void Source::handleMessage(cMessage *msg)
{
    cGate *gOut = gateHalf("conn", cGate::OUTPUT);
    if (msg->isSelfMessage()) {
        // This message was scheduled by the initialize() function
        // or a previous handleMessage() call
        // Create a new job message
        cMessage *job = new cMessage("Job From Client");

        // Send the job message out through the output gate
        send(job, gOut);

        // Increment the number of jobs sent
        numJobsSent++;
        emit(numMsg,numJobsSent);
        if (numJobsSent < numJobsToSend) {
            // Schedule the next job message
            scheduleAt(simTime() + exponential(interarrivalTime), msg);
        }
    }
    else {
        // This message was received from another module

            EV_INFO << "Handling : " << msg->getName() << endl;
            counter++;
            emit(responseTime,(double)counter);
            delete msg;

    }

}

void Source::finish()
{
    // Output the number of jobs sent
    EV_INFO << "Number of jobs sent: " << numJobsSent << endl;
}

