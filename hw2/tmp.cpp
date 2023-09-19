#include <iostream>
using namespace std;

#include <Eigen/Core>
#include "sophus/so3.h"
#include "sophus/se3.h"

int main(int argc, char **argv){
    
    Eigen::Vector3d fai1(0.01, 0.02, -0.03); // 旋转小量
    Eigen::Vector3d fai2(1.1, -1.2, 1.3);

    // --------- 开始你的代码 ---------------//

    Eigen::Matrix3d jl_inv;

    std::cout << "jl_inv:" << jl_inv << std::endl
              << std::endl;

    Eigen::Matrix3d RA;
    std::cout << "sophus:" << RA << std::endl
              << std::endl;

    Eigen::Matrix3d RB;
    std::cout << "bch:" << RB << std::endl
              << std::endl;

    Eigen::Matrix3d RC;
    std::cout << "wrong:" << RC << std::endl
              << std::endl;

    // --------- 结束你的代码 ---------------//
    return 0;
}