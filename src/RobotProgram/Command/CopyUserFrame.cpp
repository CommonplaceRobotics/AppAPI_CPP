#include "CopyUserFrame.h"

namespace App
{
namespace RobotProgram
{
namespace Command
{

/**
 * @brief Constructor
 * @param from Name of the user frame to copy from
 * @param to Name of the user frame to copy to
 */
CopyUserFrame::CopyUserFrame(const std::string from, const std::string& to)
{
    data.set_from(from);
    data.set_to(to);
}

/**
 * @brief Gets the command parameters for AddCommandRequest
 */
robotcontrolapp::AddCommandRequest_CmdParameters CopyUserFrame::GetCmdParameters() const
{
    robotcontrolapp::AddCommandRequest_CmdParameters ret;
    *ret.mutable_copy_user_frame() = data;
    return ret;
}

/**
 * @brief Gets the user frame to copy from
 * @return User frame name
 */
std::string CopyUserFrame::GetFrom() const
{
    return data.from();
}

/**
 * @brief Gets the user frame to copy to
 * @return User frame name
 */
std::string CopyUserFrame::GetTo() const
{
    return data.to();
}

/**
 * @brief Sets the user frame to copy from
 * @param User frame name
 */
void CopyUserFrame::SetFrom(const std::string& from)
{
    data.set_from(from);
}

/**
 * @brief Sets the user frame to copy to
 * @param User frame name
 */
void CopyUserFrame::SetTo(const std::string& to)
{
    data.set_to(to);
}

} // namespace Command
} // namespace RobotProgram
} // namespace App
