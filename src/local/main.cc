#include "../jsoncpp/jsonrpc.h"
#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace Json::Rpc;
using namespace std;

int main(int argc, char *argv[])
//int main()
{
    assert(argc == 2 && "remove_rule needs an argument node_id");

    string addr = "0.0.0.0";
    int port = 5001;
    Json::Value query, params;
    Json::FastWriter writer;
    std::string queryStr;
    std::string responseStr;
    
    TcpClient tcpClient(addr, port);

    if(!tcpClient.Connect()) {
        std::cerr << "Cannot connect to remote peer!" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    //params["id"] = atoi(argv[1]);
    
    // link
    //params["from_port"] = atoi(argv[2]);
    //params["to_port"] = atoi(argv[3]);

    // Add rule
    /*params["table"] = atoi(argv[1]);
    params["index"] = -1;

    params["in"] = Json::Value();
    params["in"].append(atoi(argv[2]));
    params["out"] = Json::Value();
    params["out"].append(atoi(argv[3]));
    if (argc > 4)
        params["match"] = argv[4];
    else
        params["match"] = "xxxxxxxx";
    */

    params["node"] = Json::Value::UInt64(strtoull(argv[1], NULL, 0));
    query["jsonrpc"] = "2.0";
    query["id"] = "0";
    query["params"] = params;
    query["method"] = "remove_rule";

    
    queryStr = writer.write(query);
    std::cout << "Query is: " << queryStr << std::endl;

    if(tcpClient.Send(queryStr) == -1)
    {
        std::cerr << "Error while sending data!" << std::endl;
        exit(EXIT_FAILURE);
    }

    /* wait the response */
    if(tcpClient.Recv(responseStr) != -1)
    {
        std::cout << "Received: " << responseStr << std::endl;
    }
    else
    {
        std::cerr << "Error while receiving data!" << std::endl;
    }

    tcpClient.Close();
    networking::cleanup();
    return 0;
}
