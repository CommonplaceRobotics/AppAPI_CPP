#include "Subprogram.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructor
 * @param programFile sub program file name, relative to the Data/Programs directory
 */
SubProgram::SubProgram(const std::string& programFile)
{
    data.set_program_name(programFile);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters SubProgram::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_subprogram() = data;
    return ret;
}

/**
 * @brief Gets the program file name
 * @return sub program file name, relative to the Data/Programs directory
 */
std::string SubProgram::GetProgram() const
{
    return data.program_name();
}

/**
 * @brief Sets the program file name
 * @param programFile sub program file name, relative to the Data/Programs directory
 */
void SubProgram::SetProgram(const std::string& programFile)
{
    data.set_program_name(programFile);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
