#include <iostream>
using namespace std;

#include <Eigen/Core>
#include <unsupported/Eigen/MatrixFunctions> 
#include "sophus/so3.h"
#include "sophus/se3.h"

int main(int argc, char **argv){
    
    Eigen::Vector3d fai1(0.01, 0.02, -0.03); // 旋转小量
    Eigen::Vector3d fai2(1.1, -1.2, 1.3);

    // --------- 开始你的代码 ---------------//

    using namespace Sophus;
    // calculate exp(fai1)*exp(fai2)
    Eigen::Matrix3d result = (SO3::hat(fai1)).exp() * (SO3::hat(fai2)).exp();
    cout <<"Sophus result: =========== \n " << result << endl << endl;
    Sophus::SO3 res2 = SO3::exp(fai1)*SO3::exp(fai2);
    cout <<"Sophus result2: =========== \n " << res2.matrix() << endl << endl;


    // calculate by BCH

    Eigen::Matrix3d jl_inv;

    double theta = fai2.norm();
    Eigen::Vector3d a = fai2.normalized();
    double theta_half = theta/2;
    double cot_theta_half = 1.0f/tanf(theta_half);

    jl_inv = theta_half*cot_theta_half*Eigen::Matrix3d::Identity(3,3) 
            + (1-theta_half*cot_theta_half)*a*a.transpose() 
            - theta_half*Sophus::SO3::hat(a);
    
    auto b = SO3::hat(jl_inv*fai1 + fai2);
    cout <<"BCH approx: ============= \n " << b.exp() <<  endl;


    // calculate by direct adding
    Eigen::Matrix3d add_res = (Sophus::SO3::hat(fai1+fai2)).exp();
    cout <<"Direct adding:(wrong) ============= \n " << add_res <<  endl;

    // --------- 结束你的代码 ---------------//
    return 0;
}