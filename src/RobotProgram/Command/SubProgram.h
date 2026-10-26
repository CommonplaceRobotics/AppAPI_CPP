#pragma once

#include <robotcontrolapp.grpc.pb.h>

#include <string>

#include "ICommand.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Calls a sub program from a program file
 */
class SubProgram : public ICommand
{
public:
    robotcontrolapp::CmdSubprogramParameters data;

    /**
     * @brief Default constructor, no program name given
     */
    SubProgram() = default;

    /**
     * @brief Constructor
     * @param programFile sub program file name, relative to the Data/Programs directory
     */
    SubProgram(const std::string& programFile);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Gets the program file name
     * @return sub program file name, relative to the Data/Programs directory
     */
    std::string GetProgram() const;

    /**
     * @brief Sets the program file name
     * @param programFile sub program file name, relative to the Data/Programs directory
     */
    void SetProgram(const std::string& programFile);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
