#include "Packet.hpp"

Packet::Packet()
: id_(0)
, startTime_(0)
{
}

Packet::~Packet()
{
}

void Packet::setId(const int id)
{
    id_ = id;
}

void Packet::setQueueStartTime(const int time)
{
    startTime_ = time;
}