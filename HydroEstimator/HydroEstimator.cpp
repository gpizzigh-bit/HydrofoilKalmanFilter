/************** Wave Simulator v0.1 **************/
//  Created by : Gabriel Pizzighini Salvador    //
//  Contact info : gabrielpizzighini@gmail.com  //


#include "HydroEstimator.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
//#include <unistd.h>


constexpr auto PI = 3.14159265;
#define FILE_DATA_NAME "data.dat"
// [TODO] create an if define for layout data creation 

float wave,
height = 3.00,
real_dist,
choice,
scale = 0.1,
upbound = 4.00,
lowbound = 4.00,
measured_dist;


int offset = 1,
epoch = 0,
epoch_lim = 3;

//function definition 
void create_log(std::fstream& file, float wave, float real_dist, float measured_dist);
void close_log(std::fstream& file);

// main func
int main() {

    std::fstream DataFile; // creates file 
    DataFile.open(FILE_DATA_NAME, std::ios::out);

    while (epoch <= epoch_lim) {

        float obj_height = height;

        //Create the sinisoid wave 
        for (int Angle = -360; Angle < 360; Angle++) {
            wave = sin(Angle * PI / 180) + offset;

            //Object of interest located at height 3
            real_dist = height - wave;

            //Adding random walk error to measurement (Simulates the GPS errors)
            //Keeping the walk only on height axis for now
            choice = rand() % 2; // equal probability of going up(50%) or down(50%)

            if (choice == 0) {
                if (obj_height == height + upbound * scale) {
                    //step down limited to upbound
                    obj_height = obj_height - upbound * scale;
                }
                else {
                    // go up
                    obj_height = obj_height + upbound * scale;
                }
            }
            else if (choice == 1) {
                if (obj_height == height - lowbound * scale) {
                    //step up limited to lowbound
                    obj_height = obj_height + lowbound * scale;
                }
                else {
                    // go down
                    obj_height = obj_height - lowbound * scale;
                }

            }

            //Measure height with random walk noise
            measured_dist = obj_height - wave;

            //std::cout << " Wave at " << wave << " | Distance(Real) :  " << real_dist << "| Distance(Measured) : " << measured_dist << "\n";
            create_log(DataFile, wave, real_dist, measured_dist);

            //unsigned int microsecond = 1000000;
            //usleep(1*microsecond);
        }
        epoch++;
    }
    close_log(DataFile);

}

void create_log(std::fstream& File, float wave, float real_dist, float measured_dist) {
    if (!File) {
        std::cout << "[ERROR] : File not created!";
    }
    else {
        //File << " Wave at " << wave << " | Distance(Real) :  " << real_dist << " | Distance(Measured) : " << measured_dist << "\n"; //inputs data
        File << wave << " " << real_dist << " " << measured_dist << "\n"; // For a simpler file generation 
    }
}

void close_log(std::fstream& File) {
    File.close();
    std::cout << "Log generated!" << "\n";
}