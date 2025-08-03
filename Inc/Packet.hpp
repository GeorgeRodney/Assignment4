#pragma once

class Packet
{
    private:
        int id_;
        int startTime_;

    public:
        Packet();
        ~Packet();

        void setId(const int id);
        void setQueueStartTime(const int time);

        const int getQueueStartTime(void) const { return startTime_; }
};