#include <iostream>
#include "Server.hpp"
#include "GenPacket.hpp"
#include <memory>

int main(void)
{
    // Create server model
    std::unique_ptr<Server> pServer = std::make_unique<Server>();

    // Create packet generation model
    std::unique_ptr<GenPacket> genPack = std::make_unique<GenPacket>();

    // Set the server update rate
    pServer->setServerUpdateRate(1024);

    // I want to do a simTick driven method.


}