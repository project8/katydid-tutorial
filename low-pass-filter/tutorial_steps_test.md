# Low-Pass Filter Tutorial

## Requirements

1. git
1. docker
1. Text editor
1. Terminal (x2), both in a clean directory

## Steps

1. Clone Katydid: `git clone --recursive git@github.com:project8/katydid`
1. Clone the tutorial: `git clone git@github.com:project8/katydid-tutorial`
1. Copy the processor template to the right location in Katydid:
  ```
  cp katydid-tutorial/templates/KTProcessorTemplate.hh katydid/Source/SpectrumAnalysis/KTLowPassFilter.hh
  cp katydid-tutorial/templates/KTProcessorTemplate.cc katydid/Source/SpectrumAnalysis/KTLowPassFilter.cc
  ```
1. Copy the data template to the right location in Katydid:
  ```
  cp katydid-tutorial/templates/KTDataTemplate.hh katydid/Source/Data/SpectrumAnalysis/KTLowPassFilteredData.hh
  cp katydid-tutorial/templates/KTDataTemplate.cc katydid/Source/Data/SpectrumAnalysis/KTLowPassFilteredData.cc
  ```
1. Add the processor files to the appropriate CMakeLists.txt file: `katydid/Source/SpectrumAnalysis/CMakeLists.txt`
1. Add the data files to the appropriate CMakeLists.txt file: `katydid/Source/Data/SpectrumAnalysis/CMakeLists.txt`
