#pragma once

/**
 * @file parameters.h
 * @brief System configuration parameters and thresholds
 * 
 * This file contains all the configurable parameters for the system including
 * temperature thresholds, timing constants, and hardware positions.
 */

/* Temperature Monitoring System Parameters */

/**
 * @brief First temperature threshold for pre-alarm state
 * @details Temperature in degrees Celsius that triggers monitoring for pre-alarm
 */
#define TEMP1 15

/**
 * @brief Time duration for TEMP1 threshold in pre-alarm detection
 * @details Time in milliseconds that temperature must remain above TEMP1 to trigger pre-alarm
 */
#define T1 10000

/**
 * @brief Second temperature threshold for alarm state
 * @details Temperature in degrees Celsius that triggers alarm conditions
 */
#define TEMP2 20

/**
 * @brief Time duration for TEMP2 threshold in alarm detection
 * @details Time in milliseconds that temperature must remain above TEMP2 to trigger alarm
 */
#define T2 10000

/* Distance Monitoring Parameters */

/**
 * @brief First distance threshold for object detection
 * @details Distance in centimeters that triggers first level detection
 */
#define D1 10

/**
 * @brief Time duration for D1 distance threshold
 * @details Time in milliseconds for sustained detection at D1 distance
 */
#define T3 10000

/**
 * @brief Second distance threshold for closer object detection
 * @details Distance in centimeters that triggers second level detection
 */
#define D2 5

/**
 * @brief Time duration for D2 distance threshold
 * @details Time in milliseconds for sustained detection at D2 distance
 */
#define T4 10000

/* General Timing Parameters */

/**
 * @brief General timing constant for periodic tasks
 * @details Time in milliseconds used for various periodic operations
 */
#define T5 1000

/* Gate Control Parameters */

/**
 * @brief Time required for gate to fully close
 * @details Time in milliseconds for gate to move from open to closed position
 */
#define CLOSE_TIME 2000

/**
 * @brief Time required for gate to fully open
 * @details Time in milliseconds for gate to move from closed to open position
 */
#define OPEN_TIME 2000

/* Gate Position Parameters */

/**
 * @brief Gate position when fully open
 * @details Angle in degrees for the open gate position
 */
#define OPEN_POS 93

/**
 * @brief Gate position when fully closed
 * @details Angle in degrees for the closed gate position
 */
#define CLOSE_POS 0
