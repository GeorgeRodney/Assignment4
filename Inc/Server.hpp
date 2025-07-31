#pragma once
#include <queue>
#include "Packet.hpp"

class Server
{
    private:
        int rate_;
        std::queue<int> queue_;
        int systemArrivals_;
        int serviceCompletions_;
        double avgSystemTime_;
        double avgQueueTime_;
        double avgServiceTime_;

    public:
        Server();
        ~Server();

        double processPacket(const Packet& pkt) const;

        int getSystemArrivals(void) const { return systemArrivals_; }
        int getServiveCompletions(void) const { return serviceCompletions_; }
        double getAvgSystemTime(void) const { return avgSystemTime_; }
        double getAvgQueueTime(void) const { return avgQueueTime_; }
        double getAvgServiceTime(void) const { return avgServiceTime_; }

        void setServerUpdateRate(const int rate) {rate_ = rate;}
};