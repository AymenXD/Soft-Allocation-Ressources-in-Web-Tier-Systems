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

#include "Fork.h"
#include "Job.h"


Define_Module(Fork);
int balancer = 0;
void Fork::handleMessage(cMessage *msg)
{

    int n = gateSize("out");
    if (msg->arrivedOn("in$i")) {
        msg->setName("Job To Process");
        send(msg, "out$o", balancer%n);
        balancer++;
    }else{
        send(msg, "in$o");
    }



}

Fork::~Fork()
{
    // delete remaining parent jobs
    while (getNumOwnedObjects() > 0)
        delete getOwnedObject(0);
}


