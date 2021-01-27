/*
 * KTProcessorTemplate.cc
 *
 *  Created on: Oct 13, 2016
 *      Author: ezayas
 */

#include "KTProcessorTemplate.hh"

// If you want to build this, you must comment out these include lines, since they don't really exist
#include "KTDummyDataClass1.hh"
#include "KTDummyDataClass1.hh"
#include "KTDummyDataClass1.hh"
#include "KTNewDummyDataClass.hh"

#include "KTLogger.hh"

#include "param_node.hh"


namespace Katydid
{
    KTLOGGER(ptlog, "KTProcessorTemplate");

    // Register the processor
    KT_REGISTER_PROCESSOR(KTProcessorTemplate, "processor-template");

    KTProcessorTemplate::KTProcessorTemplate(const std::string& name) :
            KTProcessor(name),
            fMemberVariable1(0),
            fMemberVariable2(0.),
            fMemberVariable3(""),
            fDummySignal1("dummy-signal-1", this),
            fDummySignal2("dummy-signal-2", this),
            fDummySignal3("dummy-signal-3", this),

            // If you would like to build this template as-is, you must comment out the following slot initializations because they use made-up data types
            fSlotOne("dummy-slot-1", this, &KTProcessorTemplate::AnalyzeDummyObject1, &fDummySignal1),
            fSlotTwo("dummy-slot-2", this, &KTProcessorTemplate::AnalyzeDummyObject2, &fDummySignal2),
            fSlotThree("dummy-slot-3", this, &KTProcessedTemplate::AnalyzeDummyObject3, &fDummySignal3)
    {
    }

    KTProcessorTemplate::~KTProcessorTemplate()
    {
    }

    bool KTProcessorTemplate::Configure(const scarab::param_node* node)
    {
        if (node == NULL) return false;

        SetMemberVariable1(node->get_value< unsigned >("member-variable-1", fMemberVariable1));
        SetMemberVariable2(node->get_value< double >("member-variable-2", fMemberVariable2));
        SetMemberVariable3(node->get_value< std::string >("member-variable-3", fMemberVariable3));
        
        return true;
    }

    bool KTProcessorTemplate::AnalyzeDummyClass1( KTDummyDataClass1& someData )
    {
        KTNewDummyDataClass& newData = someData.Of< KTNewDummyDataClass >()

        // The meat of the processor action on KTDummyDataClass1 goes here

        return true;
    }

    bool KTProcessorTemplate::AnalyzeDummyClass2( KTDummyDataClass2& someData )
    {
        KTNewDummyDataClass& newData = someData.Of< KTNewDummyDataClass >()

        // The meat of the processor action on KTDummyDataClass2 goes here

        return true;
    }

    bool KTProcessorTemplate::AnalyzeDummyClass3( KTDummyDataClass3& someData )
    {
        KTNewDummyDataClass& newData = someData.Of< KTNewDummyDataClass >()

        // The meat of the processor action on KTDummyDataClass3 goes here

        return true;
    }

} // namespace Katydid
