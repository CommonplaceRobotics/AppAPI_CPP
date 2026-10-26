#include <RobotProgram/Command/Gripper.h>
#include <gtest/gtest.h>

TEST(App_Command_Gripper, ConstructorDefault)
{
    App::RobotProgram::Command::Gripper cmd;
    EXPECT_EQ(0, cmd.GetTargetState());
    ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
    ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
    EXPECT_EQ(0, cmd.GetCmdParameters().gripper().target_states(0));
}

TEST(App_Command_Gripper, Constructor)
{
    {
        const float state = 0;

        App::RobotProgram::Command::Gripper cmd(state);
        EXPECT_EQ(state, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state, cmd.GetCmdParameters().gripper().target_states(0));
    }

    {
        const float state = -1;

        App::RobotProgram::Command::Gripper cmd(state);
        EXPECT_EQ(state, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state, cmd.GetCmdParameters().gripper().target_states(0));
    }

    {
        const float state = 100;

        App::RobotProgram::Command::Gripper cmd(state);
        EXPECT_EQ(state, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state, cmd.GetCmdParameters().gripper().target_states(0));
    }

    {
        const float state = 101;

        App::RobotProgram::Command::Gripper cmd(state);
        EXPECT_EQ(state, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state, cmd.GetCmdParameters().gripper().target_states(0));
    }
}

TEST(App_Command_Gripper, SetTargetState)
{
    {
        const float state1 = 12;
        const float state2 = 0;

        App::RobotProgram::Command::Gripper cmd(state1);
        ASSERT_EQ(state1, cmd.GetTargetState());

        cmd.SetTargetState(state2);
        EXPECT_EQ(state2, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state2, cmd.GetCmdParameters().gripper().target_states(0));
    }

    {
        const float state1 = 12;
        const float state2 = -1;

        App::RobotProgram::Command::Gripper cmd(state1);
        ASSERT_EQ(state1, cmd.GetTargetState());

        cmd.SetTargetState(state2);
        EXPECT_EQ(state2, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state2, cmd.GetCmdParameters().gripper().target_states(0));
    }

    {
        const float state1 = 12;
        const float state2 = 100;

        App::RobotProgram::Command::Gripper cmd(state1);
        ASSERT_EQ(state1, cmd.GetTargetState());

        cmd.SetTargetState(state2);
        EXPECT_EQ(state2, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state2, cmd.GetCmdParameters().gripper().target_states(0));
    }

    {
        const float state1 = 12;
        const float state2 = 101;

        App::RobotProgram::Command::Gripper cmd(state1);
        ASSERT_EQ(state1, cmd.GetTargetState());

        cmd.SetTargetState(state2);
        EXPECT_EQ(state2, cmd.GetTargetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_gripper());
        ASSERT_LE(1, cmd.GetCmdParameters().gripper().target_states_size());
        EXPECT_EQ(state2, cmd.GetCmdParameters().gripper().target_states(0));
    }
}
