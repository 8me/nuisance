// Copyright 2016 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

/*******************************************************************************
*    This file is part of NUISANCE.
*
*    NUISANCE is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    NUISANCE is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

// This class corresponds to Fig 10a from PRD78 112004 (2008)

#ifndef SCIBOONE_CCCOH_1TRK_1DQ2_NU_H_SEEN
#define SCIBOONE_CCCOH_1TRK_1DQ2_NU_H_SEEN

#include "Measurement1D.h"
#include "SciBooNEUtils.h"

//******************************************************************** 
class SciBooNE_CCCOH_1TRK_1DQ2_nu : public Measurement1D {
//******************************************************************** 

public:

  SciBooNE_CCCOH_1TRK_1DQ2_nu(std::string name, std::string inputfile, FitWeight *rw, std::string type, std::string fakeDataFile);
  virtual ~SciBooNE_CCCOH_1TRK_1DQ2_nu() {};
  
  void FillEventVariables(FitEvent *event);
  bool isSignal(FitEvent *event);

  // For dealing with the efficiency
  void GetTH2DFromFile(std::string fileName, std::string histName);
  double CalcEfficiency(FitParticle *nu, FitParticle *HMT);
  
  TH1D* fMCHist_PDG[61]; ///<! Plots in CCQELike mode to tag PDG of the background

 private:
  double q2qe; ///<! X_Variable
  FitParticle *HM_track;
  TH2D *muonStopEff;
};
  
#endif
