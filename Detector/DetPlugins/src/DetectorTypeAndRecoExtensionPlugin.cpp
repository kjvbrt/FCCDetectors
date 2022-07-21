#include <DD4hep/DetElement.h>
#include <DD4hep/Detector.h>
#include <DD4hep/Factories.h>
#include <DD4hep/Printout.h>
#include <Parsers/Parsers.h>

#include <DD4hep/IDDescriptor.h>

#include <DDRec/DetectorData.h>
#include <DDRec/SurfaceHelper.h>
#include <DDRec/SurfaceManager.h>

#include <string>

using dd4hep::DetElement;
using dd4hep::PrintLevel;

namespace {

  /** Plugin for adding detector type flags and reconstruction extensions to DetElements
   *
   */

  static long addRecoExtensions(dd4hep::Detector& description, int argc, char** argv) {
    const std::string LOG_SOURCE("AddRecoExtensions");
    printout(PrintLevel::INFO, LOG_SOURCE, "Running plugin");

    std::string subDetectorName = argv[0];
    std::string type_flags = argv[1];

    printout(PrintLevel::INFO, LOG_SOURCE, "Running plugin for %s to add %s",
             subDetectorName.c_str(),
             type_flags.c_str());

    try {

      auto detector = description.detector(subDetectorName);

      if(!detector.isValid()){
        printout(PrintLevel::ERROR, LOG_SOURCE, "Detector not found");
        return 1;
      }

      unsigned int typeFlag = dd4hep::_toInt(type_flags);
      printout(PrintLevel::INFO, LOG_SOURCE,"+++ setDetectorTypeFlags for detector :%s set to 0x%x",
               subDetectorName.c_str(),
               typeFlag);

      detector.setTypeFlag(typeFlag);

      auto caloData = new dd4hep::rec::LayeredCalorimeterData;
      caloData->layoutType = dd4hep::rec::LayeredCalorimeterData::BarrelLayout;
      // caloData->inner_symmetry = nsides;
      // caloData->outer_symmetry = nsides;

      detector.addExtension<dd4hep::rec::LayeredCalorimeterData>(caloData);

    } catch ( std::exception &e) {
      printout(PrintLevel::ERROR, LOG_SOURCE, "Detector not found exception");
      printout(PrintLevel::ERROR, LOG_SOURCE, e.what());
    }

    return 1;
  }

}  // namespace

DECLARE_APPLY(fccdet_addRecoExtensions, ::addRecoExtensions)
