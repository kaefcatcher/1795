import xml.etree.ElementTree as ET
import csv

path = "trace1.xml"
tree = ET.parse(path)
root = tree.getroot()

csvfile = open("data.csv",'w')
csvfile_writer = csv.writer(csvfile)

for timestep in root:
    for vehicle in timestep:
        csv_line = [vehicle.attrib["x"], vehicle.attrib["y"], 0]
        csvfile_writer.writerow(csv_line)
csvfile.close()
