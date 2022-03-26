#include <iostream>
#include <vector>
#include <complex>

class ImpedanceDevice{
public:

  virtual std::complex<double> get_impedance(double omega) const = 0;

  // there is no formula for a "generic impedance" as it depends on the device
  // so this is a pure virtual member function

  // classes inheriting from ImpedanceDevice will override this function

  // the function will compute and return
  // a complex number representing the impedance
  // depending on the formula for the specific device
  // and the value of omega in input

  // to represent a complex number for the impedance
  // we use std::complex from the standard library
  // with the real and imaginary part of type double

  virtual ~ImpedanceDevice() { }
};

class Resistor : public ImpedanceDevice{
public:

  Resistor(double r) : resistance(r) { }

  // the impedance of a resistor is equal to the resistance
  // and this doesn't depend on the frequency, however we
  // still need to keep the omega parameter in order
  // to override the function from the base class ImpedanceDevice

  std::complex<double> get_impedance(double omega) const {

    std::complex<double> impedance(resistance);

    // constructor for std::double with only one parameter
    // setting the real part of impedance
    // to the value of resistance
    // and its imaginary part to 0

    return impedance;
  }

private:
  double resistance ;
};


class Capacitor : public ImpedanceDevice{
public:
  Capacitor(double c) : capacitance(c) { }

  std::complex<double>get_impedance(double omega) const {

    std::complex<double> impedance(0, - 1/(omega * capacitance));

    // we pass in input to the constructor for std::complex
    // the values from the formula for the impedance of a capacitor
    // real part: 0 (passed to the first parameter of the constructor)
    // imaginary part: - 1/(omega * capacitance) (passed to the second parameter of the constructor)

    return impedance;
  }

private :

  double capacitance;

};

class Inductor : public ImpedanceDevice{
public:
  Inductor(double i) : inductance(i) { }

  std::complex<double>get_impedance(double omega) const {

    std::complex<double> impedance(0, omega * inductance);

    return impedance;
  }

private :

  double inductance;

};


int main(){
  std::vector<ImpedanceDevice*> devices;

  ImpedanceDevice* tmp_id;
  std::string dev_choice;
  double dev_feature;
  int n_devices;

  std::cout << "please enter number of devices:" << std::endl;
  std::cin >> n_devices ;

  for(int i = 0; i < n_devices ; i++){

    std::cout << "please enter device " << i + 1 << " choice (r/i/c):" << std::endl;
    std::cin >> dev_choice;

    if(dev_choice=="c"){
      std::cout << "please enter capacitance (F):" << std::endl;
      std::cin >> dev_feature;
      tmp_id = new Capacitor(dev_feature);
    }
    else if (dev_choice == "i"){
      std::cout << "please enter Inductance (H):" << std::endl;
      std::cin >> dev_feature;
      tmp_id = new Inductor(dev_feature);
    }
    else{
      std::cout << "please enter resistance (Ohm):" << std::endl;
      std::cin >> dev_feature;
      tmp_id = new Resistor(dev_feature);
    }

    devices.push_back(tmp_id);

  }

  double f, omega;
  std::cout << "please enter frequency (Hz):" << std::endl;
  std::cin >> f;
  omega = 2 * 3.14 * f;
  // 3.14 sufficient precision for now
  // (the M_PI constant often found in the cmath header
  // is not standard so it doesn't always work)

  for(int i=0; i < devices.size(); i++){
    std::cout << "impedance of device " << i + 1 << ": " << std::endl;

    std::cout << devices[i]->get_impedance(omega) << " Ohms" << std::endl;

  }

  for(int i = 0; i < devices.size(); i++) {
    delete devices[i];
  }
}