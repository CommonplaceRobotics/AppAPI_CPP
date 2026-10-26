#include <RobotProgram/Command/SubProgram.h>
#include <gtest/gtest.h>

TEST(App_Command_Subprogram, ConstructorDefault)
{
    App::RobotProgram::Command::SubProgram cmd;
    EXPECT_STREQ("", cmd.GetProgram().c_str());
    EXPECT_TRUE(cmd.GetCmdParameters().has_subprogram());
    EXPECT_STREQ("", cmd.GetCmdParameters().subprogram().program_name().c_str());
}

TEST(App_Command_Subprogram, ConstructorProgramName)
{
    {
        std::string programName = "";
        App::RobotProgram::Command::SubProgram cmd(programName);
        EXPECT_STREQ(programName.c_str(), cmd.GetProgram().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_subprogram());
        EXPECT_STREQ(programName.c_str(), cmd.GetCmdParameters().subprogram().program_name().c_str());
    }

    {
        std::string programName = "Foo.xml";
        App::RobotProgram::Command::SubProgram cmd(programName);
        EXPECT_STREQ(programName.c_str(), cmd.GetProgram().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_subprogram());
        EXPECT_STREQ(programName.c_str(), cmd.GetCmdParameters().subprogram().program_name().c_str());
    }

    {
        std::string programName = "Foo/Bar.xml";
        App::RobotProgram::Command::SubProgram cmd(programName);
        EXPECT_STREQ(programName.c_str(), cmd.GetProgram().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_subprogram());
        EXPECT_STREQ(programName.c_str(), cmd.GetCmdParameters().subprogram().program_name().c_str());
    }
}

TEST(App_Command_Subprogram, SetProgram)
{
    {
        const std::string prog1 = "Foo";
        const std::string prog2 = "Bar";
        App::RobotProgram::Command::SubProgram cmd(prog1);
        ASSERT_STREQ(prog1.c_str(), cmd.GetProgram().c_str());
        cmd.SetProgram(prog2);
        EXPECT_STREQ(prog2.c_str(), cmd.GetProgram().c_str());
        EXPECT_STREQ(prog2.c_str(), cmd.GetCmdParameters().subprogram().program_name().c_str());
    }

    {
        const std::string prog1 = "Foo";
        const std::string prog2 = "";
        App::RobotProgram::Command::SubProgram cmd(prog1);
        ASSERT_STREQ(prog1.c_str(), cmd.GetProgram().c_str());
        cmd.SetProgram(prog2);
        EXPECT_STREQ(prog2.c_str(), cmd.GetProgram().c_str());
        EXPECT_STREQ(prog2.c_str(), cmd.GetCmdParameters().subprogram().program_name().c_str());
    }
}
