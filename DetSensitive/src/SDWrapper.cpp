#include "DDG4/Factories.h"
#include "DD4hep/LCDD.h"

#include "DetSensitive/SimpleTrackerSD.h"
#include "DetSensitive/AggregateCalorimeterSD.h"

namespace DD4hep {
namespace Simulation {

// All G4VSensitiveDetector are deleted by ~G4SDManager called by ~G4RunManagerKernel
// Factory method to create an instance of SimpleTrackerSD
static G4VSensitiveDetector* create_simple_tracker_sd(
    const std::string& aDetectorName,
    DD4hep::Geometry::LCDD& aLcdd)  {
  std::string readoutName = aLcdd.sensitiveDetector(aDetectorName).readout().name();
  return new det::SimpleTrackerSD(aDetectorName,
    readoutName,
    aLcdd.sensitiveDetector(aDetectorName).readout().segmentation());
}
// Factory method to create an instance of AggregateCalorimeterSD
static G4VSensitiveDetector* create_aggregate_calorimeter_sd(
    const std::string& aDetectorName,
    DD4hep::Geometry::LCDD& aLcdd)  {
  std::string readoutName = aLcdd.sensitiveDetector(aDetectorName).readout().name();
  return new det::AggregateCalorimeterSD(aDetectorName,
    readoutName,
    aLcdd.sensitiveDetector(aDetectorName).readout().segmentation());
}
}
}
DECLARE_EXTERNAL_GEANT4SENSITIVEDETECTOR(SimpleTrackerSD,DD4hep::Simulation::create_simple_tracker_sd)
DECLARE_EXTERNAL_GEANT4SENSITIVEDETECTOR(AggregateCalorimeterSD,DD4hep::Simulation::create_aggregate_calorimater_sd)
