#include <RobotProgram/Command/SetGlobalSignal.h>
#include <gtest/gtest.h>

TEST(App_Command_SetGlobalSignal, ConstructorDefault)
{
    App::RobotProgram::Command::SetGlobalSignal cmd;
    EXPECT_EQ(0, cmd.GetID());
    EXPECT_FALSE(cmd.GetState());
    ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
    EXPECT_EQ(0, cmd.GetCmdParameters().set_global_signal().output_number());
    EXPECT_FALSE(cmd.GetCmdParameters().set_global_signal().target_state());
}

TEST(App_Command_SetGlobalSignal, Constructor)
{
    {
        const int id = 0;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 0;
        const bool state = true;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = -1;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 99;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 100;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }
}

TEST(App_Command_SetGlobalSignal, SetState)
{
    {
        const int id = 0;
        const bool state = false;
        const bool state_new = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 0;
        const bool state = false;
        const bool state_new = true;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 0;
        const bool state = true;
        const bool state_new = true;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 0;
        const bool state = true;
        const bool state_new = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_global_signal().target_state());
    }
}

TEST(App_Command_SetGlobalSignal, SetID)
{
    {
        const int id = 0;
        const int id_new = -1;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        ASSERT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());

        cmd.SetID(id_new);
        EXPECT_EQ(id_new, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id_new, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 0;
        const int id_new = 99;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        ASSERT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());

        cmd.SetID(id_new);
        EXPECT_EQ(id_new, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id_new, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }

    {
        const int id = 0;
        const int id_new = 100;
        const bool state = false;

        App::RobotProgram::Command::SetGlobalSignal cmd(id, state);
        ASSERT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());

        cmd.SetID(id_new);
        EXPECT_EQ(id_new, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_global_signal());
        EXPECT_EQ(id_new, cmd.GetCmdParameters().set_global_signal().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_global_signal().target_state());
    }
}
