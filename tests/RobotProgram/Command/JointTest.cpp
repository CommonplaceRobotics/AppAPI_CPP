#include <RobotProgram/Command/Joint.h>
#include <gtest/gtest.h>

TEST(App_Command_Joint, ConstructorDefault)
{
    App::RobotProgram::Command::Joint cmd;
    EXPECT_TRUE(cmd.IsPositionConstant());
    EXPECT_FALSE(cmd.IsPositionFromVariable());
    EXPECT_STREQ("", cmd.GetVariable().c_str());
    EXPECT_EQ(0, cmd.GetA1());
    EXPECT_EQ(0, cmd.GetA2());
    EXPECT_EQ(0, cmd.GetA3());
    EXPECT_EQ(0, cmd.GetA4());
    EXPECT_EQ(0, cmd.GetA5());
    EXPECT_EQ(0, cmd.GetA6());
    EXPECT_EQ(0, cmd.GetE1());
    EXPECT_EQ(0, cmd.GetE2());
    EXPECT_EQ(0, cmd.GetE3());
    EXPECT_EQ(40, cmd.GetVelocity());
    EXPECT_EQ(40, cmd.GetAcceleration());
    EXPECT_EQ(0, cmd.GetSmoothing());
    EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

    ASSERT_TRUE(cmd.GetCmdParameters().has_joint());
    EXPECT_FALSE(cmd.GetCmdParameters().joint().has_target_pos_variable());
    ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    EXPECT_EQ(40, cmd.GetCmdParameters().joint().velocity_percent());
    EXPECT_EQ(40, cmd.GetCmdParameters().joint().acceleration_percent());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint().smoothing_percent());
    EXPECT_STREQ("false", cmd.GetCmdParameters().joint().abort_condition().c_str());
}

TEST(App_Command_Joint, ConstructorConstPosition)
{
    {
        const float pos[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        const float vel = 12.3;
        const float acc = 23.4;
        const float smooth = 34.5;

        App::RobotProgram::Command::Joint cmd(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], vel, acc, smooth);
        EXPECT_TRUE(cmd.IsPositionConstant());
        EXPECT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetVariable().c_str());
        EXPECT_EQ(pos[0], cmd.GetA1());
        EXPECT_EQ(pos[1], cmd.GetA2());
        EXPECT_EQ(pos[2], cmd.GetA3());
        EXPECT_EQ(pos[3], cmd.GetA4());
        EXPECT_EQ(pos[4], cmd.GetA5());
        EXPECT_EQ(pos[5], cmd.GetA6());
        EXPECT_EQ(pos[6], cmd.GetE1());
        EXPECT_EQ(pos[7], cmd.GetE2());
        EXPECT_EQ(pos[8], cmd.GetE3());
        EXPECT_EQ(vel, cmd.GetVelocity());
        EXPECT_EQ(acc, cmd.GetAcceleration());
        EXPECT_EQ(smooth, cmd.GetSmoothing());
        EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

        ASSERT_TRUE(cmd.GetCmdParameters().has_joint());
        EXPECT_FALSE(cmd.GetCmdParameters().joint().has_target_pos_variable());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(pos[0], cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(pos[1], cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(pos[2], cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(pos[3], cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(pos[4], cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(pos[5], cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(pos[6], cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(pos[7], cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(pos[8], cmd.GetCmdParameters().joint().target_pos(8));
        EXPECT_EQ(vel, cmd.GetCmdParameters().joint().velocity_percent());
        EXPECT_EQ(acc, cmd.GetCmdParameters().joint().acceleration_percent());
        EXPECT_EQ(smooth, cmd.GetCmdParameters().joint().smoothing_percent());
        EXPECT_STREQ("false", cmd.GetCmdParameters().joint().abort_condition().c_str());
    }
}

TEST(App_Command_Joint, ConstructorVariablePosition)
{
    {
        const std::string varName = "";

        App::RobotProgram::Command::Joint cmd(varName);
        EXPECT_FALSE(cmd.IsPositionConstant());
        EXPECT_TRUE(cmd.IsPositionFromVariable());
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_EQ(0, cmd.GetA1());
        EXPECT_EQ(0, cmd.GetA2());
        EXPECT_EQ(0, cmd.GetA3());
        EXPECT_EQ(0, cmd.GetA4());
        EXPECT_EQ(0, cmd.GetA5());
        EXPECT_EQ(0, cmd.GetA6());
        EXPECT_EQ(0, cmd.GetE1());
        EXPECT_EQ(0, cmd.GetE2());
        EXPECT_EQ(0, cmd.GetE3());
        EXPECT_EQ(40, cmd.GetVelocity());
        EXPECT_EQ(40, cmd.GetAcceleration());
        EXPECT_EQ(0, cmd.GetSmoothing());
        EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

        ASSERT_TRUE(cmd.GetCmdParameters().has_joint());
        ASSERT_TRUE(cmd.GetCmdParameters().joint().has_target_pos_variable());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
        EXPECT_EQ(40, cmd.GetCmdParameters().joint().velocity_percent());
        EXPECT_EQ(40, cmd.GetCmdParameters().joint().acceleration_percent());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().smoothing_percent());
        EXPECT_STREQ("false", cmd.GetCmdParameters().joint().abort_condition().c_str());
    }
}

TEST(App_Command_Joint, SetVariable)
{
    {
        const std::string varName = "";

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_STREQ("", cmd.GetVariable().c_str());

        cmd.SetVariable(varName);
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().joint().target_pos_variable().c_str());
    }

    {
        const std::string varName = "Foo";

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_STREQ("", cmd.GetVariable().c_str());

        cmd.SetVariable(varName);
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().joint().target_pos_variable().c_str());
    }
}

TEST(App_Command_Joint, SetA1)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA1());

        cmd.SetA1(val);
        EXPECT_EQ(val, cmd.GetA1());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA1());

        cmd.SetA1(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetA1());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetA2)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA2());

        cmd.SetA2(val);
        EXPECT_EQ(val, cmd.GetA2());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA2());

        cmd.SetA2(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetA2());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetA3)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA3());

        cmd.SetA3(val);
        EXPECT_EQ(val, cmd.GetA3());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA3());

        cmd.SetA3(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetA3());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetA4)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA4());

        cmd.SetA4(val);
        EXPECT_EQ(val, cmd.GetA4());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA4());

        cmd.SetA4(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetA4());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetA5)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA5());

        cmd.SetA5(val);
        EXPECT_EQ(val, cmd.GetA5());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA5());

        cmd.SetA5(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetA5());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetA6)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA6());

        cmd.SetA6(val);
        EXPECT_EQ(val, cmd.GetA6());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetA6());

        cmd.SetA6(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetA6());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetE1)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE1());

        cmd.SetE1(val);
        EXPECT_EQ(val, cmd.GetE1());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE1());

        cmd.SetE1(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE1());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetE2)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE2());

        cmd.SetE2(val);
        EXPECT_EQ(val, cmd.GetE2());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE2());

        cmd.SetE2(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE2());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetE3)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE3());

        cmd.SetE3(val);
        EXPECT_EQ(val, cmd.GetE3());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(8));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Joint cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE3());

        cmd.SetE3(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE3());
        ASSERT_EQ(9, cmd.GetCmdParameters().joint().target_pos_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(2));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(3));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(4));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(5));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(6));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint().target_pos(7));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().target_pos(8));
    }
}

TEST(App_Command_Joint, SetVelocity)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::Joint cmd;
        cmd.SetVelocity(val);
        EXPECT_EQ(val, cmd.GetVelocity());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().velocity_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::Joint cmd;
        cmd.SetVelocity(val);
        EXPECT_EQ(val, cmd.GetVelocity());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().velocity_percent());
    }
}

TEST(App_Command_Joint, SetAcceleration)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::Joint cmd;
        cmd.SetAcceleration(val);
        EXPECT_EQ(val, cmd.GetAcceleration());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().acceleration_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::Joint cmd;
        cmd.SetAcceleration(val);
        EXPECT_EQ(val, cmd.GetAcceleration());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().acceleration_percent());
    }
}

TEST(App_Command_Joint, SetSmoothing)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::Joint cmd;
        cmd.SetSmoothing(val);
        EXPECT_EQ(val, cmd.GetSmoothing());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().smoothing_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::Joint cmd;
        cmd.SetSmoothing(val);
        EXPECT_EQ(val, cmd.GetSmoothing());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint().smoothing_percent());
    }
}

TEST(App_Command_Joint, SetAbortCondition)
{
    {
        const std::string cond = "DIn21";
        App::RobotProgram::Command::Joint cmd;
        cmd.SetAbortCondition(cond);
        EXPECT_STREQ(cond.c_str(), cmd.GetAbortCondition().c_str());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().joint().abort_condition().c_str());
    }

    {
        const std::string cond = "";
        App::RobotProgram::Command::Joint cmd;
        cmd.SetAbortCondition(cond);
        EXPECT_STREQ(cond.c_str(), cmd.GetAbortCondition().c_str());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().joint().abort_condition().c_str());
    }
}
