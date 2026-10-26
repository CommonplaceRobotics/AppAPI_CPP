#include <RobotProgram/Command/SetVelocity.h>
#include <gtest/gtest.h>

TEST(App_Command_SetVelocity, ConstructorDefault)
{
    App::RobotProgram::Command::SetVelocity cmd;
    EXPECT_EQ(0, cmd.GetE1());
    EXPECT_EQ(0, cmd.GetE2());
    EXPECT_EQ(0, cmd.GetE3());
    ASSERT_TRUE(cmd.GetCmdParameters().has_set_velocity());
    EXPECT_EQ(0, cmd.GetCmdParameters().set_velocity().velocity_e1());
    EXPECT_EQ(0, cmd.GetCmdParameters().set_velocity().velocity_e2());
    EXPECT_EQ(0, cmd.GetCmdParameters().set_velocity().velocity_e3());
}

TEST(App_Command_SetVelocity, Constructor3Float)
{
    {
        const float vel_e1 = 123;
        const float vel_e2 = 456;
        const float vel_e3 = 789;

        App::RobotProgram::Command::SetVelocity cmd(vel_e1, vel_e2, vel_e3);
        EXPECT_EQ(vel_e1, cmd.GetE1());
        EXPECT_EQ(vel_e2, cmd.GetE2());
        EXPECT_EQ(vel_e3, cmd.GetE3());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_velocity());
        EXPECT_EQ(vel_e1, cmd.GetCmdParameters().set_velocity().velocity_e1());
        EXPECT_EQ(vel_e2, cmd.GetCmdParameters().set_velocity().velocity_e2());
        EXPECT_EQ(vel_e3, cmd.GetCmdParameters().set_velocity().velocity_e3());
    }

    {
        const float vel_e1 = -123;
        const float vel_e2 = -456;
        const float vel_e3 = -789;

        App::RobotProgram::Command::SetVelocity cmd(vel_e1, vel_e2, vel_e3);
        EXPECT_EQ(vel_e1, cmd.GetE1());
        EXPECT_EQ(vel_e2, cmd.GetE2());
        EXPECT_EQ(vel_e3, cmd.GetE3());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_velocity());
        EXPECT_EQ(vel_e1, cmd.GetCmdParameters().set_velocity().velocity_e1());
        EXPECT_EQ(vel_e2, cmd.GetCmdParameters().set_velocity().velocity_e2());
        EXPECT_EQ(vel_e3, cmd.GetCmdParameters().set_velocity().velocity_e3());
    }
}

TEST(App_Command_SetVelocity, SetE1)
{
    {
        const float vel_e1_orig = 123;
        const float vel_e2_orig = 456;
        const float vel_e3_orig = 789;

        const float vel_new = 258;

        App::RobotProgram::Command::SetVelocity cmd(vel_e1_orig, vel_e2_orig, vel_e3_orig);
        ASSERT_EQ(vel_e1_orig, cmd.GetE1());
        ASSERT_EQ(vel_e2_orig, cmd.GetE2());
        ASSERT_EQ(vel_e3_orig, cmd.GetE3());

        cmd.SetE1(vel_new);
        EXPECT_EQ(vel_new, cmd.GetE1());
        EXPECT_EQ(vel_e2_orig, cmd.GetE2());
        EXPECT_EQ(vel_e3_orig, cmd.GetE3());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_velocity());
        EXPECT_EQ(vel_new, cmd.GetCmdParameters().set_velocity().velocity_e1());
        EXPECT_EQ(vel_e2_orig, cmd.GetCmdParameters().set_velocity().velocity_e2());
        EXPECT_EQ(vel_e3_orig, cmd.GetCmdParameters().set_velocity().velocity_e3());
    }
}

TEST(App_Command_SetVelocity, SetE2)
{
    {
        const float vel_e1_orig = 123;
        const float vel_e2_orig = 456;
        const float vel_e3_orig = 789;

        const float vel_new = 258;

        App::RobotProgram::Command::SetVelocity cmd(vel_e1_orig, vel_e2_orig, vel_e3_orig);
        ASSERT_EQ(vel_e1_orig, cmd.GetE1());
        ASSERT_EQ(vel_e2_orig, cmd.GetE2());
        ASSERT_EQ(vel_e3_orig, cmd.GetE3());

        cmd.SetE2(vel_new);
        EXPECT_EQ(vel_e1_orig, cmd.GetE1());
        EXPECT_EQ(vel_new, cmd.GetE2());
        EXPECT_EQ(vel_e3_orig, cmd.GetE3());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_velocity());
        EXPECT_EQ(vel_e1_orig, cmd.GetCmdParameters().set_velocity().velocity_e1());
        EXPECT_EQ(vel_new, cmd.GetCmdParameters().set_velocity().velocity_e2());
        EXPECT_EQ(vel_e3_orig, cmd.GetCmdParameters().set_velocity().velocity_e3());
    }
}

TEST(App_Command_SetVelocity, SetE3)
{
    {
        const float vel_e1_orig = 123;
        const float vel_e2_orig = 456;
        const float vel_e3_orig = 789;

        const float vel_new = 258;

        App::RobotProgram::Command::SetVelocity cmd(vel_e1_orig, vel_e2_orig, vel_e3_orig);
        ASSERT_EQ(vel_e1_orig, cmd.GetE1());
        ASSERT_EQ(vel_e2_orig, cmd.GetE2());
        ASSERT_EQ(vel_e3_orig, cmd.GetE3());

        cmd.SetE3(vel_new);
        EXPECT_EQ(vel_e1_orig, cmd.GetE1());
        EXPECT_EQ(vel_e2_orig, cmd.GetE2());
        EXPECT_EQ(vel_new, cmd.GetE3());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_velocity());
        EXPECT_EQ(vel_e1_orig, cmd.GetCmdParameters().set_velocity().velocity_e1());
        EXPECT_EQ(vel_e2_orig, cmd.GetCmdParameters().set_velocity().velocity_e2());
        EXPECT_EQ(vel_new, cmd.GetCmdParameters().set_velocity().velocity_e3());
    }
}
