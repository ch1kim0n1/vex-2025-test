#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "pros/abstract_motor.hpp"
#include <array>
#include <cstdint>
#include "lemlib/api.hpp"

namespace constants
{
    // using namespace pros;
    inline constexpr bool USE_TANK = false;

    namespace drivebase
    {
        // front, middle, back, top
        inline constexpr std::array<int8_t, 4> LEFT_PORTS = {
            0,
            0,
            0,
            0
        };

        // front, middle, back, top
        inline constexpr std::array<int8_t, 4> RIGHT_PORTS = {
            0,
            0,
            0,
            0
        };

        inline constexpr double DRIVETRAIN_WIDTH = 11.292; //this is CAD based and will require tuning
        inline constexpr int8_t IMU_PORT = 0;

        inline constexpr auto CHASSIS_INTERNAL_GEARSET = pros::v5::MotorGears::blue;



        // lateral PID controller
        inline const lemlib::ControllerSettings lateral_controller(
            0, // proportional gain (kP)
            0, // integral gain (kI)
            0, // derivative gain (kD)
            3, // anti windup
            1, // small error range, in inches
            100, // small error range timeout, in milliseconds
            3, // large error range, in inches
            500, // large error range timeout, in milliseconds
            20 // maximum acceleration (slew)
        );

        // angular PID controller
        inline const lemlib::ControllerSettings angular_controller(
            0, // proportional gain (kP)
            0, // integral gain (kI)
            0, // derivative gain (kD)
            0, //3, // anti windup
            0, //1, // small error range, in degrees
            0, //100, // small error range timeout, in milliseconds
            0, //3, // large error range, in degrees
            0, //500, // large error range timeout, in milliseconds
            0 // maximum acceleration (slew)
        );
    }

    namespace intake
    {
        // left, right
        inline constexpr std::array<int8_t, 2> PORTS = {
            0,
            0
        };

        // uses basic motors, which doesn't requre gearset to be configured in code
    }

    inline constexpr double TELEOP_POLL_TIME = 10.0; // ms

}
#endif