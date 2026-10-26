#include <RobotProgram/Command/ProgramControl.h>
#include <gtest/gtest.h>

TEST(App_Command_ProgramControl, ConstructorDefault)
{
    App::RobotProgram::Command::ProgramControl cmd;
    ASSERT_TRUE(cmd.GetCmdParameters().has_program_control());
    EXPECT_EQ(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Pause, cmd.GetCmdParameters().program_control().type());
}

TEST(App_Command_ProgramControl, Constructor)
{
    {
        App::RobotProgram::Command::ProgramControl cmd(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Stop);
        ASSERT_TRUE(cmd.GetCmdParameters().has_program_control());
        EXPECT_EQ(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Stop, cmd.GetCmdParameters().program_control().type());
    }

    {
        App::RobotProgram::Command::ProgramControl cmd(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Pause);
        ASSERT_TRUE(cmd.GetCmdParameters().has_program_control());
        EXPECT_EQ(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Pause, cmd.GetCmdParameters().program_control().type());
    }
}

TEST(App_Command_Stop, ConstructorDefault)
{
    App::RobotProgram::Command::Stop cmd;
    ASSERT_TRUE(cmd.GetCmdParameters().has_program_control());
    EXPECT_EQ(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Stop, cmd.GetCmdParameters().program_control().type());
}

TEST(App_Command_Pause, ConstructorDefault)
{
    App::RobotProgram::Command::Pause cmd;
    ASSERT_TRUE(cmd.GetCmdParameters().has_program_control());
    EXPECT_EQ(robotcontrolapp::CmdProgramControlParameters_Type::CmdProgramControlParameters_Type_Pause, cmd.GetCmdParameters().program_control().type());
}
