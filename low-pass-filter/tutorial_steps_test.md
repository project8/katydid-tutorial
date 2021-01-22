# Low-Pass Filter Tutorial

## Requirements

1. git
1. docker
1. Text editor
1. Terminal (x2), both in a clean directory

## Steps

1. Clone Katydid: 
  ```
  git clone --recursive git@github.com:project8/katydid
  ```
1. Clone the tutorial:
  ```
  git clone git@github.com:project8/katydid-tutorial
  ```
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
1. Add the processor files to the appropriate CMakeLists.txt file (.hh and .cc): `katydid/Source/SpectrumAnalysis/CMakeLists.txt`
1. Add the data files to the appropriate CMakeLists.txt file (.hh and .cc): `katydid/Source/Data/CMakeLists.txt`
1. Start the container with the Katydid source mounted as a volume:
  ```
  docker run -it -v /path/to/katydid:/katydid -v /path/to/katydid-tutorial:/tutorial project8/p8compute:latest /bin/bash
  ```
  *Note:* specify the path to the Katydid source directory on your own system.
1. Perform the Katydid build
  ```
  cd /katydid
  mkdir build
  cd build
  cmake ..
  make install
  ```
1. Run Katydid with LPFConfig.yaml
  ```
  cd /tutorial/low-pass-filter
  /katydid/build/bin/Katydid -c LPFConfig.yaml -e /tutorial/rid000002839_0.egg --brw-file rid2839_lpf.root
  ```