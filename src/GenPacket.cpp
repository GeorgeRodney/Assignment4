#include "GenPacket.hpp"

GenPacket::GenPacket()
: packetGenRate_(1.0)
, rng_()
, expDist_(packetGenRate_)
{
}

GenPacket::~GenPacket()
{
}

GenPacket::GenPacket(double rate)
: packetGenRate_(rate)
, rng_()
, expDist_(packetGenRate_)
{

}

double GenPacket::sampleExponential(void)
{
    return  expDist_(rng_);
}