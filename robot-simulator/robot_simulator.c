#include "robot_simulator.h"
#include <string.h>
#include <stdio.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{

    robot_status_t robot = (robot_status_t){
        .direction = direction,
        .position = (robot_position_t){
            .x = x,
            .y = y,
        }};
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    for (size_t i = 0; i < strlen(commands); i++)
    {
        robot->direction = next_dir(robot->direction, commands[i]);
        if (commands[i] != 'A')
            continue;

        switch (robot->direction)
        {
        case DIRECTION_EAST:
            robot->position.x += 1;
            break;
        case DIRECTION_WEST:
            robot->position.x -= 1;
            break;
        case DIRECTION_SOUTH:
            robot->position.y -= 1;
            break;
        case DIRECTION_NORTH:
            robot->position.y += 1;
            break;
        case DIRECTION_MAX:
            break;
        }
    }
}
robot_direction_t next_dir(robot_direction_t direction, char move)
{
    robot_direction_t dir;
    switch (move)
    {
    case 'A':
        return direction;
    case 'R':
        switch (direction)
        {
        case DIRECTION_NORTH:
            dir = DIRECTION_EAST;
            break;
        case DIRECTION_EAST:
            dir = DIRECTION_SOUTH;
            break;
        case DIRECTION_SOUTH:
            dir = DIRECTION_WEST;
            break;
        case DIRECTION_WEST:
            dir = DIRECTION_NORTH;
            break;
        default:
            dir = DIRECTION_MAX;
            break;
        }
        break;
    case 'L':
        switch (direction)
        {
        case DIRECTION_NORTH:
            dir = DIRECTION_WEST;
            break;
        case DIRECTION_WEST:
            dir = DIRECTION_SOUTH;
            break;
        case DIRECTION_SOUTH:
            dir = DIRECTION_EAST;
            break;
        case DIRECTION_EAST:
            dir = DIRECTION_NORTH;
            break;
        default:
            dir = DIRECTION_MAX;
            break;
        }
        break;
    }
    return dir;
}