#pragma once
#include "common_types.hpp"
#include "Block.hpp"

class Reference : public Block {

    private:
        block_type _type;

    public:
        block_type getType();
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        void receive_msg_data(DataMessage* t_msg);
        virtual block_id getID() = 0;
        virtual DataMessage* receive_msg_internal(DataMessage*) = 0;
        virtual reference_type getReferenceType() = 0;
        virtual void setReferenceValue(float) = 0;

        Reference();
        ~Reference();
};