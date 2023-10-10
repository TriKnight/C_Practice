#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

// This program demonstrates the basic usage of Sophus
int main(int argc, char **argv){
    //Rotation matrix with 90 degrees along Z axis
    Matrix3d R = AngleAxisd(M_PI/2, Vector3d(0,0,1)).toRotationMatrix();
    //or Quaternion 
    Quaterniond q(R);
    Sophus::SO3d SO3_R(R);  //Sophus::SO3d can be constructed from rotation matrix
    Sophus::SO3d SO3_q(q);  //or quaternion
    // they are equivalent of course
    cout << "SO(3) from matrix:\n" << SO3_R.matrix() << endl;
    cout << "SO(3) from quaternion:\n" << SO3_q.matrix() << endl;
    cout << "they are equal" << endl;

    //Use logaritmic map to get the Lie Algebre
    Vector3d so3 = SO3_R.log();
    cout <<"SO3 =" << so3.transpose() <<endl;
    // Skew-symmetric matrix
    cout <<"so3 hat = \n" << Sophus::SO3d::hat(so3) <<endl;
    //inversely from matrix to vector
    cout<< "so3 hat vee = " << Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose() <<endl;
    
    // Update by pertuurbation model
    Vector3d update_so3(1e-4, 0 ,0); // this is small update
    Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3)*SO3_R;
    cout << "SO3 updated = \n" << SO3_updated.matrix() << endl;
    return 0;
}