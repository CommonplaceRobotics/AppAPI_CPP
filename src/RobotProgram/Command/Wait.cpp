#include "Wait.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructs a wait by duration
 * @param seconds time in seconds
 */
Wait::Wait(float seconds)
{
    data.set_duration(seconds * 1000.0);
}

/**
 * @brief Constructs a wait by condition
 * @param condition wait condition. Once it evaluates TRUE the command finishes.
 */
Wait::Wait(const std::string& condition)
{
    data.set_condition(condition);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters Wait::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_wait() = data;
    return ret;
}

/**
 * @brief Is this a wait by duration?
 * @return
 */
bool Wait::IsDuration() const
{
    return data.has_duration();
}

/**
 * @brief Is this a wait by condition?
 * @return
 */
bool Wait::IsCondition() const
{
    return data.has_condition();
}

/**
 * @brief Gets the wait duration
 * @return duration in seconds
 */
float Wait::GetDuration() const
{
    return data.duration() / 1000.0;
}

/**
 * @brief Gets the wait condition
 * @return
 */
std::string Wait::GetCondition() const
{
    return data.condition();
}

/**
 * @brief Sets the wait duration
 * @param seconds duration in seconds
 */
void Wait::SetDuration(float seconds)
{
    data.set_duration(seconds * 1000.0);
}

/**
 * @brief Sets the wait condition
 * @param condition wait condition. Once it evaluates TRUE the command finishes.
 */
void Wait::SetCondition(const std::string& condition)
{
    data.set_condition(condition);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
