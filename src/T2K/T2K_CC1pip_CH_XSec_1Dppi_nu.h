#ifndef T2K_CC1PIP_CH_XSEC_1DPPI_NU_H_SEEN
#define T2K_CC1PIP_CH_XSEC_1DPPI_NU_H_SEEN 

#include "Measurement1D.h"

class T2K_CC1pip_CH_XSec_1Dppi_nu : public Measurement1D {
public:
  T2K_CC1pip_CH_XSec_1Dppi_nu(nuiskey samplekey);
  virtual ~T2K_CC1pip_CH_XSec_1Dppi_nu() {};

  void FillEventVariables(FitEvent *event);
  bool isSignal(FitEvent *event);
};

#endif
