#pragma once
#include <vector>

class Packet
{
    private:
        std::vector<double> packetInfo_;
    public:
        Packet();
        ~Packet();

        std::vector<double> getPacketInfo(void) const { return packetInfo_; }
};