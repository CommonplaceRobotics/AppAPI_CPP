#include "Gripper.h"

#include <stdexcept>

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Default constructor
 */
Gripper::Gripper()
{
    data.add_target_states(0);
}

/**
 * @brief Constructor
 * @param targetState gripper target state
 */
Gripper::Gripper(float targetState)
{
    data.add_target_states(targetState);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters Gripper::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_gripper() = data;
    return ret;
}

/**
 * @brief Gets the target state of the gripper
 * @return target state in percent
 */
float Gripper::GetTargetState() const
{
    if (data.target_states_size() < 1) throw std::invalid_argument("invalid number of gripper states");
    return data.target_states(0);
}

/**
 * @brief Sets the target state of the gripper
 * @param state target state in percent
 */
void Gripper::SetTargetState(float state)
{
    data.set_target_states(0, state);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
