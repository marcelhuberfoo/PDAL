
#ifndef PDAL_APP_ACTION_PIPELINE_HPP
#define PDAL_APP_ACTION_PIPELINE_HPP



#include <pdal/PipelineReader.hpp>
#include <pdal/PipelineManager.hpp>
#include <pdal/PipelineWriter.hpp>
#include <pdal/FileUtils.hpp>
#include <pdal/PointBuffer.hpp>
#include <pdal/StageIterator.hpp>

#include <boost/scoped_ptr.hpp>
#include "AppSupport.hpp"

#include "Application.hpp"

#include <iostream>

using namespace pdal;
namespace po = boost::program_options;


class PDAL_DLL Pipeline : public Application
{
public:
    Pipeline(int argc, char* argv[]);
    int execute();

private:
    void addSwitches();
    void validateSwitches();
    pdal::PointBuffer* dummyWrite(pdal::PipelineManager& manager);
    
    std::string m_inputFile;
    std::string m_pipelineFile;
    bool m_validate;
    boost::uint64_t m_numPointsToWrite;
    boost::uint64_t m_numSkipPoints;
};

#endif