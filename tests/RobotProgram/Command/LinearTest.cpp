#include <RobotProgram/Command/Linear.h>
#include <gtest/gtest.h>

TEST(App_Command_Linear, ConstructorDefault)
{
    App::RobotProgram::Command::Linear cmd;
    EXPECT_TRUE(cmd.IsPositionConstant());
    EXPECT_FALSE(cmd.IsPositionFromVariable());
    EXPECT_STREQ("", cmd.GetVariable().c_str());
    EXPECT_EQ(0, cmd.GetTargetX());
    EXPECT_EQ(0, cmd.GetTargetY());
    EXPECT_EQ(0, cmd.GetTargetZ());
    EXPECT_EQ(0, cmd.GetTargetA());
    EXPECT_EQ(0, cmd.GetTargetB());
    EXPECT_EQ(0, cmd.GetTargetC());
    EXPECT_EQ(0, cmd.GetE1());
    EXPECT_EQ(0, cmd.GetE2());
    EXPECT_EQ(0, cmd.GetE3());
    EXPECT_EQ(100, cmd.GetVelocity());
    EXPECT_EQ(40, cmd.GetAcceleration());
    EXPECT_EQ(0, cmd.GetSmoothing());
    EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

    ASSERT_TRUE(cmd.GetCmdParameters().has_linear());
    EXPECT_FALSE(cmd.GetCmdParameters().linear().has_target_pos_variable());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
    ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    EXPECT_EQ(100, cmd.GetCmdParameters().linear().velocity_mms());
    EXPECT_EQ(40, cmd.GetCmdParameters().linear().acceleration_percent());
    EXPECT_EQ(0, cmd.GetCmdParameters().linear().smoothing_percent());
    EXPECT_STREQ("false", cmd.GetCmdParameters().linear().abort_condition().c_str());
}

TEST(App_Command_Linear, ConstructorConstPosition)
{
    {
        const float pos[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        const float vel = 12.3;
        const float acc = 23.4;
        const float smooth = 34.5;

        App::RobotProgram::Command::Linear cmd(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], vel, acc, smooth);
        EXPECT_TRUE(cmd.IsPositionConstant());
        EXPECT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetVariable().c_str());
        EXPECT_EQ(pos[0], cmd.GetTargetX());
        EXPECT_EQ(pos[1], cmd.GetTargetY());
        EXPECT_EQ(pos[2], cmd.GetTargetZ());
        EXPECT_EQ(pos[3], cmd.GetTargetA());
        EXPECT_EQ(pos[4], cmd.GetTargetB());
        EXPECT_EQ(pos[5], cmd.GetTargetC());
        EXPECT_EQ(pos[6], cmd.GetE1());
        EXPECT_EQ(pos[7], cmd.GetE2());
        EXPECT_EQ(pos[8], cmd.GetE3());
        EXPECT_EQ(vel, cmd.GetVelocity());
        EXPECT_EQ(acc, cmd.GetAcceleration());
        EXPECT_EQ(smooth, cmd.GetSmoothing());
        EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

        ASSERT_TRUE(cmd.GetCmdParameters().has_linear());
        EXPECT_FALSE(cmd.GetCmdParameters().linear().has_target_pos_variable());
        EXPECT_EQ(pos[0], cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(pos[1], cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(pos[2], cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(pos[3], cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(pos[4], cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(pos[5], cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(pos[6], cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(pos[7], cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(pos[8], cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
        EXPECT_EQ(vel, cmd.GetCmdParameters().linear().velocity_mms());
        EXPECT_EQ(acc, cmd.GetCmdParameters().linear().acceleration_percent());
        EXPECT_EQ(smooth, cmd.GetCmdParameters().linear().smoothing_percent());
        EXPECT_STREQ("false", cmd.GetCmdParameters().linear().abort_condition().c_str());
    }
}

TEST(App_Command_Linear, ConstructorVariablePosition)
{
    {
        const std::string varName = "";

        App::RobotProgram::Command::Linear cmd(varName);
        EXPECT_FALSE(cmd.IsPositionConstant());
        EXPECT_TRUE(cmd.IsPositionFromVariable());
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_EQ(0, cmd.GetTargetX());
        EXPECT_EQ(0, cmd.GetTargetY());
        EXPECT_EQ(0, cmd.GetTargetZ());
        EXPECT_EQ(0, cmd.GetTargetA());
        EXPECT_EQ(0, cmd.GetTargetB());
        EXPECT_EQ(0, cmd.GetTargetC());
        EXPECT_EQ(0, cmd.GetE1());
        EXPECT_EQ(0, cmd.GetE2());
        EXPECT_EQ(0, cmd.GetE3());
        EXPECT_EQ(100, cmd.GetVelocity());
        EXPECT_EQ(40, cmd.GetAcceleration());
        EXPECT_EQ(0, cmd.GetSmoothing());
        EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

        ASSERT_TRUE(cmd.GetCmdParameters().has_linear());
        ASSERT_TRUE(cmd.GetCmdParameters().linear().has_target_pos_variable());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
        EXPECT_EQ(100, cmd.GetCmdParameters().linear().velocity_mms());
        EXPECT_EQ(40, cmd.GetCmdParameters().linear().acceleration_percent());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().smoothing_percent());
        EXPECT_STREQ("false", cmd.GetCmdParameters().linear().abort_condition().c_str());
    }
}

TEST(App_Command_Linear, SetVariable)
{
    {
        const std::string varName = "";

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_STREQ("", cmd.GetVariable().c_str());

        cmd.SetVariable(varName);
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().linear().target_pos_variable().c_str());
    }

    {
        const std::string varName = "Foo";

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_STREQ("", cmd.GetVariable().c_str());

        cmd.SetVariable(varName);
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().linear().target_pos_variable().c_str());
    }
}

TEST(App_Command_Linear, SetTargetX)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetX());

        cmd.SetTargetX(val);
        EXPECT_EQ(val, cmd.GetTargetX());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetX());

        cmd.SetTargetX(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetX());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetTargetY)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetY());

        cmd.SetTargetY(val);
        EXPECT_EQ(val, cmd.GetTargetY());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetY());

        cmd.SetTargetY(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetY());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetTargetZ)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetZ());

        cmd.SetTargetZ(val);
        EXPECT_EQ(val, cmd.GetTargetZ());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetZ());

        cmd.SetTargetZ(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetZ());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetTargetA)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetA());

        cmd.SetTargetA(val);
        EXPECT_EQ(val, cmd.GetTargetA());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetA());

        cmd.SetTargetA(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetA());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetTargetB)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetB());

        cmd.SetTargetB(val);
        EXPECT_EQ(val, cmd.GetTargetB());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetB());

        cmd.SetTargetB(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetB());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetTargetC)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetC());

        cmd.SetTargetC(val);
        EXPECT_EQ(val, cmd.GetTargetC());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_c());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetC());

        cmd.SetTargetC(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetC());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetE1)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE1());

        cmd.SetE1(val);
        EXPECT_EQ(val, cmd.GetE1());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE1());

        cmd.SetE1(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE1());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetE2)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE2());

        cmd.SetE2(val);
        EXPECT_EQ(val, cmd.GetE2());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE2());

        cmd.SetE2(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE2());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetE3)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE3());

        cmd.SetE3(val);
        EXPECT_EQ(val, cmd.GetE3());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::Linear cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE3());

        cmd.SetE3(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().linear().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE3());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().linear().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().linear().target_pos_ext_joints(1));
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().target_pos_ext_joints(2));
    }
}

TEST(App_Command_Linear, SetVelocity)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::Linear cmd;
        cmd.SetVelocity(val);
        EXPECT_EQ(val, cmd.GetVelocity());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().velocity_mms());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::Linear cmd;
        cmd.SetVelocity(val);
        EXPECT_EQ(val, cmd.GetVelocity());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().velocity_mms());
    }
}

TEST(App_Command_Linear, SetAcceleration)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::Linear cmd;
        cmd.SetAcceleration(val);
        EXPECT_EQ(val, cmd.GetAcceleration());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().acceleration_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::Linear cmd;
        cmd.SetAcceleration(val);
        EXPECT_EQ(val, cmd.GetAcceleration());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().acceleration_percent());
    }
}

TEST(App_Command_Linear, SetSmoothing)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::Linear cmd;
        cmd.SetSmoothing(val);
        EXPECT_EQ(val, cmd.GetSmoothing());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().smoothing_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::Linear cmd;
        cmd.SetSmoothing(val);
        EXPECT_EQ(val, cmd.GetSmoothing());
        EXPECT_EQ(val, cmd.GetCmdParameters().linear().smoothing_percent());
    }
}

TEST(App_Command_Linear, SetAbortCondition)
{
    {
        const std::string cond = "DIn21";
        App::RobotProgram::Command::Linear cmd;
        cmd.SetAbortCondition(cond);
        EXPECT_STREQ(cond.c_str(), cmd.GetAbortCondition().c_str());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().linear().abort_condition().c_str());
    }

    {
        const std::string cond = "";
        App::RobotProgram::Command::Linear cmd;
        cmd.SetAbortCondition(cond);
        EXPECT_STREQ(cond.c_str(), cmd.GetAbortCondition().c_str());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().linear().abort_condition().c_str());
    }
}
