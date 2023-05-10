simple Source
{
    parameters:
        @signal[responseTime](type="double");
        @statistic[responseTime](title="Response Time";record=vector?,count?);
        @signal[numMsg](type="long");
        @statistic[numMsg](title="the number of clients";record=vector?,count?);
    gates:
        inout conn;
}
