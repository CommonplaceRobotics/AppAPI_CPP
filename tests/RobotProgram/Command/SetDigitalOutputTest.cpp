#include <RobotProgram/Command/SetDigitalOutput.h>
#include <gtest/gtest.h>

TEST(App_Command_SetDigitalOutput, ConstructorDefault)
{
    App::RobotProgram::Command::SetDigitalOutput cmd;
    EXPECT_EQ(0, cmd.GetID());
    EXPECT_FALSE(cmd.GetState());
    ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
    EXPECT_EQ(0, cmd.GetCmdParameters().set_digital_out().output_number());
    EXPECT_FALSE(cmd.GetCmdParameters().set_digital_out().target_state());
}

TEST(App_Command_SetDigitalOutput, Constructor)
{
    {
        const int id = 0;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 0;
        const bool state = true;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = -1;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 63;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 64;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }
}

TEST(App_Command_SetDigitalOutput, SetState)
{
    {
        const int id = 0;
        const bool state = false;
        const bool state_new = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 0;
        const bool state = false;
        const bool state_new = true;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 0;
        const bool state = true;
        const bool state_new = true;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 0;
        const bool state = true;
        const bool state_new = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        EXPECT_EQ(id, cmd.GetID());
        ASSERT_EQ(state, cmd.GetState());

        cmd.SetState(state_new);
        EXPECT_EQ(id, cmd.GetID());
        EXPECT_EQ(state_new, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state_new, cmd.GetCmdParameters().set_digital_out().target_state());
    }
}

TEST(App_Command_SetDigitalOutput, SetID)
{
    {
        const int id = 0;
        const int id_new = -1;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        ASSERT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());

        cmd.SetID(id_new);
        EXPECT_EQ(id_new, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id_new, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 0;
        const int id_new = 63;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        ASSERT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());

        cmd.SetID(id_new);
        EXPECT_EQ(id_new, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id_new, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }

    {
        const int id = 0;
        const int id_new = 64;
        const bool state = false;

        App::RobotProgram::Command::SetDigitalOutput cmd(id, state);
        ASSERT_EQ(id, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());

        cmd.SetID(id_new);
        EXPECT_EQ(id_new, cmd.GetID());
        EXPECT_EQ(state, cmd.GetState());
        ASSERT_TRUE(cmd.GetCmdParameters().has_set_digital_out());
        EXPECT_EQ(id_new, cmd.GetCmdParameters().set_digital_out().output_number());
        EXPECT_EQ(state, cmd.GetCmdParameters().set_digital_out().target_state());
    }
}
