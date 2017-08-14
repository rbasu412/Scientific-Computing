// Rukmini Basu
// Rb2ep
// HW 11
// Problem 1
// rb2ep_neutron.cpp
// g++ -O -Wall rb2ep_neutron.cpp -o test_neutron $P2660FLAGS
//On my honor I have neither given or received help on this assignment.
//When the thickness is around 8m, 99% are blocked.

/*
This program is a Monte Carlo analysis of neutron shielding. Suppose a source of radiation produces neutrons that you need to block 
with a shielding wall.
Ideally, the shielding wall should block all of the neutrons coming from the “radiation area”, and prevent them from getting into 
the “safe area”. Let's see if we can design a wall that will do the job.
Assumptions; all neutrons hit the wall with the same kinetic energy (1 MeV)
	All neutrons enter wall at random angle phi between 88 and 92 degrees (90 degrees is perpindicular to surface of the wall)

Once inside the wall, then neutron bounces around, colliding with nuclei. During each collision, it loses some energy. If it loses 
enough energy, it will stop inside the wall, and no longer be a threat. It may, however, make it all the way through the wall, or 
even bounce around and come back out through the same side of the wall it entered on.

Consider a wall made of Lead (with A = 207.2 and \lambda = 10 cm).

Write a program called username_neutron.cpp to simulate the scattering of the neutrons within the shield wall. Generate many 
neutrons for your simulation. Consider a neutron to be effectively stopped (thermalized) for our purposes when its kinetic energy 
reaches thermal energies, at or below 0.025 eV. (Note the change of units from MeV). Follow the neutron as it bounces around inside 
the wall. You may stop simulating a particular neutron when it thermalizes or leaves the wall by punching through or backscattering 
out. Assume the neutron is confined to the x-y plane, and assume the wall extends to infinity up and down along the y-axis.


Plots created (pdf format)
backscatter: the remaining energy of neutrons backscattering from a 5 meter thick wall. (Beyond a certain thickness, the thickness 
will no longer have any significant effect on this distribution.)
punchthru: The remaining energy of neutrons that punch through a 5 meter thick wall.
thermal: The total distance traveled by all thermalized neutrons

*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "hist.hpp"
#include "random.hpp"

double MeV_to_eV(double MeV);
double deg_to_rad(double angle);

double energy_loss(double A, double theta, double incident);

int main(){

  double lambda, A, KE_inc, T, KE_new;
  int i;
  double thermalized_E;
  double dist;
  int backscat, punchthru, therm;
  double phi, theta;
  int NUM_OF_NEUTRONS = 10000;
  double dist_therm[NUM_OF_NEUTRONS], back_energy[NUM_OF_NEUTRONS], thru_e[NUM_OF_NEUTRONS];
  double temp_dist;

  h1 back, thru, therm_dist;

  h1init(&back,500,0.025, 1.0,"backscatter");
  h1init(&thru,50,0.0, 0.015,"punch thru");
  h1init(&therm_dist,10,40.5, 490.5,"thermalized dist");
  
  backscat = 0;
  punchthru = 0;
  therm = 0;

  thermalized_E = 0.025; //eV

  lambda = 10; //cm
  A = 207.2;
  KE_inc = 1; //MeV
  T = 500; //cm



  //for each neutron
  for(i = 0; i <NUM_OF_NEUTRONS; i++){
    KE_new = MeV_to_eV(KE_inc);//incident KE
    phi = randu(88,92);
    phi = deg_to_rad(phi);

//neutron will travel a random distance, according to the probability density function of 1/lambda*exp(-d/lambda)   
    dist = ranExp(lambda)*cos(phi);
    temp_dist = dist;

    //for each collision
    while(temp_dist >= 0 && temp_dist <= T && KE_new >= thermalized_E){
      theta = randu(1, 360);
      theta = deg_to_rad(theta);
      KE_new = energy_loss(A, lambda, KE_new);
      dist = cos(theta)*ranExp(lambda);
      temp_dist += dist;
    }
    if(temp_dist > T){
      thru_e[punchthru] = KE_new/1000000;
      h1fill(&thru,thru_e[punchthru],1);
      punchthru++;
      
    }
    else if(temp_dist < 0){
      back_energy[backscat] = KE_new/1000000;
      h1fill(&back,back_energy[backscat],1);
      backscat++;
      
    }
    else{
      dist_therm[therm] = temp_dist;
      h1fill(&therm_dist,dist_therm[therm],1);
      therm++;
    }

  }

  //printf("%d\n%d\n%d\n", punchthru, backscat, therm);

//   h1info(&thru);
//   h1info(&back);
//   h1info(&therm_dist);

  h1labels(&thru,"Energy (MeV)", "Number of Events");
  h1labels(&back,"Energy (MeV)", "Number of Events");
  h1labels(&therm_dist,"Distance (cm)", "Number of Events");


  h1plot(&thru, "");
  h1plot(&back, "");
  h1plot(&therm_dist, "");

  h1plot(&thru, "rb2ep_E_punchthru.pdf");
  h1plot(&back, "rb2ep_E_backscatter.pdf");
  h1plot(&therm_dist, "rb2ep_dist_thermal.pdf");

  return 0;
}

double MeV_to_eV(double MeV){
  double eV;
  eV = MeV*1000000;
  return eV;
}

double deg_to_rad(double angle){

  angle = 0.01745329252*angle;
  return angle;

}



double energy_loss(double A, double theta, double incident){
  double outgoing = incident*(A*A+2*A*cos(theta)+1)/((1+A)*(1+A));
  double newKE = outgoing;
  return newKE;
}
