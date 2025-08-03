#include "GenPacket.hpp"
#include <fstream>

GenPacket::GenPacket()
: packetGenRate_(1.0)
, expDist_(packetGenRate_)
, uniqueIdFactory_(0)
{
}

GenPacket::~GenPacket()
{
    if(interArrivalHist.is_open()) interArrivalHist.close();
}

GenPacket::GenPacket(const double rate, const std::string& str)
: packetGenRate_(rate)
, expDist_(packetGenRate_)
{
    interArrivalHist.open(str);
    if (!interArrivalHist.is_open())
    {
        throw std::runtime_error("interServiceHist not open");
    }
}

int GenPacket::sampleExponential(void)
{
    int inter = static_cast<int>(std::ceil(expDist_(rng_)));
    interArrivalHist << inter << "\n";
    return inter;
}

void GenPacket::generateNextSendTime(void)
{
    nextPackGenTime_ = nextPackGenTime_ + sampleExponential();
}

bool GenPacket::attemptEvent(const int tick)
{
    if (tick >= nextPackGenTime_)
    {
        nextPackGenTime_ = tick;
        generateNextSendTime();
        return true;
    }
    else 
    {
        return false;
    }
}

Packet GenPacket::sendPacket(void)
{
    Packet pk{};
    pk.setId(uniqueIdFactory_++);
    return pk;
}