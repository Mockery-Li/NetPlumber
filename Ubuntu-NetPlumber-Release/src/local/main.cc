#include "../jsoncpp/jsonrpc.h"
#include <iostream>

using namespace Json::Rpc;
using namespace std;

int main()
{
    string addr = "0.0.0.0";
    int port = 5001;

    TcpClient client(addr, port);
    client.send("AAA");
}
