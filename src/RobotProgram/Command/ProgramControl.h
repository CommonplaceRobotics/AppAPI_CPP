#pragma once

#include <robotcontrolapp.grpc.pb.h>

#include "ICommand.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Controls the motion program (stop/pause)
 */
class ProgramControl : public ICommand
{
public:
    robotcontrolapp::CmdProgramControlParameters data;

    /**
     * @brief Default constructor
     */
    ProgramControl() = default;

    /**
     * @brief Constructor
     * @param type command type
     */
    ProgramControl(robotcontrolapp::CmdProgramControlParameters_Type type);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;
};

/**
 * @brief Stops the motion program
 */
class Stop : public ProgramControl
{
public:
    Stop() : ProgramControl(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Stop) {}
};

/**
 * @brief Pauses the motion program
 */
class Pause : public ProgramControl
{
public:
    Pause() : ProgramControl(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Pause) {}
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
