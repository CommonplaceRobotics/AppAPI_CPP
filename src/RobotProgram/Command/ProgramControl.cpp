#include "ProgramControl.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructor
 * @param type command type
 */
ProgramControl::ProgramControl(robotcontrolapp::CmdProgramControlParameters_Type type)
{
    data.set_type(type);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters ProgramControl::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_program_control() = data;
    return ret;
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
