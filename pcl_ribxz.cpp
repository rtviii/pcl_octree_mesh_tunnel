#include <pcl/io/pcd_io.h>
#include <pcl/octree/octree.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/octree/octree.h>
#include <pcl/surface/marching_cubes_hoppe.h>
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>


// template class pcl::MarchingCubesHoppe<pcl::PointXYZ>;

int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile<pcl::PointXYZ>("7ssw.pcd", *cloud) == -1) {
        PCL_ERROR("Couldn't read PCD file.\n");
        return (-1);
    }else{
        printf("Opened successfully");
    }

    // // FIXME: Adjust resolution
    // pcl::octree::OctreePointCloudSearch<pcl::PointXYZ> octree(0.01); 
    // octree.setInputCloud(cloud);
    // octree.addPointsFromInputCloud();


    fork();
    pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
    viewer.runOnVisualizationThread ([&cloud] (pcl::visualization::PCLVisualizer& viewer)
    {
        viewer.setBackgroundColor (0, 0, 0);
        viewer.addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
        viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
        viewer.addCoordinateSystem (1.0);
        viewer.initCameraParameters ();
    });
    // viewer.runOnVisualizationThreadOnce ([&cloud] (pcl::visualization::PCLVisualizer& viewer)
    // {
    //     viewer.setBackgroundColor (0, 0, 0);
    //     viewer.addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
    //     viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
    //     viewer.addCoordinateSystem (1.0);
    //     viewer.initCameraParameters ();
    // });
    // viewer.showCloud (cloud);
    // while (!viewer.wasStopped ())
    // {

    // }
    // pcl::PolygonMesh mesh;
    // pcl::MarchingCubesHoppe<pcl::PointXYZ> mc;
    // mc.setInputCloud(cloud);
    // mc.setGridResolution(400,400,400);  // Adjust grid resolution as needed
    // mc.reconstruct(mesh);
}