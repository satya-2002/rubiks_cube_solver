//
// Created by Pavilion on 2023-08-18.
//

/*
 * cube[FACE][ROW][COLUMN] gives color of the corresponding face, row, and column
 *  * * *  6 x 3 x 3 = 54
 */

#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
private:
    void rotateFace(int ind) {
        // Perform the 90-degree clockwise rotation in-place for a 3x3 face
        char temp = cube[ind][0][0];
        cube[ind][0][0] = cube[ind][2][0];
        cube[ind][2][0] = cube[ind][2][2];
        cube[ind][2][2] = cube[ind][0][2];
        cube[ind][0][2] = temp;

        temp = cube[ind][0][1];
        cube[ind][0][1] = cube[ind][1][0];
        cube[ind][1][0] = cube[ind][2][1];
        cube[ind][2][1] = cube[ind][1][2];
        cube[ind][1][2] = temp;

//        char rotatedFace[3][3] = {};
//
//        // Perform the 90-degree clockwise rotation
//        for (int row = 0; row < 3; row++) {
//            for (int col = 0; col < 3; col++) {
//                rotatedFace[col][2 - row] = cube[ind][row][col]; // for anti-clockwise replace (col, 2 - row) with (2 - col, row)
//            }
//        }
//
//        // Copy the rotated values back to the original face
//        for (int row = 0; row < 3; row++) {
//            for (int col = 0; col < 3; col++) {
//                cube[ind][row][col] = rotatedFace[row][col];
//            }
//        }

    }

public:
    char cube[6][3][3]{};

    RubiksCube3dArray () {
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    cube[face][row][col] = getColorLetter(COLOR(face));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

};