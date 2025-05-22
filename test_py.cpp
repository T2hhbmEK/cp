#include<rturtle.h>
#include<iostream>
using namespace std;
int main() {
    initWorld(800, 600);
    setSpeed(5000);
    setOrigin(-150, 50);

    setHeading(0); // 开始朝右

    // 画个楼梯 5 层
//    i = 1 右
//        i = 2 左
//            i = 3 右
    beginFill();
    for (int i = 1; i <= 12; i++) {
        forward(100); // 往右走
        if (i % 3 == 0) {
            rightTurn(90);
        } else if (i % 3 == 1) {
            leftTurn(90);
        } else {
            rightTurn(90);
        }
    }
    endFill(RED);


    waitClose();
    closeWorld();
    return 0;
}
