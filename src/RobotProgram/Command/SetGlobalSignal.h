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
 * @brief Sets a global signal
 */
class SetGlobalSignal : public ICommand
{
public:
    robotcontrolapp::CmdSetGlobalSignalParameters data;

    /**
     * @brief Default constructor
     */
    SetGlobalSignal() = default;

    /**
     * @brief Constructor
     * @param id Global signal ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..99
     * @param state Target state
     */
    SetGlobalSignal(uint32_t id, bool state);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Gets the global signal ID
     * @return ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..99
     */
    uint32_t GetID() const;
    /**
     * @brief Gets the target state
     * @return
     */
    bool GetState() const;

    /**
     * @brief Sets the global signal ID
     * @param id Global signal ID with index base 0 (i.e. index 0 refers to GSig1). Range 0..99
     */
    void SetID(uint32_t id);
    /**
     * @brief Sets the target state
     * @param state target state
     */
    void SetState(bool state);
};

} // namespace Command
} // namespace RobotProgram
} // namespace App
