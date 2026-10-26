#include "SetDigitalOutput.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructor
 * @param id Digital output ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..63
 * @param state Target state
 */
SetDigitalOutput::SetDigitalOutput(uint32_t id, bool state)
{
    data.set_output_number(id);
    data.set_target_state(state);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters SetDigitalOutput::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_set_digital_out() = data;
    return ret;
}

/**
 * @brief Gets the digital output ID
 * @return ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..63
 */
uint32_t SetDigitalOutput::GetID() const
{
    return data.output_number();
}

/**
 * @brief Gets the target state
 * @return
 */
bool SetDigitalOutput::GetState() const
{
    return data.target_state();
}

/**
 * @brief Sets the digital output ID
 * @param id Digital output ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..63
 */
void SetDigitalOutput::SetID(uint32_t id)
{
    data.set_output_number(id);
}

/**
 * @brief Sets the target state
 * @param state target state
 */
void SetDigitalOutput::SetState(bool state)
{
    data.set_target_state(state);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
