#pragma once
#include "Packet.hpp"
#include <random>

class GenPacket
{
    private:
        double packetGenRate_;
        std::default_random_engine rng_;
        std::exponential_distribution<double> expDist_;
        int nextPackGenTime_;

    public:
        GenPacket();
        ~GenPacket();
        GenPacket(double rate);
 
        int sampleExponential(void);
        void generateNextSendTime(void);
        bool attemptEvent(const int tick);
        Packet sendPacket(void) const;
};