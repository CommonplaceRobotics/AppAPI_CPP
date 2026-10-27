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
 * @brief Sets a digital output
 */
class SetDigitalOutput : public ICommand
{
public:
    robotcontrolapp::CmdSetDigitalOutParameters data;

    /**
     * @brief Default constructor
     */
    SetDigitalOutput() = default;

    /**
     * @brief Constructor
     * @param id Digital output ID with index base 0 (i.e. index 0 refers to DOut1). Range 0..63
     * @param state Target state
     */
    SetDigitalOutput(uint32_t id, bool state);

    /**
     * @brief Gets the command parameters for AddCommandRequest
     */
    virtual robotcontrolapp::AddCommandRequest_CmdParameters GetCmdParameters() const override;

    /**
     * @brief Gets the digital output ID
     * @return ID with index base 0 (i.e. index 0 refers to DOut1). Range 0..63
     */
    uint32_t GetID() const;
    /**
     * @brief Gets the target state
     * @return
     */
    bool GetState() const;

    /**
     * @brief Sets the digital output ID
     * @param id Digital output ID with index base 0 (i.e. index 0 refers to DOut1). Range 0..63
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
