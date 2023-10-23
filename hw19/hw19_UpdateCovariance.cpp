// ESKF
		void update_iterated_dyn_share_modified(double R, PointCloudXYZI::Ptr &feats_down_body,
												KD_TREE<PointType> &ikdtree, vector<PointVector> &Nearest_Points, int maximum_iter, bool extrinsic_est)
		{
			//......

			for (int i = -1; i < maximum_iter; i++) // maximum_iter是卡尔曼滤波的最大迭代次数
			{
				dyn_share.valid = true;
				// 计算雅克比，也就是点面残差的导数 H(代码里是h_x)
				h_share_model(dyn_share, feats_down_body, ikdtree, Nearest_Points, extrinsic_est);

				if (!dyn_share.valid)
				{
					continue;
				}

        		Eigen::Matrix<double, 24, 24> J = ;  // TODO 在此处计算矩阵J
        		P_ =  ;  // TODO 每次迭代前更新矩阵P

				//......
			}
		}