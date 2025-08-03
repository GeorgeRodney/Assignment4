#pragma once
#include <queue>
#include "Packet.hpp"
#include <random>
#include <fstream>

class Server
{
    private:

        double serviceRate_{0.0};
        std::queue<Packet> queue_{};
        int systemArrivals_{0};
        int serviceCompletions_{0};
        double avgSystemTime_{0.0};
        double avgQueueTime_{0.0};
        double avgServiceTime_{0.0};
        std::default_random_engine rng_{};
        std::exponential_distribution<double> expDist_{};
        int startServiceTime_{0};
        int stopServiceTime_{0};
        int interServiceCompleteTime_{0};
        bool inService_{false};
        std::ofstream interServiceHist;

    public:
        Server();
        ~Server();
        Server(const double rate, const std::string& str);

        void receivePacket(Packet pkt, const int tick);
        void iterateServiceTick(const int tick);

        int getSystemArrivals(void) const { return systemArrivals_; }
        int getServiveCompletions(void) const { return serviceCompletions_; }
        double getAvgSystemTime(void) const { return avgSystemTime_; }
        double getAvgQueueTime(void) const { return avgQueueTime_; }
        double getAvgServiceTime(void) const { return avgServiceTime_; }
        bool queueEmpty(void) const;
};