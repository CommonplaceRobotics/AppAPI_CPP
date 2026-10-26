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
 * @brief A joint motion command
 */
class Joint : public ICommand
{
public:
    robotcontrolapp::CmdJointParameters data;

    // Default value for velocity in percent (0..100)
    static constexpr float VELOCITY_DEFAULT = 40;
    // Default value for acceleration in percent (0..100)
    static constexpr float ACCELERATION_DEFAULT = 40;
    // Default value for smoothing in percent (0..100)
    static constexpr float SMOOTHING_DEFAULT = 0;

    /**
     * @brief Default constructor
     */
    Joint();

    /**
     * @brief Constructor
     * @param a1 target position joint 1 in mm or degress
     * @param a2 target position joint 2 in mm or degress
     * @param a3 target position joint 3 in mm or degress
     * @param a4 target position joint 4 in mm or degress
     * @param a5 target position joint 5 in mm or degress
     * @param a6 target position joint 6 in mm or degress
     * @param e1 target position external joint 1 in user-defined units
     * @param e2 target position external joint 2 in user-defined units
     * @param e3 target position external joint 3 in user-defined units
     * @param velocity velocity in percent (0..100)
     * @param acceleration acceleration in percent (0..100)
     * @param smoothing smoothing in percent (0..100)
     */
    Joint(float a1, float a2, float a3, float a4, float a5, float a6, float e1, float e2, float e3, float velocity = VELOCITY_DEFAULT,
          float acceleration = ACCELERATION_DEFAULT, float smoothing = SMOOTHING_DEFAULT);

    /**
     * @brief Constructor
     * @param variableName variable name, the target position is read from this position variable
     * @param velocity velocity in percent (0..100)
     * @param acceleration acceleration in percent (0..100)
     * @param smoothing smoothing in percent (0..100)
     */
    Joint(const std::string& variableName, float velocity = VELOCITY_DEFAULT, float acceleration = ACCELERATION_DEFAULT, float smoothing = SMOOTHING_DEFAULT);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Returns true if the position is read from a variable
     * @return
     */
    bool IsPositionFromVariable() const;
    /**
     * @brief Returns true if the constant position values are used
     * @return
     */
    bool IsPositionConstant() const;

    /**
     * @brief Gets the position variable name
     * @return name of the position variable
     */
    std::string GetVariable() const;
    /**
     * @brief Sets the position variable name
     * @param variable name of the position variable
     */
    void SetVariable(const std::string& variable);

    /**
     * @brief Gets the target position for A1
     * @return position in mm or degrees
     */
    float GetA1() const;
    /**
     * @brief Gets the target position for A2
     * @return position in mm or degrees
     */
    float GetA2() const;
    /**
     * @brief Gets the target position for A3
     * @return position in mm or degrees
     */
    float GetA3() const;
    /**
     * @brief Gets the target position for A4
     * @return position in mm or degrees
     */
    float GetA4() const;
    /**
     * @brief Gets the target position for A5
     * @return position in mm or degrees
     */
    float GetA5() const;
    /**
     * @brief Gets the target position for A6
     * @return position in mm or degrees
     */
    float GetA6() const;
    /**
     * @brief Gets the target position for E1
     * @return position in user-defined units
     */
    float GetE1() const;
    /**
     * @brief Gets the target position for E2
     * @return position in user-defined units
     */
    float GetE2() const;
    /**
     * @brief Gets the target position for E3
     * @return position in user-defined units
     */
    float GetE3() const;

    /**
     * @brief Sets the target position for A1
     * @param pos position in mm or degrees
     */
    void SetA1(float pos);
    /**
     * @brief Sets the target position for A2
     * @param pos position in mm or degrees
     */
    void SetA2(float pos);
    /**
     * @brief Sets the target position for A3
     * @param pos position in mm or degrees
     */
    void SetA3(float pos);
    /**
     * @brief Sets the target position for A4
     * @param pos position in mm or degrees
     */
    void SetA4(float pos);
    /**
     * @brief Sets the target position for A5
     * @param pos position in mm or degrees
     */
    void SetA5(float pos);
    /**
     * @brief Sets the target position for A6
     * @param pos position in mm or degrees
     */
    void SetA6(float pos);
    /**
     * @brief Sets the target position for E1
     * @param pos position in user-defined units
     */
    void SetE1(float pos);
    /**
     * @brief Sets the target position for E2
     * @param pos position in user-defined units
     */
    void SetE2(float pos);
    /**
     * @brief Sets the target position for E3
     * @param pos position in user-defined units
     */
    void SetE3(float pos);

    /**
     * @brief Gets the velocity in percent (0..100)
     * @return
     */
    float GetVelocity() const;
    /**
     * @brief Gets the acceleration in percent (0..100)
     * @return
     */
    float GetAcceleration() const;
    /**
     * @brief Gets the smoothing in percent (0..100)
     * @return
     */
    float GetSmoothing() const;

    /**
     * @brief Sets the velocity in percent (0..100)
     * @param vel
     */
    void SetVelocity(float vel);
    /**
     * @brief Sets the acceleration in percent (0..100)
     * @param acc
     */
    void SetAcceleration(float acc);
    /**
     * @brief Sets the smoothing in percent (0..100)
     * @param smooth
     */
    void SetSmoothing(float smooth);

    /**
     * @brief Gets the abort condition
     * @return
     */
    std::string GetAbortCondition();

    /**
     * @brief Sets the abort condition
     * @param condition abort condition, if true the motion is aborted
     */
    void SetAbortCondition(const std::string& condition);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
