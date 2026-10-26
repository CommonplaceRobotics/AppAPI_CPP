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
 * @brief A joint motion to a cartesian position
 */
class JointToCart : public ICommand
{
public:
    robotcontrolapp::CmdJointToCartParameters data;

    // Default value for velocity in percent (0..100)
    static constexpr float VELOCITY_DEFAULT = 40;
    // Default value for acceleration in percent (0..100)
    static constexpr float ACCELERATION_DEFAULT = 40;
    // Default value for smoothing in percent (0..100)
    static constexpr float SMOOTHING_DEFAULT = 0;

    /**
     * @brief Default constructor
     */
    JointToCart();

    /**
     * @brief Constructor
     * @param x X target position in mm
     * @param y Y target position in mm
     * @param z Z target position in mm
     * @param a A target orientation in degrees
     * @param b B target orientation in degrees
     * @param c C target orientation in degrees
     * @param e1 E1 target position in user-defined units
     * @param e2 E2 target position in user-defined units
     * @param e3 E3 target position in user-defined units
     * @param velocity velocity in percent (0..100)
     * @param acceleration acceleration in percent (0..100)
     * @param smoothing smoothing in percent (0..100)
     */
    JointToCart(float x, float y, float z, float a, float b, float c, float e1, float e2, float e3, float velocity = VELOCITY_DEFAULT,
                float acceleration = ACCELERATION_DEFAULT, float smoothing = SMOOTHING_DEFAULT);

    /**
     * @brief Constructor
     * @param variableName variable name, the target position is read from this position variable
     * @param velocity velocity in percent (0..100)
     * @param acceleration acceleration in percent (0..100)
     * @param smoothing smoothing in percent (0..100)
     */
    JointToCart(const std::string& variableName, float velocity = VELOCITY_DEFAULT, float acceleration = ACCELERATION_DEFAULT,
                float smoothing = SMOOTHING_DEFAULT);

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
     * @brief Gets the target X position
     * @return position in mm
     */
    float GetTargetX() const;
    /**
     * @brief Gets the target Y position
     * @return position in mm
     */
    float GetTargetY() const;
    /**
     * @brief Gets the target Z position
     * @return position in mm
     */
    float GetTargetZ() const;
    /**
     * @brief Gets the target A orientation
     * @return position in degrees
     */
    float GetTargetA() const;
    /**
     * @brief Gets the target B orientation
     * @return position in degrees
     */
    float GetTargetB() const;
    /**
     * @brief Gets the target C orientation
     * @return position in degrees
     */
    float GetTargetC() const;
    /**
     * @brief Sets the target X position
     * @param x position in mm
     */
    void SetTargetX(float x);
    /**
     * @brief Sets the target Y position
     * @param y position in mm
     */
    void SetTargetY(float y);
    /**
     * @brief Sets the target Z position
     * @param z position in mm
     */
    void SetTargetZ(float z);
    /**
     * @brief Sets the target A orientation
     * @param a orientation in degrees
     */
    void SetTargetA(float a);
    /**
     * @brief Sets the target B orientation
     * @param b orientation in degrees
     */
    void SetTargetB(float b);
    /**
     * @brief Sets the target C orientation
     * @param c orientation in degrees
     */
    void SetTargetC(float c);

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

    /**
     * @brief Gets the reference frame
     * @return Reference frame name
     */
    std::string GetReferenceFrame() const;

    /**
     * @brief Sets the reference frame
     * @param frame Reference frame name
     */
    void SetReferenceFrame(const std::string& frame);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
