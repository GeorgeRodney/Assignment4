#include "GenPacket.hpp"

GenPacket::GenPacket()
: packetGenRate_(1.0)
, rng_()
, expDist_(packetGenRate_)
, nextPackGenTime_(0)
{
}

GenPacket::~GenPacket()
{
}

GenPacket::GenPacket(double rate)
: packetGenRate_(rate)
, rng_()
, expDist_(packetGenRate_)
, nextPackGenTime_(0)
{

}

int GenPacket::sampleExponential(void)
{
    return static_cast<int>(std::ceil(expDist_(rng_)));
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
        return true;
    }
    else 
    {
        return false;
    }
}

Packet GenPacket::sendPacket(void) const
{
    Packet pk{};
    return pk;
}