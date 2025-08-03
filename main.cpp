#include <iostream>
#include "Server.hpp"
#include "GenPacket.hpp"
#include <memory>
#include <fstream>

int main(void)
{
    // Sim Tick units of seconds.
    unsigned long simTick = 0;

    // Output files
    std::ofstream avgTimes;
    avgTimes.open("../output/avgTimes.csv");

    // Create server model
    double seriveRate = 50.0 / 3600.0;
    std::unique_ptr<Server> pServer = std::make_unique<Server>(seriveRate, "../output/interService.csv");

    // Create packet generation model
    double arrivaleRate = 40.0 / 3600.0;
    std::unique_ptr<GenPacket> pGenPack = std::make_unique<GenPacket>(arrivaleRate, "../output/interArrival.csv");

    pGenPack->generateNextSendTime();

    int hours = 100;

    // Simulate the server simulation for X hours
    while(simTick++ < hours*60*60)
    {
        // Check to see if we should generate and send a packet
        if(pGenPack->attemptEvent(simTick))
        {
            // Hand off a packet from the packet factory to the server
            pServer->receivePacket(pGenPack->sendPacket(), simTick);
        }

        // If the server has something in the queue do some servicing
        if(!pServer->queueEmpty())
        {
            // Process the server packet or start a new packet processing
            pServer->iterateServiceTick(simTick);
        }
    }

    // Send the time metrics to a post processing script
    avgTimes << pServer->getAvgSystemTime() << "\n";
    avgTimes << pServer->getAvgQueueTime() << "\n";
    avgTimes << pServer->getAvgServiceTime() << "\n";
    avgTimes << pServer->getServiveCompletions() << "\n";
    avgTimes << pServer->getSystemArrivals() << "\n";
    avgTimes << hours << "\n";
    avgTimes.close();


    return 0;

}