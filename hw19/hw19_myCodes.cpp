
for (int i = -1; i < maximum_iter; i++) // maximum_iter是卡尔曼滤波的最大迭代次数
{
    dyn_share.valid = true;
    // 计算雅克比，也就是点面残差的导数 H(代码里是h_x)
    h_share_model(dyn_share, feats_down_body, ikdtree, Nearest_Points, extrinsic_est);

    if (!dyn_share.valid)    {
        continue;
    }

    // //~ TODO:  HW19 calculate J_k for for updating.
    ROS_INFO_STREAM("---------------");
    Eigen::Matrix<double, 24, 24> J = Eigen::Matrix<double, 24, 24>::Identity();
    
    Eigen::Matrix3d m3d = x_.rot.matrix().transpose()*x_propagated.rot.matrix();
    Sophus::SO3 diff(m3d);
    Eigen::Vector3d u = diff.log();
    Eigen::Vector3d u2(u(0), u(1), u(2));
    Eigen::Matrix3d skew_u, skew_u2;
    skew_u << SKEW_SYM_MATRX(u);
    double m = u.norm();
    if(m>0.000001f){            // AVOID  Nan issue
        double alpha = m/2*(cos(m/2)/sin(m/2));
        Eigen::Matrix3d Au_1 = Eigen::Matrix3d::Identity() - 1/2*skew_u + (1-alpha)*skew_u2/(u2.norm());
        J.block<3,3>(3,3) = Au_1;
        P_ = J.inverse() * P_ * (J.inverse().transpose());
        // ROS_INFO_STREAM("New J:     " << J);
        // ROS_INFO_STREAM("New P_ is: " << P_);
    }
    else{
        ROS_INFO("Too small u, skip.");
    }

    ...

    //~ TODO: hw19, also change dx_
    // Matrix<double, 24, 1> dx_ = K * dyn_share.h + (KH - Matrix<double, 24, 24>::Identity()) * dx_new; //公式(18)
    Matrix<double, 24, 1> dx_ = K * dyn_share.h + (KH - Matrix<double, 24, 24>::Identity()) * J.inverse() * dx_new; //公式(18)
    //~ TODO: hw19
