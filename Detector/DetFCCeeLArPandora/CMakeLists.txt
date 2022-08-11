###############################################################################
# Package: DetFCCeeLArPandora
################################################################################

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/compact DESTINATION ${CMAKE_INSTALL_DATADIR}/${CMAKE_PROJECT_NAME}/Detector/DetFCCeeLArPandora)

add_test(NAME ConstructDetFFCCeeLArPandora
         COMMAND root -q -b ".github/scripts/load_detector.C(\"Detector/DetFCCeeLArPandora/compact/FCCee_DectMaster.xml\")"
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
         )
k4_set_test_env(ConstructDetFFCCeeLArPandora)


