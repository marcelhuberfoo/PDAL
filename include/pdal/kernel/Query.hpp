
#ifndef PDAL_APP_ACTION_QUERY_HPP
#define PDAL_APP_ACTION_QUERY_HPP

#include <pdal/Stage.hpp>
#include <pdal/StageIterator.hpp>
#include <pdal/FileUtils.hpp>
#include <pdal/PointBuffer.hpp>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Support.hpp"
#include "Application.hpp"

#include <cstdarg>
#include <map>
#include <vector>


using namespace pdal;

class PDAL_DLL Point
{
public:
    double x;
    double y;
    double z;
    boost::uint64_t id;
    
    bool equal(Point const& other)
    {
        return (Utils::compare_distance(x, other.x) && 
                Utils::compare_distance(y, other.y) && 
                Utils::compare_distance(z, other.z));
        
    }
    bool operator==(Point const& other)
    {
        return equal(other);
    }
    bool operator!=(Point const& other)
    {
        return !equal(other);
    }    
};

class Query : public Application
{
public:
    Query(int argc, char* argv[]);
    int execute(); // overrride
    
    
private:
    void addSwitches(); // overrride
    void validateSwitches(); // overrride
    
    void readPoints(    StageSequentialIterator* iter,
                        PointBuffer& data);    
    std::string m_sourceFile;
    std::string m_candidateFile;
    std::string m_wkt;

    std::ostream* m_outputStream;
    std::string m_outputFileName;
	
    bool m_3d;
};

#endif