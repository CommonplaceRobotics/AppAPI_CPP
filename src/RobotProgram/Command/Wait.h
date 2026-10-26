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
 * @brief Waits by a delay or condition
 */
class Wait : public ICommand
{
public:
    robotcontrolapp::CmdWaitParameters data;

    /**
     * @brief Default constructor
     */
    Wait() = default;

    /**
     * @brief Constructs a wait by duration
     * @param seconds time in seconds
     */
    Wait(float seconds);

    /**
     * @brief Constructs a wait by condition
     * @param condition wait condition. Once it evaluates TRUE the command finishes.
     */
    Wait(const std::string& condition);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Is this a wait by duration?
     * @return
     */
    bool IsDuration() const;
    /**
     * @brief Is this a wait by condition?
     * @return
     */
    bool IsCondition() const;

    /**
     * @brief Gets the wait duration
     * @return duration in seconds
     */
    float GetDuration() const;
    /**
     * @brief Gets the wait condition
     * @return
     */
    std::string GetCondition() const;

    /**
     * @brief Sets the wait duration
     * @param seconds duration in seconds
     */
    void SetDuration(float seconds);

    /**
     * @brief Sets the wait condition
     * @param condition wait condition. Once it evaluates TRUE the command finishes.
     */
    void SetCondition(const std::string& condition);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
