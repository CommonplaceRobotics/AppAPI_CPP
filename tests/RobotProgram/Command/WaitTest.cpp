#include <RobotProgram/Command/Wait.h>
#include <gtest/gtest.h>

TEST(App_Command_Wait, ConstructorDefault)
{
    App::RobotProgram::Command::Wait cmd;
    EXPECT_FALSE(cmd.IsDuration());
    EXPECT_FALSE(cmd.IsCondition());
    EXPECT_EQ(0, cmd.GetDuration());
    EXPECT_STREQ("", cmd.GetCondition().c_str());

    EXPECT_TRUE(cmd.GetCmdParameters().has_wait());
    EXPECT_FALSE(cmd.GetCmdParameters().wait().has_duration());
    EXPECT_FALSE(cmd.GetCmdParameters().wait().has_condition());
}

TEST(App_Command_Wait, ConstructorDuration)
{
    {
        const float duration = 123.45;
        App::RobotProgram::Command::Wait cmd(duration);
        EXPECT_TRUE(cmd.IsDuration());
        EXPECT_FALSE(cmd.IsCondition());
        EXPECT_EQ(duration, cmd.GetDuration());
        EXPECT_STREQ("", cmd.GetCondition().c_str());

        EXPECT_TRUE(cmd.GetCmdParameters().has_wait());
        ASSERT_TRUE(cmd.GetCmdParameters().wait().has_duration());
        EXPECT_EQ((int)(duration * 1000), cmd.GetCmdParameters().wait().duration());
        EXPECT_FALSE(cmd.GetCmdParameters().wait().has_condition());
    }

    // Negative duration
    {
        const float duration = -123.45;
        App::RobotProgram::Command::Wait cmd(duration);
        EXPECT_TRUE(cmd.IsDuration());
        EXPECT_FALSE(cmd.IsCondition());
        EXPECT_EQ(duration, cmd.GetDuration());
        EXPECT_STREQ("", cmd.GetCondition().c_str());

        EXPECT_TRUE(cmd.GetCmdParameters().has_wait());
        ASSERT_TRUE(cmd.GetCmdParameters().wait().has_duration());
        EXPECT_EQ((int)(duration * 1000), cmd.GetCmdParameters().wait().duration());
        EXPECT_FALSE(cmd.GetCmdParameters().wait().has_condition());
    }
}

TEST(App_Command_Wait, ConstructorCondition)
{
    {
        const std::string& cond = "DIn21 AND GSig10";
        App::RobotProgram::Command::Wait cmd(cond);
        EXPECT_FALSE(cmd.IsDuration());
        EXPECT_TRUE(cmd.IsCondition());
        EXPECT_EQ(0, cmd.GetDuration());
        EXPECT_STREQ(cond.c_str(), cmd.GetCondition().c_str());

        EXPECT_TRUE(cmd.GetCmdParameters().has_wait());
        EXPECT_FALSE(cmd.GetCmdParameters().wait().has_duration());
        ASSERT_TRUE(cmd.GetCmdParameters().wait().has_condition());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().wait().condition().c_str());
    }

    // Empty condition
    {
        const std::string& cond = "";
        App::RobotProgram::Command::Wait cmd(cond);
        EXPECT_FALSE(cmd.IsDuration());
        EXPECT_TRUE(cmd.IsCondition());
        EXPECT_EQ(0, cmd.GetDuration());
        EXPECT_STREQ(cond.c_str(), cmd.GetCondition().c_str());

        EXPECT_TRUE(cmd.GetCmdParameters().has_wait());
        EXPECT_FALSE(cmd.GetCmdParameters().wait().has_duration());
        ASSERT_TRUE(cmd.GetCmdParameters().wait().has_condition());
        EXPECT_STREQ(cond.c_str(), cmd.GetCmdParameters().wait().condition().c_str());
    }
}

TEST(App_Command_Wait, SetDuration)
{
    // From default constructor
    {
        float duration = 123.45;
        App::RobotProgram::Command::Wait cmd;
        cmd.SetDuration(duration);
        EXPECT_TRUE(cmd.IsDuration());
        EXPECT_FALSE(cmd.IsCondition());
        EXPECT_EQ(duration, cmd.GetDuration());
        EXPECT_STREQ("", cmd.GetCondition().c_str());
    }

    // From duration constructor
    {
        const float duration1 = 789.10;
        const float duration2 = 123.45;
        App::RobotProgram::Command::Wait cmd(duration1);
        ASSERT_EQ(duration1, cmd.GetDuration());
        cmd.SetDuration(duration2);
        EXPECT_TRUE(cmd.IsDuration());
        EXPECT_FALSE(cmd.IsCondition());
        EXPECT_EQ(duration2, cmd.GetDuration());
        EXPECT_STREQ("", cmd.GetCondition().c_str());
    }

    // From condition constructor
    {
        const float duration = 123.45;
        const std::string& cond = "DIn21 AND GSig10";
        App::RobotProgram::Command::Wait cmd(cond);
        cmd.SetDuration(duration);
        EXPECT_TRUE(cmd.IsDuration());
        EXPECT_FALSE(cmd.IsCondition());
        EXPECT_EQ(duration, cmd.GetDuration());
        EXPECT_STREQ("", cmd.GetCondition().c_str());
    }
}
