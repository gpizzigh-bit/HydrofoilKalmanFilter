// Simple Kalman Filter Algorithm Class

#include <Eigen/DENSE>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class SimpleFilter
{
public:
	SimpleFilter();
	MatrixXd getFmatrix();
	VectorXd getStateVector();
	VectorXd predict();
	VectorXd update();

private:
	MatrixXd F { 
		{ 0.0,0.0 }, 
		{ 0.0,0.0 } 
	};
	VectorXd state_v { {0.0,0.0} };
	MatrixXd G {
		{ 0.0,0.0 },
		{ 0.0,0.0 }
	};
	MatrixXd H{ // Measurment Matrix
		{0.0,0.0},
		{0.0,0.0}
	};
	VectorXd z { {0.0,0.0} }; // Estimated State
	VectorXd v { {0.0,0.0} }; // Measurment Noise
	VectorXd w { {0.0,0.0} }; // Model Noise
	void DefineFilterMatrixes();
	MatrixXd setFmatrix();
	MatrixXd setGmatrix();
	MatrixXd setHmatrix();
	VectorXd setStateVector();
	VectorXd set_z_StateVector();
	VectorXd setSystemNoiseVector();
	VectorXd setModelNoiseVector();

};


