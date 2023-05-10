//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Join.h"
int balancerJoin = 0;
Define_Module(Join);

Join::~Join()
{
    while (!jobsHeld.empty()) {
        delete jobsHeld.front();
        jobsHeld.pop_front();
    }
}

void Join::initialize()
{
    WATCH_PTRLIST(jobsHeld);
}

void Join::handleMessage(cMessage *msg)
{

    int n = gateSize("in");
    if (msg->arrivedOn("in$i")) {
        msg->setName("Job From AppServer");
        send(msg, "out$o");
    }else{
        msg->setName("Response From DBServer");
        send(msg, "in$o", balancerJoin%n);
        balancerJoin++;
        EV_INFO << "sent message from join to tomcat server" << endl;
    }
}
void Join::refreshDisplay() const
{
    getDisplayString().setTagArg("i2", 0, jobsHeld.size()>0 ? "status/hourglass" : "");
}
