#include "Joint.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Default constructor
 */
Joint::Joint()
{
    for (size_t i = 0; i < 9; i++) data.add_target_pos(0);
    SetVelocity(VELOCITY_DEFAULT);
    SetAcceleration(ACCELERATION_DEFAULT);
    SetSmoothing(SMOOTHING_DEFAULT);
    SetAbortCondition("false");
}

/**
 * @brief Constructor
 * @param a1 target position joint 1 in mm or degress
 * @param a2 target position joint 2 in mm or degress
 * @param a3 target position joint 3 in mm or degress
 * @param a4 target position joint 4 in mm or degress
 * @param a5 target position joint 5 in mm or degress
 * @param a6 target position joint 6 in mm or degress
 * @param e1 target position external joint 1 in user-defined units
 * @param e2 target position external joint 2 in user-defined units
 * @param e3 target position external joint 3 in user-defined units
 * @param velocity velocity in percent (0..100)
 * @param acceleration acceleration in percent (0..100)
 * @param smoothing smoothing in percent (0..100)
 */
Joint::Joint(float a1, float a2, float a3, float a4, float a5, float a6, float e1, float e2, float e3, float velocity, float acceleration, float smoothing)
{
    data.add_target_pos(a1);
    data.add_target_pos(a2);
    data.add_target_pos(a3);
    data.add_target_pos(a4);
    data.add_target_pos(a5);
    data.add_target_pos(a6);
    data.add_target_pos(e1);
    data.add_target_pos(e2);
    data.add_target_pos(e3);

    SetVelocity(velocity);
    SetAcceleration(acceleration);
    SetSmoothing(smoothing);
    SetAbortCondition("false");
}

/**
 * @brief Constructor
 * @param variableName variable name, the target position is read from this position variable
 * @param velocity velocity in percent (0..100)
 * @param acceleration acceleration in percent (0..100)
 * @param smoothing smoothing in percent (0..100)
 */
Joint::Joint(const std::string& variableName, float velocity, float acceleration, float smoothing)
{
    for (size_t i = 0; i < 9; i++) data.add_target_pos(0);
    data.set_target_pos_variable(variableName);
    SetVelocity(velocity);
    SetAcceleration(acceleration);
    SetSmoothing(smoothing);
    SetAbortCondition("false");
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters Joint::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_joint() = data;
    return ret;
}

/**
 * @brief Returns true if the position is read from a variable
 * @return
 */
bool Joint::IsPositionFromVariable() const
{
    return data.has_target_pos_variable();
}

/**
 * @brief Returns true if the constant position values are used
 * @return
 */
bool Joint::IsPositionConstant() const
{
    return !data.has_target_pos_variable();
}

/**
 * @brief Gets the position variable name
 * @return name of the position variable
 */
std::string Joint::GetVariable() const
{
    if (data.has_target_pos_variable())
        return data.target_pos_variable();
    else
        return "";
}

/**
 * @brief Sets the position variable name
 * @param variable name of the position variable
 */
void Joint::SetVariable(const std::string& variable)
{
    data.set_target_pos_variable(variable);
}

/**
 * @brief Gets the target position for A1
 * @return position in mm or degrees
 */
float Joint::GetA1() const
{
    return data.target_pos(0);
}

/**
 * @brief Gets the target position for A2
 * @return position in mm or degrees
 */
float Joint::GetA2() const
{
    return data.target_pos(1);
}

/**
 * @brief Gets the target position for A3
 * @return position in mm or degrees
 */
float Joint::GetA3() const
{
    return data.target_pos(2);
}

/**
 * @brief Gets the target position for A4
 * @return position in mm or degrees
 */
float Joint::GetA4() const
{
    return data.target_pos(3);
}

/**
 * @brief Gets the target position for A5
 * @return position in mm or degrees
 */
float Joint::GetA5() const
{
    return data.target_pos(4);
}

/**
 * @brief Gets the target position for A6
 * @return position in mm or degrees
 */
float Joint::GetA6() const
{
    return data.target_pos(5);
}

/**
 * @brief Gets the target position for E1
 * @return position in user-defined units
 */
float Joint::GetE1() const
{
    return data.target_pos(6);
}

/**
 * @brief Gets the target position for E2
 * @return position in user-defined units
 */
float Joint::GetE2() const
{
    return data.target_pos(7);
}

/**
 * @brief Gets the target position for E3
 * @return position in user-defined units
 */
float Joint::GetE3() const
{
    return data.target_pos(8);
}

/**
 * @brief Sets the target position for A1
 * @param pos position in mm or degrees
 */
void Joint::SetA1(float pos)
{
    data.set_target_pos(0, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for A2
 * @param pos position in mm or degrees
 */
void Joint::SetA2(float pos)
{
    data.set_target_pos(1, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for A3
 * @param pos position in mm or degrees
 */
void Joint::SetA3(float pos)
{
    data.set_target_pos(2, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for A4
 * @param pos position in mm or degrees
 */
void Joint::SetA4(float pos)
{
    data.set_target_pos(3, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for A5
 * @param pos position in mm or degrees
 */
void Joint::SetA5(float pos)
{
    data.set_target_pos(4, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for A6
 * @param pos position in mm or degrees
 */
void Joint::SetA6(float pos)
{
    data.set_target_pos(5, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for E1
 * @param pos position in user-defined units
 */
void Joint::SetE1(float pos)
{
    data.set_target_pos(6, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for E2
 * @param pos position in user-defined units
 */
void Joint::SetE2(float pos)
{
    data.set_target_pos(7, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for E3
 * @param pos position in user-defined units
 */
void Joint::SetE3(float pos)
{
    data.set_target_pos(8, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Gets the velocity in percent (0..100)
 * @return
 */
float Joint::GetVelocity() const
{
    return data.velocity_percent();
}

/**
 * @brief Gets the acceleration in percent (0..100)
 * @return
 */
float Joint::GetAcceleration() const
{
    return data.acceleration_percent();
}

/**
 * @brief Gets the smoothing in percent (0..100)
 * @return
 */
float Joint::GetSmoothing() const
{
    return data.smoothing_percent();
}

/**
 * @brief Sets the velocity in percent (0..100)
 * @param vel
 */
void Joint::SetVelocity(float vel)
{
    data.set_velocity_percent(vel);
}

/**
 * @brief Sets the acceleration in percent (0..100)
 * @param acc
 */
void Joint::SetAcceleration(float acc)
{
    data.set_acceleration_percent(acc);
}

/**
 * @brief Sets the smoothing in percent (0..100)
 * @param smooth
 */
void Joint::SetSmoothing(float smooth)
{
    data.set_smoothing_percent(smooth);
}

/**
 * @brief Gets the abort condition
 * @return
 */
std::string Joint::GetAbortCondition()
{
    return data.abort_condition();
}

/**
 * @brief Sets the abort condition
 * @param condition abort condition, if true the motion is aborted
 */
void Joint::SetAbortCondition(const std::string& condition)
{
    data.set_abort_condition(condition);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
