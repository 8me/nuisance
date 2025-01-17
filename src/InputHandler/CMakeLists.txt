# Copyright 2016-2021 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

################################################################################
#    This file is part of NUISANCE.
#
#    NUISANCE is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    NUISANCE is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
################################################################################

set(InputHandler_Impl_Files
  BaseFitEvt.cxx
  FitParticle.cxx
  FitEvent.cxx
  GeneratorUtils.cxx
  StdHepEvt.cxx
  InputUtils.cxx
  GIBUUInputHandler.cxx
  GiBUUNativeInputHandler.cxx
  NUANCEInputHandler.cxx
  InputHandler.cxx
  NuanceEvent.cxx
  FitEventInputHandler.cxx
  SplineInputHandler.cxx
  HepMCTextInputHandler.cxx
  InputFactory.cxx
  SigmaQ0HistogramInputHandler.cxx
  HistogramInputHandler.cxx
)

set(InputHandler_Hdr_Files
  BaseFitEvt.h
  FitParticle.h
  FitEvent.h
  GeneratorUtils.h
  StdHepEvt.h
  InputUtils.h
  GIBUUInputHandler.h
  GiBUUNativeInputHandler.h
  NUANCEInputHandler.h
  InputHandler.h
  InputTypes.h
  GeneratorInfoBase.h
  NuanceEvent.h
  FitEventInputHandler.h
  SplineInputHandler.h
  HepMCTextInputHandler.h
  InputFactory.h
  SigmaQ0HistogramInputHandler.h
  HistogramInputHandler.h
)

if(HEPMCNuEvt_ENABLED)
  LIST(APPEND InputHandler_Impl_Files HepMCNuEvtInputHandler.cxx)
endif()

if(GENIE_ENABLED)
  LIST(APPEND InputHandler_Impl_Files GENIEInputHandler.cxx)
endif()

if(NEUT_ENABLED)
  LIST(APPEND InputHandler_Impl_Files NEUTInputHandler.cxx)
endif()

if(NuWro_ENABLED)
  LIST(APPEND InputHandler_Impl_Files NuWroInputHandler.cxx)
endif()

add_library(InputHandler SHARED ${InputHandler_Impl_Files})
target_link_libraries(InputHandler GeneratorCompileDependencies Experiments CoreIncludes ROOT::ROOT)
set_target_properties(InputHandler PROPERTIES PUBLIC_HEADER "${InputHandler_Hdr_Files}")

install(TARGETS InputHandler
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include)

