network Topology
{
    submodules:
        Client: Source {
            @display("p=60,137;i=device/pc");
        }
        WebServer: Server {

            @display("p=142,137;i=device/server,blue");
        }
        AppServer: AppServer {

            @display("p=218,137");
        }
        MySQLServer: DBServer {

            @display("p=298,137;i=device/server,red");
        }
    connections allowunconnected:
        Client.conn <--> { delay = 50ms; } <--> WebServer.connIn;
        WebServer.connOut <--> { delay = 100ms; } <--> AppServer.appServerIn;
        AppServer.appServerOut <--> { delay = 200ms; } <--> MySQLServer.connIn;
}
