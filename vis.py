from open3d import visualization, io
import argparse

def vis(rcsb_id:str):
    cloud = io.read_point_cloud("{}.pcd".format(rcsb_id)) # Read point cloud
    visualization.draw_plotly([cloud], width=1920, height=1080) # Visualize point cloud (plotly

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Retrieve PDB structure by RCSB ID")
    parser.add_argument("rcsb_id", type=str, help="RCSB ID of the PDB structure")
    args = parser.parse_args()
    rcsb_id = args.rcsb_id   
    vis(rcsb_id)