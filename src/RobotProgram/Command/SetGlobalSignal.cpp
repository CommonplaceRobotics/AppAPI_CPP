#include "SetGlobalSignal.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructor
 * @param id Global signal ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..99
 * @param state Target state
 */
SetGlobalSignal::SetGlobalSignal(uint32_t id, bool state)
{
    data.set_output_number(id);
    data.set_target_state(state);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters SetGlobalSignal::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_set_global_signal() = data;
    return ret;
}

/**
 * @brief Gets the global signal ID
 * @return ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..99
 */
uint32_t SetGlobalSignal::GetID() const
{
    return data.output_number();
}

/**
 * @brief Gets the target state
 * @return
 */
bool SetGlobalSignal::GetState() const
{
    return data.target_state();
}

/**
 * @brief Sets the global signal ID
 * @param id Global signal ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..99
 */
void SetGlobalSignal::SetID(uint32_t id)
{
    data.set_output_number(id);
}

/**
 * @brief Sets the target state
 * @param state target state
 */
void SetGlobalSignal::SetState(bool state)
{
    data.set_target_state(state);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
