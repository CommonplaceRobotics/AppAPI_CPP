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
 * @brief Copies a user frame into another
 */
class CopyUserFrame : public ICommand
{
public:
    robotcontrolapp::CmdCopyUserFrameParameters data;

    /**
     * @brief Default constructor
     */
    CopyUserFrame() = default;
    /**
     * @brief Constructor
     * @param from Name of the user frame to copy from
     * @param to Name of the user frame to copy to
     */
    CopyUserFrame(const std::string from, const std::string& to);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Gets the user frame to copy from
     * @return User frame name
     */
    std::string GetFrom() const;
    /**
     * @brief Gets the user frame to copy to
     * @return User frame name
     */
    std::string GetTo() const;

    /**
     * @brief Sets the user frame to copy from
     * @param User frame name
     */
    void SetFrom(const std::string& from);
    /**
     * @brief Sets the user frame to copy to
     * @param User frame name
     */
    void SetTo(const std::string& to);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
