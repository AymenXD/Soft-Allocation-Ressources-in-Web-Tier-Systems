module AppServer
{
    parameters:
        @display("bgb=433,268;i=device/server,gold");
    gates:
        inout appServerIn;
        inout appServerOut;
    submodules:
        TomcatServer1: Server {
            @display("i=device/cpu;p=224,202");
        }
        TomcatServer2: Server {
            @display("i=device/cpu;p=224,76");
        }
        LoadBalancer: Fork {
            @display("p=70,133");
        }
        Join: Join {
            @display("p=359,133");
        }
    connections:
        appServerIn <--> LoadBalancer.in;
        LoadBalancer.out++ <--> TomcatServer1.connIn;
        LoadBalancer.out++ <--> TomcatServer2.connIn;
        TomcatServer1.connOut <--> Join.in++;
        TomcatServer2.connOut <--> Join.in++;
        Join.out <--> appServerOut;
}
