#pragma once
#include "DataMessage.hpp"
class ReferenceMessage : public DataMessage {

private:
    msg_type _type;
    float _data;

public:
    msg_type getType();
    volatile const int getSize();
    float getData();
    
    ReferenceMessage();

    void setReferenceMessage(float t_data);
    DataMessage* Clone();
    ~ReferenceMessage();
};

