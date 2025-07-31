#include <iostream>
#include "Server.hpp"
#include "GenPacket.hpp"
#include <memory>
#include <fstream>

int main(void)
{
    // To Python
    std::ofstream file("../output/interarrival.csv");

    // Sim Tick units of seconds.
    unsigned long simTick = 0;

    // Create server model
    double seriveRate = 50.0 / 3600.0;
    std::unique_ptr<Server> pServer = std::make_unique<Server>(seriveRate);

    // Create packet generation model
    double arrivaleRate = 40.0 / 3600.0;
    std::unique_ptr<GenPacket> pGenPack = std::make_unique<GenPacket>(arrivaleRate);

    // I want to do a simTick driven method.
    // 10 hours
    while(simTick++ < 60*10*60)
    {
        double interarrival = pGenPack->sampleExponential();
        std::cout << "interGenPacket: " << interarrival << std::endl;
        file << interarrival << "\n";
    }
    file.close();
    



    return 0;

}