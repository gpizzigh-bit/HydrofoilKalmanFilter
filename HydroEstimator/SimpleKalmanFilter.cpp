

#include "SimpleKalmanFilter.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

SimpleFilter::SimpleFilter()
{
	// Define the initial values here
	// Construct matrixes
	DefineFilterMatrixes();
}

MatrixXd SimpleFilter::getFmatrix() {
	return F;
}

MatrixXd SimpleFilter::setFmatrix() {
	F(0, 0) = 1.0;
	F(0, 1) = 0.0;
	F(1, 0) = sin(90 * 3.14/180);
	F(1, 1) = 0.0;
	return F;
}

MatrixXd SimpleFilter::setGmatrix()
{
	return MatrixXd();
}

MatrixXd SimpleFilter::setHmatrix()
{
	return MatrixXd();
}

VectorXd SimpleFilter::getStateVector()
{
	return state_v;
}

VectorXd SimpleFilter::setStateVector() {
	double h_k = 0.0,
		   aux = 0.0;
	state_v(0) = h_k;
	state_v(1) = aux;
	return state_v;
}

VectorXd SimpleFilter::set_z_StateVector()
{
	return VectorXd();
}

VectorXd SimpleFilter::setSystemNoiseVector()
{
	return VectorXd();
}

VectorXd SimpleFilter::setModelNoiseVector()
{
	return VectorXd();
}


void SimpleFilter::DefineFilterMatrixes() {
	F = setFmatrix();
	state_v = setStateVector();
}

