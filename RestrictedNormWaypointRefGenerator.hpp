#pragma once
#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include "Vector3D.hpp"
#include "PositionMsg.hpp"
#include "RestrictedNormRefSettingsMsg.hpp"
#include "ReferenceMessage.hpp"
#include "WaypointMsg.hpp"
#include "Waypoint.hpp"
#include <vector>

class RestrictedNormWaypointRefGenerator : public msg_emitter, public msg_receiver{

    private:
    vector<Waypoint> Waypoints;
    double max_norm;
    bool enabled=true;
    ControlSystem* x_control_system;
    ControlSystem* y_control_system;
    ControlSystem* z_control_system;
    ControlSystem* yaw_control_system;
    void updateControlSystemsReferences(Vector3D<double> position,double yaw);
public:
    void add_x_control_system(ControlSystem*);
    void add_y_control_system(ControlSystem*);
    void add_z_control_system(ControlSystem*);
    void add_yaw_control_system(ControlSystem*);
    void receive_msg_data(DataMessage* t_msg);
};