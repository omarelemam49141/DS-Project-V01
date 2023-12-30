#include"CMUgraphicsLib/colors.h"

bool operator==(color a, color b) {

	return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

	return !(a == b);

}