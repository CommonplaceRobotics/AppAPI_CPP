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
 * @brief Sets the gripper state
 */
class Gripper : public ICommand
{
public:
    robotcontrolapp::CmdGripperParameters data;

    /**
     * @brief Default constructor
     */
    Gripper();

    /**
     * @brief Constructor
     * @param targetState gripper target state
     */
    Gripper(float targetState);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Gets the target state of the gripper
     * @return target state in percent
     */
    float GetTargetState() const;

    /**
     * @brief Sets the target state of the gripper
     * @param state target state in percent
     */
    void SetTargetState(float state);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
