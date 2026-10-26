#pragma once

#include <robotcontrolapp.grpc.pb.h>

#include <string>

namespace App
{
namespace DataTypes
{

/**
 * @brief This class defines a user frame
 */
class UserFrame
{
public:
    // Name of the user frame
    std::string Name;

    // User frame origin position X
    double PointAX = 0;
    // User frame origin position Y
    double PointAY = 0;
    // User frame origin position Z
    double PointAZ = 0;

    // User frame "left" direction X
    double PointBX = 0;
    // User frame "left" direction Y
    double PointBY = 0;
    // User frame "left" direction Z
    double PointBZ = 0;

    // User frame "up" direction X
    double PointCX = 0;
    // User frame "up" direction Y
    double PointCY = 0;
    // User frame "up" direction Z
    double PointCZ = 0;

    /**
     * @brief Default constructor
     */
    UserFrame() = default;

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
    UserFrame(const std::string& name, double pointAX, double pointAY, double pointAZ, double pointBX, double pointBY, double pointBZ, double pointCX,
              double pointCY, double pointCZ);

    /**
     * @brief Constructor from GRPC
     * @param grpc GRPC user frame
     */
    UserFrame(const robotcontrolapp::UserFrame& grpc);

    /**
     * @brief Converts the data to a GRPC object
     * @return GRPC user frame
     */
    robotcontrolapp::UserFrame ToGrpc() const;
};

} // namespace DataTypes
} // namespace App
