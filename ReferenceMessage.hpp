#pragma once
#include "DataMessage.hpp"
class ReferenceMessage : public DataMessage {

private:
    float _data;

public:
    msg_type getType();
    const int getSize();
    float getData();
    
    ReferenceMessage();

    void setReferenceMessage(float t_data);
    DataMessage* Clone();
    ~ReferenceMessage();
};

