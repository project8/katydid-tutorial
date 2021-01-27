/*
 * KTProcessorTemplate.hh
 *
 *  Created on: Oct 13, 2016
 *      Author: E.V. Zayas
 */

#ifndef KTPROCESSORTEMPLATE_HH_
#define KTPROCESSORTEMPLATE_HH_

#include "KTProcessor.hh"
#include "KTData.hh"

#include "KTSlot.hh"

namespace Scarab
{
    class param_node;
}

namespace Katydid
{
    
    KTLOGGER(avlog_hh, "KTProcessorTemplate.hh");

    class KTDummyDataClass1;
    class KTDummyDataClass2;
    class KTDummyDataClass3;

    /*
     @class KTProcessorTemplate
     @author E.V. Zayas

     @brief An example processor to show the structure of these classes

     @details
     This is a "template" processor which has member variables, signals, and slots which act on fictional data objects. Its purpose
     is to show the general structure of a processor class, and to be used as a starting point when creating a new processor.

     Let's say this processor adds data type KTNewDummyDataClass.

     Configuration name: "processor-template"

     Available configuration values:
     - "member-variable-1": double -- An example member variable
     - "member-variable-2": double -- An example member variable
     - "member-variable-3": double -- An example member variable

     Slots:
     - "dummy-slot-1": void (Nymph::KTDataPtr) -- Does something with dummy data object #1; Requires KTDummyDataClass1; Adds KTNewDummyDataClass
     - "dummy-slot-2": void (Nymph::KTDataPtr) -- Does something with dummy data object #2; Requires KTDummyDataClass2; Adds KTNewDummyDataClass
     - "dummy-slot-3": void (Nymph::KTDataPtr) -- Does something with dummy data object #3; Requires KTDummyDataClass3; Adds KTNewDummyDataClass

     Signals:
     - "dummy-signal-1": void (Nymph::KTDataPtr) -- Emitted upon successful processing of dummy data object #1; Guarantees KTNewDummyDataClass
     - "dummy-signal-2": void (Nymph::KTDataPtr) -- Emitted upon successful processing of dummy data object #2; Guarantees KTNewDummyDataClass
     - "dummy-signal-3": void (Nymph::KTDataPtr) -- Emitted upon successful processing of dummy data object #3; Guarantees KTNewDummyDataClass
    */

    class KTProcessorTemplate : public Nymph::KTProcessor
    {
        public:
            KTProcessorTemplate(const std::string& name = "processor-template");
            virtual ~KTProcessorTemplate();

            bool Configure(const scarab::param_node* node);

            MEMBERVARIABLE(unsigned, MemberVariable1)
            MEMBERVARIABLE(double, MemberVariable2)
            MEMBERVARIABLE(std::string, MemberVariable3)

        public:
            bool AnalyzeDummyClass1( KTDummyDataClass1& someData );
            bool AnalyzeDummyClass2( KTDummyDataClass2& someData );
            bool AnalyzeDummyClass3( KTDummyDataClass3& someData );

            // Other functions, e.g. to analyze components, would go here

            //***************
            // Signals
            //***************

        private:
            Nymph::KTSignalData fDummySignal1;
            Nymph::KTSignalData fDummySignal2;
            Nymph::KTSignalData fDummySignal3;

            //***************
            // Slots
            //***************

        private:
            // If you would like to build this template as-is, you must comment out the following slot initializations because they use made-up data types
            Nymph::KTSlotDataOneType< KTDummyDataClass1 > fSlotOne;
            Nymph::KTSlotDataOneType< KTDummyDataClass2 > fSlotTwo;
            Nymph::KTSlotDataOneType< KTDummyDataClass3 > fSlotThree;
    };

}

#endif /* KTPROCESSORTEMPLATE_HH_ */
