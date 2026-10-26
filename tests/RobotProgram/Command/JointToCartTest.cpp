#include <RobotProgram/Command/JointToCart.h>
#include <gtest/gtest.h>

TEST(App_Command_JointToCart, ConstructorDefault)
{
    App::RobotProgram::Command::JointToCart cmd;
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
    EXPECT_EQ(40, cmd.GetVelocity());
    EXPECT_EQ(40, cmd.GetAcceleration());
    EXPECT_EQ(0, cmd.GetSmoothing());
    EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

    ASSERT_TRUE(cmd.GetCmdParameters().has_joint_to_cart());
    EXPECT_FALSE(cmd.GetCmdParameters().joint_to_cart().has_target_pos_variable());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
    ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    EXPECT_EQ(40, cmd.GetCmdParameters().joint_to_cart().velocity_percent());
    EXPECT_EQ(40, cmd.GetCmdParameters().joint_to_cart().acceleration_percent());
    EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().smoothing_percent());
    EXPECT_STREQ("false", cmd.GetCmdParameters().joint_to_cart().abort_condition().c_str());
}

TEST(App_Command_JointToCart, ConstructorConstPosition)
{
    {
        const float pos[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        const float vel = 12.3;
        const float acc = 23.4;
        const float smooth = 34.5;

        App::RobotProgram::Command::JointToCart cmd(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], vel, acc, smooth);
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

        ASSERT_TRUE(cmd.GetCmdParameters().has_joint_to_cart());
        EXPECT_FALSE(cmd.GetCmdParameters().joint_to_cart().has_target_pos_variable());
        EXPECT_EQ(pos[0], cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(pos[1], cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(pos[2], cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(pos[3], cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(pos[4], cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(pos[5], cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(pos[6], cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(pos[7], cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(pos[8], cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
        EXPECT_EQ(vel, cmd.GetCmdParameters().joint_to_cart().velocity_percent());
        EXPECT_EQ(acc, cmd.GetCmdParameters().joint_to_cart().acceleration_percent());
        EXPECT_EQ(smooth, cmd.GetCmdParameters().joint_to_cart().smoothing_percent());
        EXPECT_STREQ("false", cmd.GetCmdParameters().joint_to_cart().abort_condition().c_str());
    }
}

TEST(App_Command_JointToCart, ConstructorVariablePosition)
{
    {
        const std::string varName = "";

        App::RobotProgram::Command::JointToCart cmd(varName);
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
        EXPECT_EQ(40, cmd.GetVelocity());
        EXPECT_EQ(40, cmd.GetAcceleration());
        EXPECT_EQ(0, cmd.GetSmoothing());
        EXPECT_STREQ("false", cmd.GetAbortCondition().c_str());

        ASSERT_TRUE(cmd.GetCmdParameters().has_joint_to_cart());
        ASSERT_TRUE(cmd.GetCmdParameters().joint_to_cart().has_target_pos_variable());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
        EXPECT_EQ(40, cmd.GetCmdParameters().joint_to_cart().velocity_percent());
        EXPECT_EQ(40, cmd.GetCmdParameters().joint_to_cart().acceleration_percent());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().smoothing_percent());
        EXPECT_STREQ("false", cmd.GetCmdParameters().joint_to_cart().abort_condition().c_str());
    }
}

TEST(App_Command_JointToCart, SetVariable)
{
    {
        const std::string varName = "";

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_STREQ("", cmd.GetVariable().c_str());

        cmd.SetVariable(varName);
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
    }

    {
        const std::string varName = "Foo";

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_STREQ("", cmd.GetVariable().c_str());

        cmd.SetVariable(varName);
        EXPECT_STREQ(varName.c_str(), cmd.GetVariable().c_str());
        EXPECT_STREQ(varName.c_str(), cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
    }
}

TEST(App_Command_JointToCart, SetTargetX)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetX());

        cmd.SetTargetX(val);
        EXPECT_EQ(val, cmd.GetTargetX());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetX());

        cmd.SetTargetX(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetX());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetTargetY)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetY());

        cmd.SetTargetY(val);
        EXPECT_EQ(val, cmd.GetTargetY());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetY());

        cmd.SetTargetY(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetY());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetTargetZ)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetZ());

        cmd.SetTargetZ(val);
        EXPECT_EQ(val, cmd.GetTargetZ());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetZ());

        cmd.SetTargetZ(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetZ());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetTargetA)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetA());

        cmd.SetTargetA(val);
        EXPECT_EQ(val, cmd.GetTargetA());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetA());

        cmd.SetTargetA(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetA());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetTargetB)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetB());

        cmd.SetTargetB(val);
        EXPECT_EQ(val, cmd.GetTargetB());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetB());

        cmd.SetTargetB(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetB());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetTargetC)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetC());

        cmd.SetTargetC(val);
        EXPECT_EQ(val, cmd.GetTargetC());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_c());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetTargetC());

        cmd.SetTargetC(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetTargetC());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetE1)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE1());

        cmd.SetE1(val);
        EXPECT_EQ(val, cmd.GetE1());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE1());

        cmd.SetE1(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE1());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetE2)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE2());

        cmd.SetE2(val);
        EXPECT_EQ(val, cmd.GetE2());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE2());

        cmd.SetE2(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE2());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetE3)
{
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd;
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE3());

        cmd.SetE3(val);
        EXPECT_EQ(val, cmd.GetE3());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }

    // From variable position
    {
        const float val = 123.45;

        App::RobotProgram::Command::JointToCart cmd("Foo");
        ASSERT_FALSE(cmd.IsPositionConstant());
        ASSERT_TRUE(cmd.IsPositionFromVariable());
        ASSERT_EQ(0, cmd.GetE3());

        cmd.SetE3(val);
        ASSERT_TRUE(cmd.IsPositionConstant());
        ASSERT_FALSE(cmd.IsPositionFromVariable());
        EXPECT_STREQ("", cmd.GetCmdParameters().joint_to_cart().target_pos_variable().c_str());
        EXPECT_EQ(val, cmd.GetE3());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_x());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_y());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_z());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_a());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_b());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_c());
        ASSERT_EQ(3, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints_size());
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(0));
        EXPECT_EQ(0, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(1));
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().target_pos_ext_joints(2));
    }
}

TEST(App_Command_JointToCart, SetVelocity)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetVelocity(val);
        EXPECT_EQ(val, cmd.GetVelocity());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().velocity_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetVelocity(val);
        EXPECT_EQ(val, cmd.GetVelocity());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().velocity_percent());
    }
}

TEST(App_Command_JointToCart, SetAcceleration)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetAcceleration(val);
        EXPECT_EQ(val, cmd.GetAcceleration());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().acceleration_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetAcceleration(val);
        EXPECT_EQ(val, cmd.GetAcceleration());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().acceleration_percent());
    }
}

TEST(App_Command_JointToCart, SetSmoothing)
{
    {
        const float val = 12.3;
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetSmoothing(val);
        EXPECT_EQ(val, cmd.GetSmoothing());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().smoothing_percent());
    }

    {
        const float val = -12.3;
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetSmoothing(val);
        EXPECT_EQ(val, cmd.GetSmoothing());
        EXPECT_EQ(val, cmd.GetCmdParameters().joint_to_cart().smoothing_percent());
    }
}

TEST(App_Command_JointToCart, SetAbortCondition)
{
    {
        const std::string cond = "DIn21";
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetAbortCondition(cond);
        EXPECT_STREQ(cond.c_str(), cmd.GetAbortCondition().c_str());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().joint_to_cart().abort_condition().c_str());
    }

    {
        const std::string cond = "";
        App::RobotProgram::Command::JointToCart cmd;
        cmd.SetAbortCondition(cond);
        EXPECT_STREQ(cond.c_str(), cmd.GetAbortCondition().c_str());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().joint_to_cart().abort_condition().c_str());
    }
}
