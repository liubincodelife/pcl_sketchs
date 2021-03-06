#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

using namespace std;

int main(int argc,char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    if(pcl::io::loadPCDFile<pcl::PointXYZ>("test_pcd.pcd",*cloud)==-1)//load the pcd file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd\n");
        return(-1);
    }
    cout<<"Loaded "
        <<cloud->width*cloud->height
        <<" data points from test_pcd.pcd with the following fields: "<<endl;
    for(size_t i=0;i<cloud->points.size();++i)
        cout<<"    "<<cloud->points[i].x
            <<" "<<cloud->points[i].y
            <<" "<<cloud->points[i].z<<endl;

    return(0);
}