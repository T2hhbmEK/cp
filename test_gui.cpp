#include <rturtle.h>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	initWorld(800, 600);
	setSpeed(INT_MAX);
	setImmediate(true);
	hide();

	pu();
	setHeading(0);
	for (int i = 1; i <= 4; i++) {
		setPenSize(10 * i);
		auto p = getXY();
		cout << p.x << " " << p.y << endl;
		drawPoint(p.x, p.y);
		fd(100);
		rt(90);
	}

	waitClose();
	closeWorld();
	return 0;
}
