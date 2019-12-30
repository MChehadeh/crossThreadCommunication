#include "ReferenceMessage.hpp"

    msg_type ReferenceMessage::getType(){
        return msg_type::reference;
    }
    const int ReferenceMessage::getSize(){
        return 4;
    }
    float ReferenceMessage::getData(){
        return _data;
    }
    
    ReferenceMessage::ReferenceMessage()
    {

    }

    void ReferenceMessage::setReferenceMessage(float t_data){
        _data=t_data;
    }
    DataMessage* ReferenceMessage::Clone(){ 
        return new ReferenceMessage(*this); 
    }
    ReferenceMessage::~ReferenceMessage()
    {

    }