#include "SetVelocity.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructor
 * @param e1 velocity for E1 in user-defined units, is ignored if not in velocity mode
 * @param e2 velocity for E2 in user-defined units, is ignored if not in velocity mode
 * @param e3 velocity for E3 in user-defined units, is ignored if not in velocity mode
 */
SetVelocity::SetVelocity(float e1, float e2, float e3)
{
    data.set_velocity_e1(e1);
    data.set_velocity_e2(e2);
    data.set_velocity_e3(e3);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters SetVelocity::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_set_velocity() = data;
    return ret;
}

/**
 * @brief Gets the velocity for E1
 * @return velocity in user-defined units
 */
float SetVelocity::GetE1() const
{
    return data.velocity_e1();
}

/**
 * @brief Gets the velocity for E2
 * @return velocity in user-defined units
 */
float SetVelocity::GetE2() const
{
    return data.velocity_e2();
}

/**
 * @brief Gets the velocity for E3
 * @return velocity in user-defined units
 */
float SetVelocity::GetE3() const
{
    return data.velocity_e3();
}

/**
 * @brief Sets the velocity for E1
 * @param velocity velocity in user-defined units
 */
void SetVelocity::SetE1(float velocity)
{
    data.set_velocity_e1(velocity);
}

/**
 * @brief Sets the velocity for E2
 * @param velocity velocity in user-defined units
 */
void SetVelocity::SetE2(float velocity)
{
    data.set_velocity_e2(velocity);
}

/**
 * @brief Sets the velocity for E3
 * @param velocity velocity in user-defined units
 */
void SetVelocity::SetE3(float velocity)
{
    data.set_velocity_e3(velocity);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
