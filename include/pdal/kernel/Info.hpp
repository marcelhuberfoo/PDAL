#ifndef PDAL_APP_ACTION_INFO_HPP
#define PDAL_APP_ACTION_INFO_HPP

#include <pdal/Stage.hpp>
#include <pdal/StageIterator.hpp>
#include <pdal/FileUtils.hpp>
#include <pdal/PointBuffer.hpp>
#include <pdal/filters/Stats.hpp>
#include <pdal/XMLSchema.hpp>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/tokenizer.hpp>

#include "Support.hpp"
#include "Application.hpp"

#define SEPARATORS ",| "
typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

using namespace pdal;


class PDAL_DLL Info : public Application
{
public:
    Info(int argc, char* argv[]);
    int execute(); // overrride

private:
    void addSwitches(); // overrride
    void validateSwitches(); // overrride

    void dumpOnePoint(const Stage&) const;
    void dumpStats(pdal::filters::Stats& filter) const;
    void dumpSchema(const Stage&) const;
    void dumpStage(const Stage&) const;
    void dumpQuery(Stage const&, IndexedPointBuffer&) const;
    void dumpMetadata(const Stage&) const;
    void dumpSDO_PCMetadata(Stage const&) const;

    std::string m_inputFile;
    bool m_showStats;
    bool m_showSchema;
    bool m_showStage;
    bool m_showMetadata;
    bool m_showSDOPCMetadata;
    pdal::Options m_options;
    boost::uint64_t m_pointNumber;
    std::ostream* m_outputStream;
    boost::uint32_t m_seed;
    boost::uint32_t m_sample_size;
    bool m_useXML;
    std::string m_Dimensions;
    std::string m_QueryPoint;
    double m_QueryDistance;
    boost::uint64_t m_numPointsToWrite;
};

#endif