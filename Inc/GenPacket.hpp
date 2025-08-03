#pragma once
#include "Packet.hpp"
#include <random>
#include <fstream>

class GenPacket
{
    private:
        double packetGenRate_{};
        std::default_random_engine rng_{};
        std::exponential_distribution<double> expDist_{};
        int nextPackGenTime_{0};
        std::ofstream interArrivalHist;
        int uniqueIdFactory_;

    public:
        GenPacket();
        ~GenPacket();
        GenPacket(const double rate, const std::string& str);
 
        int sampleExponential(void);
        void generateNextSendTime(void);
        bool attemptEvent(const int tick);
        Packet sendPacket(void);
};