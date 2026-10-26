#include <DataTypes/UserFrame.h>
#include <gtest/gtest.h>
#include <robotcontrolapp.grpc.pb.h>

TEST(App_UserFrame, ConstructorDefault)
{
    App::DataTypes::UserFrame frame;
    EXPECT_STREQ("", frame.Name.c_str());
    EXPECT_EQ(0, frame.PointAX);
    EXPECT_EQ(0, frame.PointAY);
    EXPECT_EQ(0, frame.PointAZ);
    EXPECT_EQ(0, frame.PointBX);
    EXPECT_EQ(0, frame.PointBY);
    EXPECT_EQ(0, frame.PointBZ);
    EXPECT_EQ(0, frame.PointCX);
    EXPECT_EQ(0, frame.PointCY);
    EXPECT_EQ(0, frame.PointCZ);
}

TEST(App_UserFrame, Constructor)
{
    {
        const std::string name = "Foo";
        const float ax = 1, bx = 2, cx = 3;
        const float ay = 4, by = 5, cy = 6;
        const float az = 7, bz = 8, cz = 9;

        App::DataTypes::UserFrame frame(name, ax, ay, az, bx, by, bz, cx, cy, cz);

        EXPECT_STREQ(name.c_str(), frame.Name.c_str());
        EXPECT_EQ(ax, frame.PointAX);
        EXPECT_EQ(ay, frame.PointAY);
        EXPECT_EQ(az, frame.PointAZ);
        EXPECT_EQ(bx, frame.PointBX);
        EXPECT_EQ(by, frame.PointBY);
        EXPECT_EQ(bz, frame.PointBZ);
        EXPECT_EQ(cx, frame.PointCX);
        EXPECT_EQ(cy, frame.PointCY);
        EXPECT_EQ(cz, frame.PointCZ);
    }

    {
        const std::string name = "";
        const float ax = -1, bx = -2, cx = -3;
        const float ay = -4, by = -5, cy = -6;
        const float az = -7, bz = -8, cz = -9;

        App::DataTypes::UserFrame frame(name, ax, ay, az, bx, by, bz, cx, cy, cz);

        EXPECT_STREQ(name.c_str(), frame.Name.c_str());
        EXPECT_EQ(ax, frame.PointAX);
        EXPECT_EQ(ay, frame.PointAY);
        EXPECT_EQ(az, frame.PointAZ);
        EXPECT_EQ(bx, frame.PointBX);
        EXPECT_EQ(by, frame.PointBY);
        EXPECT_EQ(bz, frame.PointBZ);
        EXPECT_EQ(cx, frame.PointCX);
        EXPECT_EQ(cy, frame.PointCY);
        EXPECT_EQ(cz, frame.PointCZ);
    }
}

TEST(App_UserFrame, ConstructorGRPC)
{
    {
        const std::string name = "Foo";
        const float ax = 1, bx = 2, cx = 3;
        const float ay = 4, by = 5, cy = 6;
        const float az = 7, bz = 8, cz = 9;

        robotcontrolapp::UserFrame grpc;
        grpc.set_name(name);
        grpc.mutable_point_a()->set_x(ax);
        grpc.mutable_point_a()->set_y(ay);
        grpc.mutable_point_a()->set_z(az);
        grpc.mutable_point_b()->set_x(bx);
        grpc.mutable_point_b()->set_y(by);
        grpc.mutable_point_b()->set_z(bz);
        grpc.mutable_point_c()->set_x(cx);
        grpc.mutable_point_c()->set_y(cy);
        grpc.mutable_point_c()->set_z(cz);

        App::DataTypes::UserFrame frame(grpc);

        EXPECT_STREQ(name.c_str(), frame.Name.c_str());
        EXPECT_EQ(ax, frame.PointAX);
        EXPECT_EQ(ay, frame.PointAY);
        EXPECT_EQ(az, frame.PointAZ);
        EXPECT_EQ(bx, frame.PointBX);
        EXPECT_EQ(by, frame.PointBY);
        EXPECT_EQ(bz, frame.PointBZ);
        EXPECT_EQ(cx, frame.PointCX);
        EXPECT_EQ(cy, frame.PointCY);
        EXPECT_EQ(cz, frame.PointCZ);
    }

    {
        const std::string name = "";
        const float ax = -1, bx = -2, cx = -3;
        const float ay = -4, by = -5, cy = -6;
        const float az = -7, bz = -8, cz = -9;

        robotcontrolapp::UserFrame grpc;
        grpc.set_name(name);
        grpc.mutable_point_a()->set_x(ax);
        grpc.mutable_point_a()->set_y(ay);
        grpc.mutable_point_a()->set_z(az);
        grpc.mutable_point_b()->set_x(bx);
        grpc.mutable_point_b()->set_y(by);
        grpc.mutable_point_b()->set_z(bz);
        grpc.mutable_point_c()->set_x(cx);
        grpc.mutable_point_c()->set_y(cy);
        grpc.mutable_point_c()->set_z(cz);

        App::DataTypes::UserFrame frame(grpc);

        EXPECT_STREQ(name.c_str(), frame.Name.c_str());
        EXPECT_EQ(ax, frame.PointAX);
        EXPECT_EQ(ay, frame.PointAY);
        EXPECT_EQ(az, frame.PointAZ);
        EXPECT_EQ(bx, frame.PointBX);
        EXPECT_EQ(by, frame.PointBY);
        EXPECT_EQ(bz, frame.PointBZ);
        EXPECT_EQ(cx, frame.PointCX);
        EXPECT_EQ(cy, frame.PointCY);
        EXPECT_EQ(cz, frame.PointCZ);
    }
}

TEST(App_UserFrame, ToGRPC)
{
    const std::string name = "Foo";
    const float ax = 1, bx = 2, cx = 3;
    const float ay = 4, by = 5, cy = 6;
    const float az = 7, bz = 8, cz = 9;

    App::DataTypes::UserFrame frame(name, ax, ay, az, bx, by, bz, cx, cy, cz);
    robotcontrolapp::UserFrame grpc = frame.ToGrpc();

    EXPECT_STREQ(name.c_str(), grpc.name().c_str());
    EXPECT_EQ(ax, grpc.point_a().x());
    EXPECT_EQ(ay, grpc.point_a().y());
    EXPECT_EQ(az, grpc.point_a().z());
    EXPECT_EQ(bx, grpc.point_b().x());
    EXPECT_EQ(by, grpc.point_b().y());
    EXPECT_EQ(bz, grpc.point_b().z());
    EXPECT_EQ(cx, grpc.point_c().x());
    EXPECT_EQ(cy, grpc.point_c().y());
    EXPECT_EQ(cz, grpc.point_c().z());
}
