#include <RobotProgram/Command/CopyUserFrame.h>
#include <gtest/gtest.h>

TEST(App_Command_CopyUserFrame, ConstructorDefault)
{
    App::RobotProgram::Command::CopyUserFrame cmd;
    EXPECT_STREQ("", cmd.GetFrom().c_str());
    EXPECT_STREQ("", cmd.GetTo().c_str());
    ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
    EXPECT_STREQ("", cmd.GetCmdParameters().copy_user_frame().from().c_str());
    EXPECT_STREQ("", cmd.GetCmdParameters().copy_user_frame().to().c_str());
}

TEST(App_Command_CopyUserFrame, Constructor)
{
    {
        const std::string from = "";
        const std::string to = "";

        App::RobotProgram::Command::CopyUserFrame cmd(from, to);
        EXPECT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetTo().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
        EXPECT_STREQ(from.c_str(), cmd.GetCmdParameters().copy_user_frame().from().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetCmdParameters().copy_user_frame().to().c_str());
    }

    {
        const std::string from = "Foo";
        const std::string to = "Bar";

        App::RobotProgram::Command::CopyUserFrame cmd(from, to);
        EXPECT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetTo().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
        EXPECT_STREQ(from.c_str(), cmd.GetCmdParameters().copy_user_frame().from().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetCmdParameters().copy_user_frame().to().c_str());
    }
}

TEST(App_Command_CopyUserFrame, SetFrom)
{
    {
        const std::string from = "Foo";
        const std::string to = "Bar";

        const std::string from_new = "Baz";

        App::RobotProgram::Command::CopyUserFrame cmd(from, to);
        ASSERT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        ASSERT_STREQ(to.c_str(), cmd.GetTo().c_str());

        cmd.SetFrom(from_new);
        EXPECT_STREQ(from_new.c_str(), cmd.GetFrom().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetTo().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
        EXPECT_STREQ(from_new.c_str(), cmd.GetCmdParameters().copy_user_frame().from().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetCmdParameters().copy_user_frame().to().c_str());
    }

    {
        const std::string from = "Foo";
        const std::string to = "Bar";

        const std::string from_new = "";

        App::RobotProgram::Command::CopyUserFrame cmd(from, to);
        ASSERT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        ASSERT_STREQ(to.c_str(), cmd.GetTo().c_str());

        cmd.SetFrom(from_new);
        EXPECT_STREQ(from_new.c_str(), cmd.GetFrom().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetTo().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
        EXPECT_STREQ(from_new.c_str(), cmd.GetCmdParameters().copy_user_frame().from().c_str());
        EXPECT_STREQ(to.c_str(), cmd.GetCmdParameters().copy_user_frame().to().c_str());
    }
}

TEST(App_Command_CopyUserFrame, SetTo)
{
    {
        const std::string from = "Foo";
        const std::string to = "Bar";

        const std::string to_new = "Baz";

        App::RobotProgram::Command::CopyUserFrame cmd(from, to);
        ASSERT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        ASSERT_STREQ(to.c_str(), cmd.GetTo().c_str());

        cmd.SetTo(to_new);
        EXPECT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        EXPECT_STREQ(to_new.c_str(), cmd.GetTo().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
        EXPECT_STREQ(from.c_str(), cmd.GetCmdParameters().copy_user_frame().from().c_str());
        EXPECT_STREQ(to_new.c_str(), cmd.GetCmdParameters().copy_user_frame().to().c_str());
    }

    {
        const std::string from = "Foo";
        const std::string to = "Bar";

        const std::string to_new = "";

        App::RobotProgram::Command::CopyUserFrame cmd(from, to);
        ASSERT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        ASSERT_STREQ(to.c_str(), cmd.GetTo().c_str());

        cmd.SetTo(to_new);
        EXPECT_STREQ(from.c_str(), cmd.GetFrom().c_str());
        EXPECT_STREQ(to_new.c_str(), cmd.GetTo().c_str());
        ASSERT_TRUE(cmd.GetCmdParameters().has_copy_user_frame());
        EXPECT_STREQ(from.c_str(), cmd.GetCmdParameters().copy_user_frame().from().c_str());
        EXPECT_STREQ(to_new.c_str(), cmd.GetCmdParameters().copy_user_frame().to().c_str());
    }
}
