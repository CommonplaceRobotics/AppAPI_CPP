#include "UserFrame.h"

#include <stdexcept>

namespace App
{
namespace DataTypes
{

/**
 * @brief Constructor
 * @param name user frame name
 * @param pointAX origin position X
 * @param pointAY origin position Y
 * @param pointAZ origin position Z
 * @param pointBX "left" position X
 * @param pointBY "left" position Y
 * @param pointBZ "left" position Z
 * @param pointCX "up" position X
 * @param pointCY "up" position Y
 * @param pointCZ "up" position Z
 */
UserFrame::UserFrame(const std::string& name, double pointAX, double pointAY, double pointAZ, double pointBX, double pointBY, double pointBZ, double pointCX,
                     double pointCY, double pointCZ)
{
    Name = name;
    PointAX = pointAX;
    PointAY = pointAY;
    PointAZ = pointAZ;
    PointBX = pointBX;
    PointBY = pointBY;
    PointBZ = pointBZ;
    PointCX = pointCX;
    PointCY = pointCY;
    PointCZ = pointCZ;
}

/**
 * @brief Constructor from GRPC
 * @param grpc GRPC user frame
 */
UserFrame::UserFrame(const robotcontrolapp::UserFrame& grpc)
{
    Name = grpc.name();

    PointAX = grpc.point_a().x();
    PointAY = grpc.point_a().y();
    PointAZ = grpc.point_a().z();
    PointBX = grpc.point_b().x();
    PointBY = grpc.point_b().y();
    PointBZ = grpc.point_b().z();
    PointCX = grpc.point_c().x();
    PointCY = grpc.point_c().y();
    PointCZ = grpc.point_c().z();
}

/**
 * @brief Converts the data to a GRPC object
 * @return GRPC user frame
 */
robotcontrolapp::UserFrame UserFrame::ToGrpc() const
{
    robotcontrolapp::UserFrame ret;
    ret.set_name(Name);
    ret.mutable_point_a()->set_x(PointAX);
    ret.mutable_point_a()->set_y(PointAY);
    ret.mutable_point_a()->set_z(PointAZ);
    ret.mutable_point_b()->set_x(PointBX);
    ret.mutable_point_b()->set_y(PointBY);
    ret.mutable_point_b()->set_z(PointBZ);
    ret.mutable_point_c()->set_x(PointCX);
    ret.mutable_point_c()->set_y(PointCY);
    ret.mutable_point_c()->set_z(PointCZ);
    return ret;
}

} // namespace DataTypes
} // namespace App
