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
 * @brief Sets the velocity of external axes in velocity mode (e.g. conveyor)
 */
class SetVelocity : public ICommand
{
public:
    robotcontrolapp::CmdSetVelocityParameters data;

    /**
     * @brief Default constructor
     */
    SetVelocity() = default;

    /**
     * @brief Constructor
     * @param e1 velocity for E1 in user-defined units, is ignored if not in velocity mode
     * @param e2 velocity for E2 in user-defined units, is ignored if not in velocity mode
     * @param e3 velocity for E3 in user-defined units, is ignored if not in velocity mode
     */
    SetVelocity(float e1, float e2, float e3);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Gets the velocity for E1
     * @return velocity in user-defined units
     */
    float GetE1() const;
    /**
     * @brief Gets the velocity for E2
     * @return velocity in user-defined units
     */
    float GetE2() const;
    /**
     * @brief Gets the velocity for E3
     * @return velocity in user-defined units
     */
    float GetE3() const;

    /**
     * @brief Sets the velocity for E1
     * @param velocity velocity in user-defined units
     */
    void SetE1(float velocity);
    /**
     * @brief Sets the velocity for E2
     * @param velocity velocity in user-defined units
     */
    void SetE2(float velocity);
    /**
     * @brief Sets the velocity for E3
     * @param velocity velocity in user-defined units
     */
    void SetE3(float velocity);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
