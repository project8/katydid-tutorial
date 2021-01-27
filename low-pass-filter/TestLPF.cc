/*
 * TestLPF.cc
 *
 *  Created on: Jan 26, 2021
 *      Author: N.S. Oblath
 *
 *  Tests performance of KTLowPassFilter
 *
 *  Usage: > TestLPF
 */

#include "KTLowPassFilter.hh"

#include "KTFrequencySpectrumDataFFTW.hh"
#include "KTFrequencySpectrumDataPolar.hh"
#include "KTPowerSpectrumData.hh"

#include "KTLowPassFilteredData.hh"

#include "KTLogger.hh"

using namespace std;
using namespace Katydid;

KTLOGGER(testlog, "TestLPF");

int main()
{
    // Create and setup processor
    KTLowPassFilter tProc;

    tProc->SetRC(3.1831e-9); // corresponds to f_c = 50 MHz


    // Parameters for filling data
    unsigned nBins = 100;
    double minFreq = 0.;
    double maxFreq = 100.;

    // Test processing of KTFrequencySpectrumDataFFTW

    KTFrequencySpectrumDataFFTW tFSFFTW;

    // TODO: Fill tFSFFTW

    tProc.Filter(tDDC1);

    // Check Results
    KTLowPassFilteredFSDataFFTW& tLPFFSFFTW = tFSFFTW.Of< KTLowPassFilteredFSDataFFTW >();

    // TODO: Verify that the contents of tLPFFSFFTW are as expected


    // Test processing of KTFrequencySpectrumDataPolar

    KTFrequencySpectrumDataPolar tFSPolar;

    // TODO: Fill tFSPolar

    tProc.Filter(tFSPolar);

    // Check Results
    KTLowPassFilteredFSDataPolar& tLPFFSPolar = tFSPolar.Of< KTLowPassFilteredFSDataPolar >();

    // TODO: Verify that the contents of tLPFFSPolar are as expected
    

    // Test processing of KTPowerSpectrumData

    KTPowerSpectrumData tPS;

    KTPowerSpectrum* tOnePS = new KTPowerSpectrum(nBins, minFreq, maxFreq);
    for (unsigned iBin = 0; iBin < nBins; ++iBin)
    {
        (*tOnePS)(iBin) = 1.;
    }
    tPS.SetSpectrum(tOnePS);

    tProc.Filter(tPS);

    // Check Results
    KTLowPassFilteredPSData& tLPFPS = tPS.Of< KTLowPassFilteredPSData >();
    KTPowerSpectrum* tOneLPFPS = tLPFPS.GetSpectrum(0);

    // TODO: Verify that the contents of tLPFPS are as expected
    for (unsigned iBin = 0; iBin < nBins; ++iBin)
    {
        KTWARN(testlog, iBin << "  " << (*tOnePS)(iBin) << " --> " << (*tOneLPFPS)(iBin))
    }

    return 0;
}
