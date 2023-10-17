#include <iostream>
using namespace std; 

#include <Eigen/Core>
#include <Eigen/Dense>
#include <vector>

int main( int argc, char** argv )
{
    double dt = 0.5;
    // 状态量x
    Eigen::Vector2d x = Eigen::Vector2d::Zero();

    Eigen::Matrix2d A = //写入A矩阵

    double u[3] = {3, 2, 1};    //输入：加速度
    vector<Eigen::Vector2d> z(3);    // 观测
    z[0] = Eigen::Vector2d (0.37, 1.4);
    z[1] = Eigen::Vector2d (1.38, 2.6);
    z[2] = Eigen::Vector2d (2.77, 3.2);

    Eigen::Vector2d B =  // 写入B矩阵

    Eigen::Matrix2d C = // 写入C矩阵

    Eigen::Matrix2d R = //写入R矩阵
    Eigen::Matrix2d Q = // 写入Q矩阵

    Eigen::Matrix2d P = Eigen::Matrix2d::Identity();

    for (int i = 0; i < 3; i++)
    {
        // 写出预测过程
        Eigen::Vector2d x_predicted = 
        Eigen::Matrix2d P_predicted =

        // 写出更新过程
        Eigen::Matrix2d K = 
        Eigen::Vector2d x_updated =
        Eigen::Matrix2d P_updated = 

        x = x_updated;
        P = P_updated;

        std::cout << "state x: " << x.transpose() << endl;
        std::cout << "covariance P: " << P << endl;
    }
    
    return 0;
}