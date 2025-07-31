#pragma once
#include "Packet.hpp"
#include <random>

class GenPacket
{
    private:
        double packetGenRate_;
        std::default_random_engine rng_;
        std::exponential_distribution<double> expDist_;

    public:
        GenPacket();
        ~GenPacket();
        GenPacket(double rate);
 
        double sampleExponential(void);
};