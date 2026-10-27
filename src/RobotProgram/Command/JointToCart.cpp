#include "JointToCart.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Default constructor
 */
JointToCart::JointToCart()
{
    for (size_t i = 0; i < 3; i++) data.add_target_pos_ext_joints(0);
    SetVelocity(VELOCITY_DEFAULT);
    SetAcceleration(ACCELERATION_DEFAULT);
    SetSmoothing(SMOOTHING_DEFAULT);
    SetAbortCondition("false");
}

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
JointToCart::JointToCart(float x, float y, float z, float a, float b, float c, float e1, float e2, float e3, float velocity, float acceleration,
                         float smoothing)
{
    data.set_target_x(x);
    data.set_target_y(y);
    data.set_target_z(z);
    data.set_target_a(a);
    data.set_target_b(b);
    data.set_target_c(c);
    data.add_target_pos_ext_joints(e1);
    data.add_target_pos_ext_joints(e2);
    data.add_target_pos_ext_joints(e3);

    SetVelocity(velocity);
    SetAcceleration(acceleration);
    SetSmoothing(smoothing);
    SetAbortCondition("false");
}

/**
 * @brief Constructor
 * @param variableName variable name, the target position is read from this position variable
 * @param velocity velocity in percent (0..100)
 * @param acceleration acceleration in percent (0..100)
 * @param smoothing smoothing in percent (0..100)
 */
JointToCart::JointToCart(const std::string& variableName, float velocity, float acceleration, float smoothing)
{
    for (size_t i = 0; i < 3; i++) data.add_target_pos_ext_joints(0);
    data.set_target_pos_variable(variableName);
    SetVelocity(velocity);
    SetAcceleration(acceleration);
    SetSmoothing(smoothing);
    SetAbortCondition("false");
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters JointToCart::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_joint_to_cart() = data;
    return ret;
}

/**
 * @brief Returns true if the position is read from a variable
 * @return
 */
bool JointToCart::IsPositionFromVariable() const
{
    return data.has_target_pos_variable();
}

/**
 * @brief Returns true if the constant position values are used
 * @return
 */
bool JointToCart::IsPositionConstant() const
{
    return !data.has_target_pos_variable();
}

/**
 * @brief Gets the position variable name
 * @return name of the position variable
 */
std::string JointToCart::GetVariable() const
{
    if (data.has_target_pos_variable())
        return data.target_pos_variable();
    else
        return "";
}

/**
 * @brief Sets the position variable name
 * @param variable name of the position variable
 */
void JointToCart::SetVariable(const std::string& variable)
{
    data.set_target_pos_variable(variable);
}

/**
 * @brief Gets the target X position
 * @return position in mm
 */
float JointToCart::GetX() const
{
    return data.target_x();
}

/**
 * @brief Gets the target Y position
 * @return position in mm
 */
float JointToCart::GetY() const
{
    return data.target_y();
}

/**
 * @brief Gets the target Z position
 * @return position in mm
 */
float JointToCart::GetZ() const
{
    return data.target_z();
}

/**
 * @brief Gets the target A orientation
 * @return position in degrees
 */
float JointToCart::GetA() const
{
    return data.target_a();
}

/**
 * @brief Gets the target B orientation
 * @return position in degrees
 */
float JointToCart::GetB() const
{
    return data.target_b();
}

/**
 * @brief Gets the target C orientation
 * @return position in degrees
 */
float JointToCart::GetC() const
{
    return data.target_c();
}

/**
 * @brief Sets the target X position
 * @param x position in mm
 */
void JointToCart::SetX(float x)
{
    data.set_target_x(x);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target Y position
 * @param y position in mm
 */
void JointToCart::SetY(float y)
{
    data.set_target_y(y);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target Z position
 * @param z position in mm
 */
void JointToCart::SetZ(float z)
{
    data.set_target_z(z);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target A orientation
 * @param a orientation in degrees
 */
void JointToCart::SetA(float a)
{
    data.set_target_a(a);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target B orientation
 * @param b orientation in degrees
 */
void JointToCart::SetB(float b)
{
    data.set_target_b(b);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target C orientation
 * @param c orientation in degrees
 */
void JointToCart::SetC(float c)
{
    data.set_target_c(c);
    data.clear_target_pos_variable();
}

/**
 * @brief Gets the target position for E1
 * @return position in user-defined units
 */
float JointToCart::GetE1() const
{
    return data.target_pos_ext_joints(0);
}

/**
 * @brief Gets the target position for E2
 * @return position in user-defined units
 */
float JointToCart::GetE2() const
{
    return data.target_pos_ext_joints(1);
}

/**
 * @brief Gets the target position for E3
 * @return position in user-defined units
 */
float JointToCart::GetE3() const
{
    return data.target_pos_ext_joints(2);
}

/**
 * @brief Sets the target position for E1
 * @param pos position in user-defined units
 */
void JointToCart::SetE1(float pos)
{
    data.set_target_pos_ext_joints(0, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for E2
 * @param pos position in user-defined units
 */
void JointToCart::SetE2(float pos)
{
    data.set_target_pos_ext_joints(1, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Sets the target position for E3
 * @param pos position in user-defined units
 */
void JointToCart::SetE3(float pos)
{
    data.set_target_pos_ext_joints(2, pos);
    data.clear_target_pos_variable();
}

/**
 * @brief Gets the velocity in percent (0..100)
 * @return
 */
float JointToCart::GetVelocity() const
{
    return data.velocity_percent();
}

/**
 * @brief Gets the acceleration in percent (0..100)
 * @return
 */
float JointToCart::GetAcceleration() const
{
    return data.acceleration_percent();
}

/**
 * @brief Gets the smoothing in percent (0..100)
 * @return
 */
float JointToCart::GetSmoothing() const
{
    return data.smoothing_percent();
}

/**
 * @brief Sets the velocity in percent (0..100)
 * @param vel
 */
void JointToCart::SetVelocity(float vel)
{
    data.set_velocity_percent(vel);
}

/**
 * @brief Sets the acceleration in percent (0..100)
 * @param acc
 */
void JointToCart::SetAcceleration(float acc)
{
    data.set_acceleration_percent(acc);
}

/**
 * @brief Sets the smoothing in percent (0..100)
 * @param smooth
 */
void JointToCart::SetSmoothing(float smooth)
{
    data.set_smoothing_percent(smooth);
}

/**
 * @brief Gets the abort condition
 * @return
 */
std::string JointToCart::GetAbortCondition()
{
    return data.abort_condition();
}

/**
 * @brief Sets the abort condition
 * @param condition abort condition, if true the motion is aborted
 */
void JointToCart::SetAbortCondition(const std::string& condition)
{
    data.set_abort_condition(condition);
}

/**
 * @brief Gets the reference frame
 * @return Reference frame name
 */
std::string JointToCart::GetReferenceFrame() const
{
    if (data.has_reference_frame())
        return data.reference_frame();
    else
        return "#base";
}

/**
 * @brief Sets the reference frame
 * @param frame Reference frame name
 */
void JointToCart::SetReferenceFrame(const std::string& frame)
{
    data.set_reference_frame(frame);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
