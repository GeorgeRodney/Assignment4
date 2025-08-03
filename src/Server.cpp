#include "Server.hpp"
#include <fstream>
#include <iostream>

Server::Server()
: serviceRate_(1.0)
, expDist_(serviceRate_)
{
}

Server::~Server()
{
    if(interServiceHist.is_open()) interServiceHist.close();
}

Server::Server(const double rate, const std::string& str)
: serviceRate_(rate)
, expDist_(serviceRate_)
{
    interServiceHist.open(str);
    if(!interServiceHist.is_open())
    {
        throw std::runtime_error("Interservice file not open.");
    }
}

void Server::receivePacket(Packet pkt, const int tick)
{
    pkt.setQueueStartTime(tick);
    queue_.push(pkt);
    systemArrivals_++;
}

void Server::iterateServiceTick(const int tick)
{
    // Start a new packet in service
    if(!inService_)
    { 
        // generate the simulated time the packet will finish its servicing
        int time = static_cast<int>(std::ceil(expDist_(rng_)));
        interServiceCompleteTime_ = tick + time;

        // Log for histogram
        interServiceHist << time << "\n";
        
        // Track the start of service time for metrics
        startServiceTime_ = tick;

        // Calculate the amount of time this packet has been in the queue
        Packet pack = queue_.front();
        int queTime = tick - pack.getQueueStartTime();
        if (serviceCompletions_ != 0)
        {
            avgQueueTime_ = avgQueueTime_ * (((double)serviceCompletions_- 1.0) / (double)serviceCompletions_) + ( (double)queTime/ (double)serviceCompletions_);
        }

        // Starting a service
        inService_ = true;
    }
    // Packet in service. Continue to process
    else if (inService_)
    {
        // Packet service complete
        if (tick >= interServiceCompleteTime_)
        {
            // Eject the packet from the server
            Packet pack = queue_.front();
            queue_.pop();

            // Calculate average time metrics
            int serviceDelta = tick - startServiceTime_;
            startServiceTime_ = 0;

            int systemDelta = tick - pack.getQueueStartTime();
            serviceCompletions_++;

            avgServiceTime_ = avgServiceTime_ * (((double)serviceCompletions_- 1.0) / (double)serviceCompletions_) + ( (double)serviceDelta/ (double)serviceCompletions_);
            avgSystemTime_ = avgSystemTime_ * (((double)serviceCompletions_- 1.0) / (double)serviceCompletions_) + ( (double)systemDelta/ (double)serviceCompletions_);

            // Set the server to be ready to start a new packet servie
            inService_ = false;
        }
    }

}

bool Server::queueEmpty(void) const
{
    return queue_.empty();
}

