
  //遍历每个IMU帧
  for (auto it_kp = IMUpose.end() - 1; it_kp != IMUpose.begin(); it_kp--)
  {
    auto head = it_kp - 1;
    auto tail = it_kp;
    R_imu<<MAT_FROM_ARRAY(head->rot);   //拿到前一帧的IMU旋转矩阵
    // cout<<"head imu acc: "<<acc_imu.transpose()<<endl;
    vel_imu<<VEC_FROM_ARRAY(head->vel);     //拿到前一帧的IMU速度
    pos_imu<<VEC_FROM_ARRAY(head->pos);     //拿到前一帧的IMU位置
    acc_imu<<VEC_FROM_ARRAY(tail->acc);     //拿到后一帧的IMU加速度
    angvel_avr<<VEC_FROM_ARRAY(tail->gyr);  //拿到后一帧的IMU角速度

    

    //~ TODO: homework 13, change to next IMU's position (and previous IMU's speed)
    R_imu<<MAT_FROM_ARRAY(tail->rot);
    vel_imu<<VEC_FROM_ARRAY(tail->vel); 
    pos_imu<<VEC_FROM_ARRAY(tail->pos);

    acc_imu<<VEC_FROM_ARRAY(head->acc);  
    angvel_avr<<VEC_FROM_ARRAY(head->gyr); 
    //~ TODO: end.

