#include "queen_attack.h"



attack_status_t can_attack(position_t queen_1, position_t queen_2) {
if (!check_queen(queen_1) || !check_queen(queen_2) ) return INVALID_POSITION;

int d_row = (int) queen_2.row - (int) queen_1.row;
int d_col = (int) queen_2.column - (int) queen_1.column;

if ((d_row == 0) && (d_col == 0) ) return INVALID_POSITION;
if ((d_row == 0) || (d_col == 0) ) return CAN_ATTACK;
if (d_row * d_row == d_col * d_col) return CAN_ATTACK;
return CAN_NOT_ATTACK;


}

bool check_queen (position_t queen) {
    if ((queen.column > 7) || ((queen.row > 7))) return false;
    return true;
}