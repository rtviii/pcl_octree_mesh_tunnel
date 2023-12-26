import json
import typing
from  Bio.PDB.Structure import Structure
from Bio.PDB import FastMMCIFParser
from Bio import PDB
import open3d as o3d

def open_structure(pdbid, path: str, path_type: typing.Literal["cif", "json", "modified"]) -> Structure | typing.Any:
    if path_type == 'cif':
        cifpath = path
        try:
            return FastMMCIFParser(QUIET=True).get_structure(pdbid, cifpath)
        except Exception as e:
            return f"\033[93m Parser Error in structure {pdbid} \033[0m : {e}"



import argparse
parser = argparse.ArgumentParser(description="Retrieve PDB structure by RCSB ID")
parser.add_argument("rcsb_id", type=str, help="RCSB ID of the PDB structure")
args = parser.parse_args()
rcsb_id = args.rcsb_id   

# Create a PDBParser object
parser = PDB.PDBParser(QUIET=True)

# Specify the path to your PDB file
pdb_file_path = "./tunnels/prok/7SSW/7SSW_edited.pdb"

# Parse the PDB file
structure = parser.get_structure("7ssw", pdb_file_path)


points = []

# Iterate through the structure to extract atom coordinates
for model in structure:
    for chain in model:
        for residue in chain:
            for atom in residue:
                # Get atom coordinates
                x, y, z = atom.get_coord()
                points.append([x, y, z])

# Create an Open3D PointCloud object
pcd = o3d.geometry.PointCloud()
pcd.points = o3d.utility.Vector3dVector(points)

# Create a PCD file
pcd_file_path = "7ssw.pcd"

# Write the PointCloud object to a PCD file with a header
# o3d.io.write_point_cloud(pcd_file_path, pcd, write_ascii=True)
# cloud = o3d.io.read_point_cloud("{}.pcd".format(rcsb_id)) # Read point cloud
o3d.open3d.visualization.draw_plotly([pcd], width=1920, height=960)

print(f"All atom coordinates have been exported to {pcd_file_path}")
