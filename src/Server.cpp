#include "Server.hpp"

Server::Server()
: rate_(0)
, queue_()
, systemArrivals_(0)
, serviceCompletions_(0)
, avgSystemTime_(0.0)
, avgQueueTime_(0.0)
, avgServiceTime_(0.0)
{
}

Server::~Server()
{
}

double Server::processPacket(const Packet& pkt) const
{
    return 0.0;
}

