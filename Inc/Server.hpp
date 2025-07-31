#pragma once
#include <queue>
#include "Packet.hpp"
#include <random>

class Server
{
    private:
        double serviceRate_;
        std::queue<int> queue_;
        int systemArrivals_;
        int serviceCompletions_;
        double avgSystemTime_;
        double avgQueueTime_;
        double avgServiceTime_;
        std::default_random_engine rng_;
        std::exponential_distribution<double> expDist_;

    public:
        Server();
        ~Server();
        Server(double rate);

        double processPacket(const Packet& pkt) const;

        int getSystemArrivals(void) const { return systemArrivals_; }
        int getServiveCompletions(void) const { return serviceCompletions_; }
        double getAvgSystemTime(void) const { return avgSystemTime_; }
        double getAvgQueueTime(void) const { return avgQueueTime_; }
        double getAvgServiceTime(void) const { return avgServiceTime_; }
};