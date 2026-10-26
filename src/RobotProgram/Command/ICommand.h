#pragma once

#include <robotcontrolapp.grpc.pb.h>

namespace App
{
namespace RobotProgram
{
namespace Command
{

class ICommand
{
public:
    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const = 0;
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
